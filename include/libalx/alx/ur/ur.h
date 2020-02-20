/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/ur/ur.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdio.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


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
struct	Alx_UR {
	int	sfd;
};

struct	Alx_UR_Pose {
	int	type;
	union {
		struct {
			float	x;
			float	y;
			float	z;
			float	rx;
			float	ry;
			float	rz;
		};
		struct {
			float	base;
			float	shoulder;
			float	elbow;
			float	wrist1;
			float	wrist2;
			float	wrist3;
		};
	};
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull, warn_unused_result))
int	alx_ur_init	(struct Alx_UR **restrict ur,
			 const char *restrict ur_ip,
			 const char *restrict ur_port);
__attribute__((warn_unused_result))
int	alx_ur_deinit	(struct Alx_UR *restrict ur);

__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 const char *restrict cmd, int usleep_after,
			 FILE *restrict ostream);

__attribute__((warn_unused_result))
struct Alx_UR_Pose alx_ur_pose_xyz(float x, float y, float z,
				   float rx, float ry, float rz);
__attribute__((warn_unused_result))
struct Alx_UR_Pose alx_ur_pose_joints(float base, float shoulder, float elbow,
				      float wrist1, float wrist2, float wrist3);

__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_movej	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *pose, int usleep_after,
			 FILE *restrict ostream);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *pose, int usleep_after,
			 FILE *restrict ostream);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull, warn_unused_result))
int	ur_init		(struct Alx_UR **restrict ur,
			 const char *restrict ur_ip,
			 const char *restrict ur_port)
{
	return	alx_ur_init(ur, ur_ip, ur_port);
}

__attribute__((always_inline, warn_unused_result))
int	ur_deinit	(struct Alx_UR *restrict ur)
{
	return	alx_ur_deinit(ur);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_cmd		(const struct Alx_UR *restrict ur,
			 const char *restrict cmd, int usleep_after,
			 FILE *restrict ostream)
{
	return	alx_ur_cmd(ur, cmd, usleep_after, ostream);
}

__attribute__((always_inline, warn_unused_result))
struct Alx_UR_Pose ur_pose_xyz(float x, float y, float z,
			       float rx, float ry, float rz)
{
	return	alx_ur_pose_xyz(x, y, z, rx, ry, rz);
}

__attribute__((always_inline, warn_unused_result))
struct Alx_UR_Pose ur_pose_joints(float base, float shoulder, float elbow,
				  float wrist1, float wrist2, float wrist3)
{
	return	alx_ur_pose_xyz(base, shoulder, elbow, wrist1, wrist2, wrist3);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_movej	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *pose, int usleep_after,
			 FILE *restrict ostream)
{
	return	alx_ur_movej(ur, pose, usleep_after, ostream);
}
__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *pose, int usleep_after,
			 FILE *restrict ostream)
{
	return	alx_ur_movel(ur, pose, usleep_after, ostream);
}
#endif	 /* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
