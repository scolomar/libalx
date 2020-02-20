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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/socket/tcp/client.h"
#include "libalx/base/stdlib/alloc/callocs.h"
#include "libalx/base/stdlib/alloc/frees.h"
#include "libalx/base/stdio/printf/snprintfs.h"
#include "libalx/base/string/strcpy/strlcpys.h"
#include "libalx/base/string/strcat/strscat.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
__attribute__((nonnull, warn_unused_result))
static
int	ur_sprintf_pose		(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const struct Alx_UR_Pose *restrict pose);
__attribute__((nonnull, warn_unused_result))
static
int	ur_sprintf_func		(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const char *restrict func,
				 const char *restrict arg);


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

	status1	= alx_ur_cmd(ur, "halt()", 0, NULL);
	status2	= close(ur->sfd);

	if (status2)
		return	status2;
	ur->sfd	= -1;
	return	status1;
}

int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 const char *restrict cmd, int usleep_after,
			 FILE *restrict ostream)
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

	if (ostream)
		fprintf(ostream, "%s\n", cmd);
	return	usleep(usleep_after);
err:
	if (ostream) {
		fprintf(ostream, "%s\n", cmd);
		fprintf(stderr, "%s\n", cmd);
	}
	if (n < 0)
		return	n;
	return	(n % INT_MAX) + 1;
}

struct Alx_UR_Pose alx_ur_pose_xyz(float x, float y, float z,
				   float rx, float ry, float rz)
{

	return	(struct Alx_UR_Pose){
		.type	= ALX_UR_POSE_XYZ,
		.x	= x,
		.y	= y,
		.z	= z,
		.rx	= rx,
		.ry	= ry,
		.rz	= rz
	};
}

struct Alx_UR_Pose alx_ur_pose_joints(float base, float shoulder, float elbow,
				      float wrist1, float wrist2, float wrist3)
{

	return	(struct Alx_UR_Pose){
		.type		= ALX_UR_POSE_JOINTS,
		.base		= base,
		.shoulder	= shoulder,
		.elbow		= elbow,
		.wrist1		= wrist1,
		.wrist2		= wrist2,
		.wrist3		= wrist3
	};
}

int	alx_ur_puts	(const struct Alx_UR *restrict ur,
			 const char *restrict msg, int usleep_after,
			 FILE *restrict ostream)
{
	char	buf[BUFSIZ];

	if (ur_sprintf_func(ARRAY_SIZE(buf), buf, "textmsg", msg))
		return	-1;
	return	alx_ur_cmd(ur, buf, usleep_after, ostream);
}

int	alx_ur_movej	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict ostream)
{
	char	pos[BUFSIZ];
	char	buf[BUFSIZ];

	if (ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(buf), buf, "movej", pos))
		return	-1;
	return	alx_ur_cmd(ur, buf, usleep_after, ostream);
}

int	alx_ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict ostream)
{
	char	pos[BUFSIZ];
	char	buf[BUFSIZ];

	if (ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(buf), buf, "movel", pos))
		return	-1;
	return	alx_ur_cmd(ur, buf, usleep_after, ostream);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	ur_sprintf_pose		(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const struct Alx_UR_Pose *restrict pose)
{

	switch (pose->type) {
	case ALX_UR_POSE_XYZ:
		return	alx_snprintfs(str, NULL, nmemb,
				"p[%.4f, %.4f, %.4f, %.4f, %.4f, %.4f]",
					pose->x, pose->y, pose->z,
					pose->rx, pose->ry, pose->rz);
	case ALX_UR_POSE_JOINTS:
		return	alx_snprintfs(str, NULL, nmemb,
				"[%.4f, %.4f, %.4f, %.4f, %.4f, %.4f]",
					pose->x, pose->y, pose->z,
					pose->rx, pose->ry, pose->rz);
	default:
		return	EINVAL;
	}
}

static
int	ur_sprintf_func		(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const char *restrict func,
				 const char *restrict arg)
{

	if (alx_strlcpys(str, func, nmemb, NULL))
		return	-1;
	if (alx_strscat(nmemb, str, "(") < 0)
		return	-1;
	if (alx_strscat(nmemb, str, arg) < 0)
		return	-1;
	if (alx_strscat(nmemb, str, ")") < 0)
		return	-1;
	return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
