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
#include "libalx/base/stdlib/alloc/mallocarrays.h"
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
int	alx_ur_init	(struct Alx_UR **restrict ur, int usleep_time,
			 const char *restrict ur_ip,
			 const char *restrict ur_port)
{
	int	status;
	int	sfd;

	if (usleep_time < 0)
		return	EINVAL;
	status	= usleep(usleep_time);
	if (status)
		return	status;

	sfd	= alx_tcp_client_open(ur_ip, ur_port);
	if (sfd < 0)
		return	sfd;

	if (alx_mallocarrays(ur, 1))
		goto err;

	(*ur)->sfd	= sfd;
	(*ur)->usleep	= usleep_time;

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

	status1	= alx_ur_cmd(ur, "halt()");
	status2	= close(ur->sfd);

	if (status2)
		return	status2;
	ur->sfd	= -1;
	return	status1;
}

int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 const char *restrict cmd)
{
	ssize_t	n;
	ssize_t	len;

	usleep(ur->usleep);

	len	= strlen(cmd);
	n	= write(ur->sfd, cmd, len);
	if (n != len)
		goto err;

	len	= strlen("\n");
	n	= write(ur->sfd, "\n", len);
	if (n != len)
		goto err;

	return	0;
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
