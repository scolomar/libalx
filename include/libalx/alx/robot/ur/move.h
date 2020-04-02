/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot/ur/move.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/core.h"
#include "libalx/alx/robot/ur/pose.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define ur_halt(ur, usleep_after)					\
	alx_ur_halt(ur, usleep_after)
#define ur_movej(ur, pose, usleep_after)				\
	alx_ur_movej(ur, pose, usleep_after)
#define ur_movej_rel(ur, pose, usleep_after)				\
	alx_ur_movej_rel(ur, pose, usleep_after)
#define ur_movel(ur, pose, usleep_after)				\
	alx_ur_movel(ur, pose, usleep_after)
#define ur_movel_rel(ur, pose, usleep_after)				\
	alx_ur_movel_rel(ur, pose, usleep_after)
#define ur_movec(ur, via, to, usleep_afterg)				\
	alx_ur_movec(ur, via, to, usleep_after)
#define ur_movec_rel(ur, via, to, usleep_after)				\
	alx_ur_movec_rel(ur, via, to, usleep_after)
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull, warn_unused_result))
int	alx_ur_halt	(struct Alx_UR *restrict ur,
			 int usleep_after);

__attribute__((nonnull, warn_unused_result))
int	alx_ur_movej	(struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 double timeout);
__attribute__((nonnull, warn_unused_result))
int	alx_ur_movej_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose_rel,
			 int usleep_after);
__attribute__((nonnull, warn_unused_result))
int	alx_ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after);
__attribute__((nonnull, warn_unused_result))
int	alx_ur_movel_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose_rel,
			 int usleep_after);
__attribute__((nonnull, warn_unused_result))
int	alx_ur_movec	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict via,
			 const struct Alx_UR_Pose *restrict to,
			 int usleep_after);
__attribute__((nonnull, warn_unused_result))
int	alx_ur_movec_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict via,
			 const struct Alx_UR_Pose *restrict to,
			 int usleep_after);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
