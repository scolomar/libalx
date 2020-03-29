/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/ur.h"

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
#include "libalx/base/stdio/printf/sbprintf.h"
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
				 const char *arg[]);
__attribute__((nonnull, warn_unused_result))
static
int	ur_sprintf_msg		(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const char *restrict msg);
__attribute__((nonnull, warn_unused_result))
static
int	ur_sprintf_bool		(ptrdiff_t nmemb,
				 char str[static restrict nmemb], bool state);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_ur_init	(struct Alx_UR **restrict ur,
			 const char *restrict ur_ip,
			 const char *restrict ur_port,
			 int usleep_after)
{
	int	sfd;

	sfd	= alx_tcp_client_open(ur_ip, ur_port);
	if (sfd < 0)
		return	-1;
	if (alx_callocs(ur, 1))
		goto err1;
	(*ur)->sfd	= sfd;

	usleep(usleep_after);
	return	0;

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
	return	status;
}

int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 const char *restrict cmd,
			 int usleep_after)
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

	printf("%s\n", cmd);
	usleep(usleep_after);
	return	0;
err:
	fprintf(stderr, "%s\n", cmd);
	return	-1;
}

int	alx_ur_halt	(const struct Alx_UR *restrict ur,
			 int usleep_after)
{
	return	alx_ur_cmd(ur, "halt", usleep_after);
}

int	alx_ur_poweroff	(const struct Alx_UR *restrict ur,
			 int usleep_after)
{
	return	alx_ur_cmd(ur, "powerdown()", usleep_after);
}

int	alx_ur_movej	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after)
{
	char	pos[BUFSIZ];
	char	cmd[BUFSIZ];
	const char *args[]	= {&pos[0], NULL};

	if (ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(cmd), cmd, "movej", args))
		return	-1;
	return	alx_ur_cmd(ur, cmd, usleep_after);
}

int	alx_ur_movej_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after)
{
	char	buf[BUFSIZ]; /* used as `pos` and later as `cmd` */
	char	pos_rel[BUFSIZ]; /* used as `pos_rel` */
	const char *args[]	= {&pos_rel[0], NULL};

	if (ur_sprintf_pose(ARRAY_SIZE(buf), buf, pose))
		return	-1;
	if (ur_sprintf_pose_rel(ARRAY_SIZE(pos_rel), pos_rel, buf))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(buf), buf, "movej", args))
		return	-1;
	return	alx_ur_cmd(ur, buf, usleep_after);
}

int	alx_ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after)
{
	char	pos[BUFSIZ];
	char	cmd[BUFSIZ];
	const char *args[]	= {&pos[0], NULL};

	if (ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(cmd), cmd, "movel", args))
		return	-1;
	return	alx_ur_cmd(ur, cmd, usleep_after);
}

int	alx_ur_movel_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after)
{
	char	buf[BUFSIZ]; /* used as `pos` and later as `cmd` */
	char	pos_rel[BUFSIZ]; /* used as `pos_rel` */
	const char *args[]	= {&pos_rel[0], NULL};

	if (ur_sprintf_pose(ARRAY_SIZE(buf), buf, pose))
		return	-1;
	if (ur_sprintf_pose_rel(ARRAY_SIZE(pos_rel), pos_rel, buf))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(buf), buf, "movel", args))
		return	-1;
	return	alx_ur_cmd(ur, buf, usleep_after);
}

int	alx_ur_movec	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict via,
			 const struct Alx_UR_Pose *restrict to,
			 int usleep_after)
{
	char	pos_via[BUFSIZ];
	char	pos_to[BUFSIZ];
	char	cmd[BUFSIZ];
	const char *args[]	= {&pos_via[0], &pos_to[0], NULL};

	if (via->type != ALX_UR_POSE_XYZ)
		return	-1;

	if (ur_sprintf_pose(ARRAY_SIZE(pos_via), pos_via, via))
		return	-1;
	if (ur_sprintf_pose(ARRAY_SIZE(pos_to), pos_to, to))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(cmd), cmd, "movec", args))
		return	-1;
	return	alx_ur_cmd(ur, cmd, usleep_after);
}

