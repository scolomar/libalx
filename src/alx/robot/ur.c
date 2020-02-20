/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur.h"

#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
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
int	ur_sprintf_pose_rel	(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const char *restrict pose);
__attribute__((nonnull(2, 3), warn_unused_result))
static
int	ur_sprintf_func		(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const char *restrict func,
				 const char *restrict arg);
__attribute__((nonnull, warn_unused_result))
static
int	ur_sprintf_msg		(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const char *restrict msg);
__attribute__((nonnull, warn_unused_result))
static
int	ur_sprintf_Dout_set	(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 ptrdiff_t idx, bool state);


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
			 FILE *restrict log)
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

	if (log)
		fprintf(log, "%s\n", cmd);
	return	usleep(usleep_after);
err:
	if (log) {
		fprintf(log, "%s\n", cmd);
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
			 FILE *restrict log)
{
	char	m[BUFSIZ];
	char	cmd[BUFSIZ];

	if (ur_sprintf_msg(ARRAY_SIZE(m), m, msg))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(cmd), cmd, "textmsg", m))
		return	-1;
	return	alx_ur_cmd(ur, cmd, usleep_after, log);
}

int	alx_ur_movej	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict log)
{
	char	pos[BUFSIZ];
	char	cmd[BUFSIZ];

	if (ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(cmd), cmd, "movej", pos))
		return	-1;
	return	alx_ur_cmd(ur, cmd, usleep_after, log);
}

int	alx_ur_movej_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict log)
{
	char	buf1[BUFSIZ]; /* used as `pos` and later as `cmd` */
	char	buf2[BUFSIZ]; /* used as `pos_rel` */

	if (ur_sprintf_pose(ARRAY_SIZE(buf1), buf1, pose))
		return	-1;
	if (ur_sprintf_pose_rel(ARRAY_SIZE(buf2), buf2, buf1))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(buf1), buf1, "movej", buf2))
		return	-1;
	return	alx_ur_cmd(ur, buf1, usleep_after, log);
}

int	alx_ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict log)
{
	char	pos[BUFSIZ];
	char	cmd[BUFSIZ];

	if (ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(cmd), cmd, "movel", pos))
		return	-1;
	return	alx_ur_cmd(ur, cmd, usleep_after, log);
}

int	alx_ur_movel_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict log)
{
	char	buf1[BUFSIZ]; /* used as `pos` and later as `cmd` */
	char	buf2[BUFSIZ]; /* used as `pos_rel` */

	if (ur_sprintf_pose(ARRAY_SIZE(buf1), buf1, pose))
		return	-1;
	if (ur_sprintf_pose_rel(ARRAY_SIZE(buf2), buf2, buf1))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(buf1), buf1, "movel", buf2))
		return	-1;
	return	alx_ur_cmd(ur, buf1, usleep_after, log);
}

int	alx_ur_Dout_set	(const struct Alx_UR *restrict ur,
			 ptrdiff_t idx, bool state, int usleep_after,
			 FILE *restrict log)
{
	char	cmd[BUFSIZ];

	if (ur_sprintf_Dout_set(ARRAY_SIZE(cmd), cmd, idx, state))
		return	-1;
	return	alx_ur_cmd(ur, cmd, usleep_after, log);
}

int	alx_ur_halt	(const struct Alx_UR *restrict ur,
			 int usleep_after,
			 FILE *restrict log)
{
	return	alx_ur_cmd(ur, "halt", usleep_after, log);
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
int	ur_sprintf_pose_rel	(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const char *restrict pose)
{

	if (alx_strlcpys(str, "pose_add(", nmemb, NULL))
		return	-1;
	switch (pose[0]) {
	case 'p':	/* xyz */
		if (alx_strscat(nmemb, str, "get_actual_tcp_pose(), ") < 0)
			return	-1;
		break;
	case '[':	/* joints */
		if (alx_strscat(nmemb, str, "get_actual_joint_positions(), ") < 0)
			return	-1;
		break;
	default:
		return	-1;
	}
	if (alx_strscat(nmemb, str, pose) < 0)
		return	-1;
	if (alx_strscat(nmemb, str, ")") < 0)
		return	-1;
	return	0;
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

static
int	ur_sprintf_msg		(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const char *restrict msg)
{

	if (alx_strlcpys(str, "\"", nmemb, NULL))
		return	-1;
	if (alx_strscat(nmemb, str, msg) < 0)
		return	-1;
	if (alx_strscat(nmemb, str, "\"") < 0)
		return	-1;
	return	0;
}

static
int	ur_sprintf_Dout_set	(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 ptrdiff_t idx, bool state)
{

	if (alx_snprintfs(str, NULL, nmemb, "%ti, ", idx))
		return	-1;
	if (state) {
		if (alx_strscat(nmemb, str, "True") < 0)
			return	-1;
	} else {
		if (alx_strscat(nmemb, str, "False") < 0)
			return	-1;
	}
	return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
