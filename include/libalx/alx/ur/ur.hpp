/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/ur/ur.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define ur_init(ur, usleep_time, ur_ip, ur_port)			\
				alx_ur_init(ur, usleep_time, ur_ip, ur_port)
#define ur_deinit(ur)		alx_ur_deinit(ur)
#define ur_cmd(ur, cmd)		alx_ur_cmd(ur, cmd)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
struct	Alx_UR {
	int	sfd;
	int	usleep;
};

extern	"C"
{
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_init	(struct Alx_UR *restrict ur, int usleep_time,
			 const char *restrict ur_ip,
			 const char *restrict ur_port);
[[gnu::warn_unused_result]]
int	alx_ur_deinit	(struct Alx_UR *restrict ur);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 const char *restrict cmd);
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