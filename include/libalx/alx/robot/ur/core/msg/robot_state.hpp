/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot/ur/core/msg/robot_state.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdint>

#include <sys/types.h>

#include "libalx/alx/robot/ur/core/core.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define ur_robot_state_update(ur)	alx_ur_robot_state_update(ur)
#define ur_parse_msg_robot_state(ur, sz, msg, ts)			\
	alx_ur_parse_msg_robot_state(ur, sz, msg, ts)
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_robot_state_update	(struct Alx_UR *ur);
[[gnu::nonnull]]
void	alx_ur_parse_msg_robot_state	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char *restrict msg/*[sz]*/,
					 const struct timespec *restrict ts);
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
struct	Robot_Msg_Hdr {
	uint64_t	timestamp;
	char		source;
	int8_t		type;
};

struct	Robot_State_Pkg_Hdr {
	int32_t	sz;
	uint8_t	type;
};


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
