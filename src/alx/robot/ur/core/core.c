/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/core/core.h"

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "libalx/alx/robot/ur/move/move.h"
#include "libalx/alx/robot/ur/core/msg.h"
#include "libalx/base/stdlib/alloc/callocs.h"
#include "libalx/base/stdlib/alloc/frees.h"
#include "libalx/base/stdio/printf/sbprintf.h"
#include "libalx/base/string/strcat/strbcatf.h"
#include "libalx/base/sys/socket/tcp/client.h"


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
int	alx_ur_init	(struct Alx_UR **restrict ur,
			 const char *restrict ur_ip,
			 const char *restrict ur_port,
			 int usleep_after)
{
	int	sfd;
	int	enable = 1;

	sfd	= alx_tcp_client_open(ur_ip, ur_port);
	if (sfd < 0)
		return	-1;
	if (setsockopt(sfd, SOL_SOCKET, SO_TIMESTAMPNS, &enable,sizeof(enable)))
		goto err1;

	if (alx_callocs(ur, 1))
		goto err1;
	(*ur)->sfd	= sfd;

	/* First received message is 'version' (in newer UR client versions) */
	if (alx_ur_recv(*ur))
		goto err2;
	/* Seccond received message is 'state' */
	if (alx_ur_recv(*ur))
		goto err2;

	usleep(usleep_after);
	return	0;

err2:	alx_frees(ur);
err1:	close(sfd);
	return	-1;
}

int	alx_ur_deinit	(struct Alx_UR *restrict ur)
{
	int	status;

	if (!ur)
		return	-1;

	status	= alx_ur_halt(ur, 0);
	if (close(ur->sfd))
		return	-1;
	ur->sfd	= -1;
	free(ur);
	return	status;
}

int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 int usleep_after,
			 const char *restrict fmt, ...)
{
	va_list	ap;
	int	status;
	char	buf[BUFSIZ];
	ssize_t	n;
	ssize_t	len;

	va_start(ap, fmt);
	status	= alx_vsbprintf(buf, NULL, fmt, ap);
	va_end(ap);
	if (status)
		return	-1;
	if (alx_strbcatf(buf, NULL, "\n"))
		return	-1;
	len	= strlen(buf);

	n	= send(ur->sfd, buf, len, 0);
	if (n != len)
		goto err;

	printf("%s", buf);
	usleep(usleep_after);
	return	0;
err:
	fprintf(stderr, "%s", buf);
	return	-1;
}

int	alx_ur_poweroff	(const struct Alx_UR *restrict ur,
			 int usleep_after)
{
	return	alx_ur_cmd(ur, usleep_after, "powerdown();");
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