int	alx_ur_movec_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict via,
			 const struct Alx_UR_Pose *restrict to,
			 int usleep_after)
{
	char	buf[BUFSIZ]; /* used as `pos` and later as `cmd` */
	char	pos_via[BUFSIZ];
	char	pos_to[BUFSIZ];
	const char *args[]	= {&pos_via[0], &pos_to[0], NULL};

	if (via->type != ALX_UR_POSE_XYZ)
		return	-1;

	if (ur_sprintf_pose(ARRAY_SIZE(buf), buf, via))
		return	-1;
	if (ur_sprintf_pose_rel(ARRAY_SIZE(pos_via), pos_via, buf))
		return	-1;
	if (ur_sprintf_pose(ARRAY_SIZE(buf), buf, to))
		return	-1;
	if (ur_sprintf_pose_rel(ARRAY_SIZE(pos_to), pos_to, buf))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(buf), buf, "movec", args))
		return	-1;
	return	alx_ur_cmd(ur, buf, usleep_after);
}

int	alx_ur_set_tcp	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict tcp,
			 int usleep_after)
{
	char	pos_tcp[BUFSIZ];
	char	cmd[BUFSIZ];
	const char *args[]	= {&pos_tcp[0], NULL};

	if (tcp->type != ALX_UR_POSE_XYZ)
		return	-1;

	if (ur_sprintf_pose(ARRAY_SIZE(pos_tcp), pos_tcp, tcp))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(cmd), cmd, "set_tcp", args))
		return	-1;
	return	alx_ur_cmd(ur, cmd, usleep_after);
}

int	alx_ur_set_Dout	(const struct Alx_UR *restrict ur,
			 ptrdiff_t idx, bool state,
			 int usleep_after)
{
	char	i[BUFSIZ];
	char	b[BUFSIZ];
	char	cmd[BUFSIZ];
	const char *args[]	= {&i[0], &b[0], NULL};

	if (alx_sbprintf(i, NULL, "%ti", idx))
		return	-1;
	if (ur_sprintf_bool(ARRAY_SIZE(b), b, state))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(cmd), cmd, "set_digital_out", args))
		return	-1;
	return	alx_ur_cmd(ur, cmd, usleep_after);
}

int	alx_ur_puts	(const struct Alx_UR *restrict ur,
			 const char *restrict msg,
			 int usleep_after)
{
	char	m[BUFSIZ];
	char	cmd[BUFSIZ];
	const char *args[]	= {&m[0], NULL};

	if (ur_sprintf_msg(ARRAY_SIZE(m), m, msg))
		return	-1;
	if (ur_sprintf_func(ARRAY_SIZE(cmd), cmd, "textmsg", args))
		return	-1;
	return	alx_ur_cmd(ur, cmd, usleep_after);
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
		return	-1;
	}
}

static
int	ur_sprintf_pose_rel	(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const char *restrict pose)
{
	const char *args[]	= {NULL, pose, NULL};

	switch (pose[0]) {
	case 'p':	/* xyz */
		args[0]	= "get_actual_tcp_pose()";
		break;
	case '[':	/* joints */
		args[0]	= "get_actual_joint_positions()";
		break;
	default:
		return	-1;
	}

	if (ur_sprintf_func(nmemb, str, "pose_add", args))
		return	-1;
	return	0;
}

static
int	ur_sprintf_func		(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const char *restrict func,
				 const char *arg[])
{

	if (alx_strlcpys(str, func, nmemb, NULL))
		return	-1;
	if (alx_strscat(nmemb, str, "(") < 0)
		return	-1;
	for (ptrdiff_t i = 0; arg[i]; i++) {
		if (i) {
			if (alx_strscat(nmemb, str, ", ") < 0)
				return	-1;
		}
		if (alx_strscat(nmemb, str, arg[i]) < 0)
			return	-1;
	}
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
int	ur_sprintf_bool		(ptrdiff_t nmemb,
				 char str[static restrict nmemb], bool state)
{
	static const char *const Bool_str[] = {"False", "True"};

	return	alx_strlcpys(str, Bool_str[!!state], nmemb, NULL);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
