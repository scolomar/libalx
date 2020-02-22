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
#define alx_ur_pose_xyz(x_, y_, z_, rx_, ry_, rz_)			\
(struct Alx_UR_Pose){							\
	.type	= (ALX_UR_POSE_XYZ),					\
	.x	= (x_),							\
	.y	= (y_),							\
	.z	= (z_),							\
	.rx	= (rx_),						\
	.ry	= (ry_),						\
	.rz	= (rz_)							\
}

#define alx_ur_pose_joints(b_, s_, e_, w1_, w2_, w3_)			\
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
#define ur_pose_xyz(x, y, z, rx, ry, rz)				\
	alx_ur_pose_xyz(x, y, z, rx, ry, rz)
#define ur_pose_joints(base, shoulder, elbow, wrist1, wrist2, wrist3)	\
	alx_ur_pose_joints(base, shoulder, elbow, wrist1, wrist2, wrist3)
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
			 const char *restrict ur_port,
			 int usleep_after);
__attribute__((warn_unused_result))
int	alx_ur_deinit	(struct Alx_UR *restrict ur);

__attribute__((nonnull(1), warn_unused_result))
int	alx_ur_halt	(const struct Alx_UR *restrict ur,
			 int usleep_after, FILE *restrict log);
__attribute__((nonnull(1), warn_unused_result))
int	alx_ur_poweroff	(const struct Alx_UR *restrict ur,
			 int usleep_after, FILE *restrict log);

__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 const char *restrict cmd,
			 int usleep_after, FILE *restrict log);

__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_puts	(const struct Alx_UR *restrict ur,
			 const char *restrict msg,
			 int usleep_after, FILE *restrict log);

__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_movej	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after, FILE *restrict log);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_movej_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after, FILE *restrict log);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after, FILE *restrict log);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_movel_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after, FILE *restrict log);
__attribute__((nonnull(1, 2, 3), warn_unused_result))
int	alx_ur_movec	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict via,
			 const struct Alx_UR_Pose *restrict to,
			 int usleep_after, FILE *restrict log);
__attribute__((nonnull(1, 2, 3), warn_unused_result))
int	alx_ur_movec_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict via,
			 const struct Alx_UR_Pose *restrict to,
			 int usleep_after, FILE *restrict log);

__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_ur_set_tcp	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict tcp,
			 int usleep_after, FILE *restrict log);

__attribute__((nonnull(1), warn_unused_result))
int	alx_ur_set_Dout	(const struct Alx_UR *restrict ur,
			 ptrdiff_t idx, bool state,
			 int usleep_after, FILE *restrict log);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull, warn_unused_result))
int	ur_init		(struct Alx_UR **restrict ur,
			 const char *restrict ur_ip,
			 const char *restrict ur_port,
			 int usleep_after)
{
	return	alx_ur_init(ur, ur_ip, ur_port, usleep_after);
}

__attribute__((always_inline, warn_unused_result))
int	ur_deinit	(struct Alx_UR *restrict ur)
{
	return	alx_ur_deinit(ur);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_cmd		(const struct Alx_UR *restrict ur,
			 const char *restrict cmd,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_cmd(ur, cmd, usleep_after, log);
}

__attribute__((always_inline, nonnull(1), warn_unused_result))
int	ur_halt		(const struct Alx_UR *restrict ur,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_halt(ur, usleep_after, log);
}

__attribute__((always_inline, nonnull(1), warn_unused_result))
int	ur_poweroff	(const struct Alx_UR *restrict ur,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_poweroff(ur, usleep_after, log);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_puts		(const struct Alx_UR *restrict ur,
			 const char *restrict msg,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_puts(ur, msg, usleep_after, log);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_movej	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_movej(ur, pose, usleep_after, log);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_movej_rel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_movej_rel(ur, pose, usleep_after, log);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_movel(ur, pose, usleep_after, log);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_movel_rel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_movel_rel(ur, pose, usleep_after, log);
}

__attribute__((always_inline, nonnull(1, 2, 3), warn_unused_result))
int	ur_movec	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict via,
			 const struct Alx_UR_Pose *restrict to,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_movec(ur, via, to, usleep_after, log);
}

__attribute__((always_inline, nonnull(1, 2, 3), warn_unused_result))
int	ur_movec_rel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict via,
			 const struct Alx_UR_Pose *restrict to,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_movec_rel(ur, via, to, usleep_after, log);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
int	ur_set_tcp	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict tcp,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_set_tcp(ur, tcp, usleep_after, log);
}

__attribute__((always_inline, nonnull(1), warn_unused_result))
int	ur_set_Dout	(const struct Alx_UR *restrict ur,
			 ptrdiff_t idx, bool state,
			 int usleep_after, FILE *restrict log)
{
	return	alx_ur_set_Dout(ur, idx, state, usleep_after, log);
}
#endif	 /* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
