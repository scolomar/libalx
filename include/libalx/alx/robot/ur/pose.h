/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot/ur/pose.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stddef.h>

#include "libalx/alx/robot/ur/core.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_UR_POSE_INIT_XYZ(x_, y_, z_, rx_, ry_, rz_)			\
(struct Alx_UR_Pose){							\
	.type	= (ALX_UR_POSE_XYZ),					\
	.x	= (x_),							\
	.y	= (y_),							\
	.z	= (z_),							\
	.rx	= (rx_),						\
	.ry	= (ry_),						\
	.rz	= (rz_)							\
}

#define ALX_UR_POSE_INIT_JOINTS(b_, s_, e_, w1_, w2_, w3_)		\
(struct Alx_UR_Pose){							\
	.type		= (ALX_UR_POSE_JOINTS),				\
	.base		= (b_),						\
	.shoulder	= (s_),						\
	.elbow		= (e_),						\
	.wrist1		= (w1_),					\
	.wrist2		= (w2_),					\
	.wrist3		= (w3_)						\
}


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define UR_POSE_INIT_XYZ(x, y, z, rx, ry, rz)				\
	ALX_UR_POSE_INIT_XYZ(x, y, z, rx, ry, rz)
#define UR_POSE_INIT_JOINTS(b, s, e, w1, w2, w3)			\
	ALX_UR_POSE_INIT_JOINTS(b, s, e, w1, w2, w3)

#define ur_sprintf_pose(nmemb, str, pose)				\
	alx_ur_sprintf_pose(nmemb, str, pose)
#define ur_sprintf_pose_rel(nmemb, str, pose_rel)			\
	alx_ur_sprintf_pose_rel(nmemb, str, pose_rel)
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Alx_UR_Pose_Types {
	ALX_UR_POSE_NONE,
	ALX_UR_POSE_XYZ,
	ALX_UR_POSE_JOINTS
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
struct	Alx_UR_Pose {
	int	type;
	union {
		struct Alx_UR_Coord	xyz;
		union Alx_UR_Joints	j;
	};
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull))
int	alx_ur_pose_diff	(struct Alx_UR_Pose *restrict diff,
				 const struct Alx_UR_Pose *restrict a,
				 const struct Alx_UR_Pose *restrict b);
__attribute__((nonnull, warn_unused_result))
bool	alx_ur_is_at_pose	(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose);
__attribute__((nonnull))
int	alx_ur_sprintf_pose	(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const struct Alx_UR_Pose *restrict pose);
__attribute__((nonnull))
int	alx_ur_sprintf_pose_rel	(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const struct Alx_UR_Pose *restrict pose_rel);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
