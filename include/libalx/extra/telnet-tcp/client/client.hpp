/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/telnet-tcp/client/client.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdio>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define telnet_open_client(telnet, server_addr, server_port, rw)	\
	alx_telnet_open_client(telnet, server_addr, server_port, rw)
#define telnet_login(telnet, user, passwd, delay_us)			\
	alx_telnet_login(telnet, user, passwd, delay_us)
#define telnet_send(telnet, msg)					\
	alx_telnet_send(telnet, msg)
#define telnet_sendf(telnet, fmt, ...)					\
	alx_telnet_sendf(telnet, fmt, ##__VA_ARGS__)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull(1, 2, 4)]] [[gnu::warn_unused_result]]
int	alx_telnet_open_client	(FILE **restrict telnet,
				 const char *restrict server_addr,
				 const char *restrict server_port,
				 const char *restrict rw);
[[gnu::nonnull(1, 2)]] [[gnu::warn_unused_result]]
int	alx_telnet_login	(FILE *restrict telnet,
				 const char *restrict user,
				 const char *restrict passwd,
				 int delay_us);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_telnet_send		(FILE *restrict telnet,
				 const char *restrict msg);
[[gnu::nonnull]] [[gnu::format(printf, 2, 3)]] [[gnu::warn_unused_result]]
int	alx_telnet_sendf	(FILE *restrict telnet,
				 const char *restrict fmt, ...);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace telnet {


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
}	/* namespace telnet */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

