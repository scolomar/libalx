/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/telnet-tcp/client/client.h"

#include <limits.h>
#include <stdio.h>

#include <unistd.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/stdio/printf/sbprintf.h"
#include "libalx/base/string/strcat/strscatfs.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define DELAY_US	(100 * 1000)


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_telnet_open_client	(FILE **restrict telnet,
				 char *restrict server_addr,
				 char *restrict server_port, char *restrict rw,
				 int log, char *fout, char *ferr)
{
	char		cmd[_POSIX_ARG_MAX];
	const char	*redir;

	switch (log) {
	case ALX_TELNET_TCP_LOG_NOT:
		break;
	case ALX_TELNET_TCP_LOG_APPEND:
		redir	= ">>";
		break;
	case ALX_TELNET_TCP_LOG_OVR:
		redir	= ">";
		break;
	default:
		return	-1;
	}

	if (alx_sbprintf(cmd, NULL, "telnet %s %s", server_addr, server_port))
		return	-1;

	if (log) {
		if (fout) {
			if (alx_strscatfs(cmd, NULL, ARRAY_SIZE(cmd), " 1%s %s",
								redir, fout))
				return	-1;
		}
		if (ferr) {
			if (alx_strscatfs(cmd, NULL, ARRAY_SIZE(cmd), " 2%s %s",
								redir, ferr))
				return	-1;
		}
	}

	*telnet	= popen(cmd, rw);

	return	!*telnet;
}

int	alx_telnet_login	(FILE *restrict telnet,
				 char *restrict user, char *restrict passwd)
{

	usleep(DELAY_US);
	if (alx_telnet_send(telnet, user))
		return	-1;
	usleep(DELAY_US);
	if (alx_telnet_send(telnet, passwd))
		return	-1;
	usleep(DELAY_US);

	return	0;
}

int	alx_telnet_send		(FILE *restrict telnet, char *restrict msg)
{
	const char	*eol	= "\r\n\r";

	if (fprintf(telnet, "%s%s", msg, eol) <= 0)
		return	-1;
	if (fflush(telnet))
		return	-1;

	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
