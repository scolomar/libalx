/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/socket/tcp/client.h"

#include <errno.h>
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


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_tcp_client_open	(const char *restrict server_addr,
				 const char *restrict server_port)
{
	struct protoent	*tcp;
	int			sd;
	struct addrinfo	hint = {0};
	struct addrinfo	*addrs;
	int			status;

	tcp	= getprotobyname("tcp");
	if (!tcp)
		return	-EINVAL;
	hint.ai_family		= AF_UNSPEC;
	hint.ai_socktype	= SOCK_STREAM;
	hint.ai_protocol	= tcp->p_proto;
	status	= getaddrinfo(server_addr, server_port, &hint, &addrs);
	if (status)
		return	-labs(status);

	for (struct addrinfo *ad = addrs; ad; ad = ad->ai_next) {
		sd = socket(ad->ai_family, ad->ai_socktype, ad->ai_protocol);
		if (sd < 0)
			break;
		if (!connect(sd, ad->ai_addr, ad->ai_addrlen))
			break;
		close(sd);
		sd	= -1;
	}
	freeaddrinfo(addrs);

	if (sd < 0)
		return	-errno;
	return	sd;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
