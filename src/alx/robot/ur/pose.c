/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/pose.h"

#include <stddef.h>
#include <stdio.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/stdio/printf/snprintfs.h"


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
int	alx_ur_sprintf_pose	(ptrdiff_t nmemb,
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

int	alx_ur_sprintf_pose_rel	(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const struct Alx_UR_Pose *restrict pose_rel)
{
	const char	*pos;
	char		pos_rel[BUFSIZ];

	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos_rel), pos_rel, pose_rel))
		return	-1;

	switch (pos_rel[0]) {
	case 'p':	/* xyz */
		pos	= "get_actual_tcp_pose()";
		break;
	case '[':	/* joints */
		pos	= "get_actual_joint_positions()";
		break;
	default:
		return	-1;
	}

	return alx_snprintfs(str, NULL,nmemb, "pose_add(%s, %s)", pos, pos_rel);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
