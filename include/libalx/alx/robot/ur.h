/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot/ur.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stddef.h>
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
			 FILE *restrict log);

__attribute__((warn_unused_result))
struct Alx_UR_Pose alx_ur_pose_xyz(float x, float y, float z,
				   float rx, float ry, float rz);
__attribute__((warn_unused_result))
struct Alx_UR_Pose alx_ur_pose_joints(float base, float shoulder, float elbow,
				      float wrist1, float wrist2, float wrist3);

__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_puts	(const struct Alx_UR *restrict ur,
			 const char *restrict msg, int usleep_after,
			 FILE *restrict log);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_movej	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict log);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_movej_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict log);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict log);
__attribute__((nonnull(1), warn_unused_result))
int	alx_ur_Dout_set	(const struct Alx_UR *restrict ur,
			 ptrdiff_t idx, bool state, int usleep_after,
			 FILE *restrict log);
__attribute__((nonnull(1), warn_unused_result))
int	alx_ur_halt	(const struct Alx_UR *restrict ur, int usleep_after,
			 FILE *restrict log);


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
			 FILE *restrict log)
{
	return	alx_ur_cmd(ur, cmd, usleep_after, log);
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
	return alx_ur_pose_joints(base, shoulder, elbow, wrist1, wrist2,wrist3);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_puts		(const struct Alx_UR *restrict ur,
			 const char *restrict msg, int usleep_after,
			 FILE *restrict log)
{
	return	alx_ur_puts(ur, msg, usleep_after, log);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_movej	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict log)
{
	return	alx_ur_movej(ur, pose, usleep_after, log);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_movej_rel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict log)
{
	return	alx_ur_movej_rel(ur, pose, usleep_after, log);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after,
			 FILE *restrict log)
{
	return	alx_ur_movel(ur, pose, usleep_after, log);
}

__attribute__((always_inline, nonnull(1), warn_unused_result))
int	ur_Dout_set	(const struct Alx_UR *restrict ur,
			 ptrdiff_t idx, bool state, int usleep_after,
			 FILE *restrict log)
{
	return	alx_ur_Dout_set(ur, idx, state, usleep_after, log);
}

__attribute__((always_inline, nonnull(1), warn_unused_result))
int	ur_halt		(const struct Alx_UR *restrict ur,
			 int usleep_after,
			 FILE *restrict log)
{
	return	alx_ur_halt(ur, usleep_after, log);
}
#endif	 /* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
