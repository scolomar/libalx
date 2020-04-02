/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot/ur/move.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/core.hpp"
#include "libalx/alx/robot/ur/pose.hpp"
#include "libalx/base/compiler/restrict.hpp"


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
#define ur_movec(ur, via, to, usleep_after)				\
	alx_ur_movec(ur, via, to, usleep_after)
#define ur_movec_rel(ur, via, to, usleep_after)				\
	alx_ur_movec_rel(ur, via, to, usleep_after)
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_halt		(struct Alx_UR *restrict ur,
				 int usleep_after);

[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_wait_while_moving(struct Alx_UR *restrict ur,
				 double timeout,
				 const struct timespec *restrict tm_start);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
bool	alx_ur_is_moving	(const struct Alx_UR *ur);

[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movej		(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose,
				 double timeout);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movej_rel	(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose_rel,
				 int usleep_after);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movel		(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose,
				 int usleep_after);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movel_rel	(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose_rel,
				 int usleep_after);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movec		(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict via,
				 const struct Alx_UR_Pose *restrict to,
				 int usleep_after);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movec_rel	(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict via,
				 const struct Alx_UR_Pose *restrict to,
				 int usleep_after);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace UR {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace UR */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
