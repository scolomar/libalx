/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/socket/tcp/server.h"

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
static
int	get_addrs	(const char *server_port, struct addrinfo **addrs);
static
int	set_server	(int sd, int *optval, struct addrinfo *ad, int backlog);
static
int	set_socket	(struct addrinfo *addrs, int backlog);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_tcp_server_open	(const char *server_port, int backlog)
{
	int		sock;
	struct addrinfo	*addrs;

	if (get_addrs(server_port, &addrs))
		return	-2;
	sock	= set_socket(addrs, backlog);
	freeaddrinfo(addrs);

	return	sock;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	get_addrs	(const char *server_port, struct addrinfo **addrs)
{
	struct protoent	*tcp;
	struct addrinfo	hint = {0};

	tcp	= getprotobyname("tcp");
	if (!tcp)
		return	-1;
	hint.ai_family		= AF_UNSPEC;
	hint.ai_socktype	= SOCK_STREAM;
	hint.ai_protocol	= tcp->p_proto;
	hint.ai_flags		= AI_PASSIVE;
	if (getaddrinfo(NULL, server_port, &hint, addrs))
		return	-1;
	return	0;
}

static
int	set_socket	(struct addrinfo *addrs, int backlog)
{
	int	val;
	int	sock;

	sock	= -1;
	for (struct addrinfo *ad = addrs; ad; ad = ad->ai_next) {
		sock = socket(ad->ai_family, ad->ai_socktype, ad->ai_protocol);
		if (sock < 0)
			continue;
		if (set_server(sock, &val, ad, backlog))
			goto retry;
		break;
	retry:
		close(sock);
		sock	= -1;
	}

	return	sock;
}

static
int	set_server	(int sd, int *optval, struct addrinfo *ad, int backlog)
{

	*optval	= 1;
	if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, optval, sizeof(*optval)))
		return	-1;
	if (bind(sd, ad->ai_addr, ad->ai_addrlen))
		return	-1;
	if (listen(sd, backlog))
		return	-1;
	return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

