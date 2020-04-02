/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/move.h"

#include <stdio.h>

#include "libalx/alx/robot/ur/core.h"
#include "libalx/alx/robot/ur/msg.h"
#include "libalx/alx/robot/ur/pose.h"
#include "libalx/base/compiler/size.h"
#include "libalx/base/time/gettime.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define THRESHOLD	(0.001)


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_ur_halt		(struct Alx_UR *ur,
				 int usleep_after)
{
	return	alx_ur_cmd(ur, usleep_after, "halt");
}

int	alx_ur_wait_while_moving(struct Alx_UR *restrict ur,
				 double timeout,
				 const struct timespec *restrict tm_start)
{
	double	time;

	if (alx_ur_robot_state_update(ur))
		return	-1;
	do {
		if (alx_ur_recv(ur))
			return	-1;
		if (!alx_ur_is_moving(ur))
			return	0;
		time	= alx_clock_gettime_diff_ms(CLOCK_REALTIME, tm_start);
	} while (time < timeout * 1000.0);

	return	-1;
}

bool	alx_ur_is_moving	(const struct Alx_UR *ur)
{

	for (ptrdiff_t i = 0; i < NJOINTS; i++) {
		if (ur->state.joint.qd_actual.j[i] > THRESHOLD)
			return	true;
	}
	return	false;
}

int	alx_ur_movej		(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose,
				 double timeout)
{
	char		pos[BUFSIZ];
	struct timespec	start;

	clock_gettime(CLOCK_REALTIME, &start);

	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	if (alx_ur_cmd(ur, 0, "movej(%s);", pos))
		return	-1;

	if (alx_ur_wait_while_moving(ur, timeout, &start))
		return	-1;
	if (!alx_ur_is_at_pose(ur, pose))
		return	-1;
	return	0;
}

int	alx_ur_movej_rel	(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose_rel,
				 int usleep_after)
{
	char	pos_rel[BUFSIZ];

	if (alx_ur_sprintf_pose_rel(ARRAY_SIZE(pos_rel), pos_rel, pose_rel))
		return	-1;
	return	alx_ur_cmd(ur, usleep_after, "movej(%s);", pos_rel);
}

int	alx_ur_movel		(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose,
				 int usleep_after)
{
	char	pos[BUFSIZ];

	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	return	alx_ur_cmd(ur, usleep_after, "movel(%s);", pos);
}

int	alx_ur_movel_rel	(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose_rel,
				 int usleep_after)
{
	char	pos_rel[BUFSIZ];

	if (alx_ur_sprintf_pose_rel(ARRAY_SIZE(pos_rel), pos_rel, pose_rel))
		return	-1;
	return	alx_ur_cmd(ur, usleep_after, "movel(%s);", pos_rel);
}

int	alx_ur_movec		(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict via,
				 const struct Alx_UR_Pose *restrict to,
				 int usleep_after)
{
	char	pos_via[BUFSIZ];
	char	pos_to[BUFSIZ];

	if (via->type != ALX_UR_POSE_XYZ)
		return	-1;

	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos_via), pos_via, via))
		return	-1;
	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos_to), pos_to, to))
		return	-1;
	return	alx_ur_cmd(ur, usleep_after, "movec(%s, %s);", pos_via, pos_to);
}

int	alx_ur_movec_rel	(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict via,
				 const struct Alx_UR_Pose *restrict to,
				 int usleep_after)
{
	char	pos_via[BUFSIZ];
	char	pos_to[BUFSIZ];

	if (via->type != ALX_UR_POSE_XYZ)
		return	-1;

	if (alx_ur_sprintf_pose_rel(ARRAY_SIZE(pos_via), pos_via, via))
		return	-1;
	if (alx_ur_sprintf_pose_rel(ARRAY_SIZE(pos_to), pos_to, to))
		return	-1;
	return	alx_ur_cmd(ur, usleep_after, "movec(%s, %s);", pos_via, pos_to);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
