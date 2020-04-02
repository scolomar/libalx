/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot/ur/move/move.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/core/core.h"
#include "libalx/alx/robot/ur/pose/pose.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define ur_halt(ur, timeout)		alx_ur_halt(ur, timeout)

#define ur_is_moving(ur, timeout)	alx_ur_is_moving(ur, timeout)
#define ur_wait_while_moving(ur, timeout, tm_start)			\
	alx_ur_wait_while_moving(ur, timeout, tm_start)
#define ur_is_moving(ur)		alx_ur_is_moving(ur)

#define ur_movej(ur, pose, timeout)	alx_ur_movej(ur, pose, timeout)
#define ur_movej_rel(ur, pose, timeout)	alx_ur_movej_rel(ur, pose, timeout)
#define ur_movel(ur, pose, timeout)	alx_ur_movel(ur, pose, timeout)
#define ur_movel_rel(ur, pose, timeout)	alx_ur_movel_rel(ur, pose, timeout)
#define ur_movec(ur, via, to, timeout)	alx_ur_movec(ur, via, to, timeout)
#define ur_movec_rel(ur, via, to, timeout)				\
	alx_ur_movec_rel(ur, via, to, timeout)
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
int	alx_ur_halt		(struct Alx_UR *ur,
				 double timeout);

__attribute__((nonnull, warn_unused_result))
int	alx_ur_check_movement	(struct Alx_UR *restrict ur,
				 double timeout);
__attribute__((nonnull, warn_unused_result))
int	alx_ur_wait_while_moving(struct Alx_UR *restrict ur,
				 double timeout,
				 const struct timespec *restrict tm_start);
__attribute__((nonnull, warn_unused_result))
bool	alx_ur_is_moving	(const struct Alx_UR *ur);

__attribute__((nonnull, warn_unused_result))
int	alx_ur_movej		(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose,
				 double timeout);
__attribute__((nonnull, warn_unused_result))
int	alx_ur_movej_rel	(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose_rel,
				 double timeout);
__attribute__((nonnull, warn_unused_result))
int	alx_ur_movel		(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose,
				 double timeout);
__attribute__((nonnull, warn_unused_result))
int	alx_ur_movel_rel	(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose_rel,
				 double timeout);
__attribute__((nonnull, warn_unused_result))
int	alx_ur_movec		(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict via,
				 const struct Alx_UR_Pose *restrict to,
				 double timeout);
__attribute__((nonnull, warn_unused_result))
int	alx_ur_movec_rel	(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict via,
				 const struct Alx_UR_Pose *restrict to,
				 double timeout);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
