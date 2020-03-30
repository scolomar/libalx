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
#include "libalx/alx/robot/ur/pose.h"
#include "libalx/base/compiler/size.h"


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
int	alx_ur_halt	(const struct Alx_UR *restrict ur,
			 int usleep_after)
{
	return	alx_ur_cmd(ur, usleep_after, "halt");
}

int	alx_ur_movej	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after)
{
	char	pos[BUFSIZ];

	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	return	alx_ur_cmd(ur, usleep_after, "movej(%s);", pos);
}

int	alx_ur_movej_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose_rel,
			 int usleep_after)
{
	char	pos_rel[BUFSIZ];

	if (alx_ur_sprintf_pose_rel(ARRAY_SIZE(pos_rel), pos_rel, pose_rel))
		return	-1;
	return	alx_ur_cmd(ur, usleep_after, "movej(%s);", pos_rel);
}

int	alx_ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after)
{
	char	pos[BUFSIZ];

	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	return	alx_ur_cmd(ur, usleep_after, "movel(%s);", pos);
}

int	alx_ur_movel_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose_rel,
			 int usleep_after)
{
	char	pos_rel[BUFSIZ];

	if (alx_ur_sprintf_pose_rel(ARRAY_SIZE(pos_rel), pos_rel, pose_rel))
		return	-1;
	return	alx_ur_cmd(ur, usleep_after, "movel(%s);", pos_rel);
}

int	alx_ur_movec	(const struct Alx_UR *restrict ur,
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

int	alx_ur_movec_rel(const struct Alx_UR *restrict ur,
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