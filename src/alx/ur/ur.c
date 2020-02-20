/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/ur/ur.h"

#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>

#include "libalx/base/socket/tcp/client.h"
#include "libalx/base/stdlib/alloc/callocs.h"
#include "libalx/base/stdlib/alloc/frees.h"


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
			 const char *restrict ur_port)
{
	int	sfd;

	sfd	= alx_tcp_client_open(ur_ip, ur_port);
	if (sfd < 0)
		return	sfd;

	if (alx_callocs(ur, 1))
		goto err;

	(*ur)->sfd	= sfd;

	return	0;
err:
	close(sfd);
	return	ENOMEM;
}

int	alx_ur_deinit	(struct Alx_UR *restrict ur)
{
	int	status1;
	int	status2;

	if (!ur)
		return	ENOANO;

	status1	= alx_ur_cmd(ur, "halt()", 0);
	status2	= close(ur->sfd);

	if (status2)
		return	status2;
	ur->sfd	= -1;
	return	status1;
}

int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 const char *restrict cmd, int usleep_after)
{
	ssize_t	n;
	ssize_t	len;


	len	= strlen(cmd);
	n	= write(ur->sfd, cmd, len);
	if (n != len)
		goto err;

	len	= strlen("\n");
	n	= write(ur->sfd, "\n", len);
	if (n != len)
		goto err;

	return	usleep(usleep_after);
err:
	if (n < 0)
		return	n;
	return	(n % INT_MAX) + 1;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
