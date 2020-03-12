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

#include "libalx/base/stdio/printf/sbprintf.h"


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
int	alx_telnet_open_client	(FILE **restrict telnet,
				 const char *restrict server_addr,
				 const char *restrict server_port,
				 const char *restrict rw)
{
	char	cmd[_POSIX_ARG_MAX];

	if (alx_sbprintf(cmd, NULL, "telnet %s %s", server_addr, server_port))
		return	-1;

	*telnet	= popen(cmd, rw);

	return	!*telnet;
}

int	alx_telnet_login	(FILE *restrict telnet,
				 const char *restrict user,
				 const char *restrict passwd,
				 int delay_us)
{

	usleep(delay_us);
	if (alx_telnet_send(telnet, user))
		return	-1;
	usleep(delay_us);
	if (alx_telnet_send(telnet, passwd))
		return	-1;
	usleep(delay_us);

	return	0;
}

int	alx_telnet_send		(FILE *restrict telnet,
				 const char *restrict msg)
{

	if (fprintf(telnet, "%s\n", msg) <= 0)
		return	-1;
	if (fflush(telnet))
		return	-1;

	return	0;
}

int	alx_telnet_sendf	(FILE *restrict telnet,
				 const char *restrict fmt, ...)
{
	va_list	ap;
	int	status;

	va_start(ap, fmt);
	status	= vfprintf(telnet, fmt, ap);
	va_end(ap);

	if (status <= 0)
		return	-1;
	if (fputc('\n', telnet) < 0)
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
