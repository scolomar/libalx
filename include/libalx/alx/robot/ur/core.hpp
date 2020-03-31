/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot/ur/core.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define ur_init(ur, ur_ip, ur_port, usleep_after)			\
	alx_ur_init(ur, ur_ip, ur_port, usleep_after)
#define ur_deinit(ur)							\
	alx_ur_deinit(ur)
#define ur_cmd(ur, usleep_after, fmt, ...)				\
	alx_ur_cmd(ur, usleep_after, fmt, ##__VA_ARGS__)
#define ur_poweroff(ur, usleep_after)					\
	alx_ur_poweroff(ur, usleep_after)
}
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
struct	Alx_UR {
	int	sfd;
};

struct	Alx_UR_Coord {
	double	x;
	double	y;
	double	z;
	double	rx;
	double	ry;
	double	rz;
};

union	Alx_UR_Joints {
	struct {
		double	base;
		double	shoulder;
		double	elbow;
		double	wrist1;
		double	wrist2;
		double	wrist3;
	};
	double	j[6];
};

extern	"C"
{
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_init	(struct Alx_UR **restrict ur,
			 const char *restrict ur_ip,
			 const char *restrict ur_port,
			 int usleep_after);
[[gnu::warn_unused_result]]
int	alx_ur_deinit	(struct Alx_UR *restrict ur);

[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 int usleep_after,
			 const char *restrict fmt, ...);

[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_poweroff	(const struct Alx_UR *restrict ur,
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
