/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/telnet-tcp/client/client.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdio.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define telnet_sendf(telnet, fmt, ...)					\
	alx_telnet_sendf(telnet, fmt, ##__VA_ARGS__)
#endif


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull(1, 2, 4), warn_unused_result))
int	alx_telnet_open_client	(FILE **restrict telnet,
				 const char *restrict server_addr,
				 const char *restrict server_port,
				 const char *restrict rw);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_telnet_login	(FILE *restrict telnet,
				 const char *restrict user,
				 const char *restrict passwd,
				 int delay_us);
__attribute__((nonnull, warn_unused_result))
int	alx_telnet_send		(FILE *restrict telnet,
				 const char *restrict msg);
__attribute__((nonnull, format(printf, 2, 3), warn_unused_result))
int	alx_telnet_sendf	(FILE *restrict telnet,
				 const char *restrict fmt, ...);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull(1, 2, 4), warn_unused_result))
inline
int	telnet_open_client	(FILE **restrict telnet,
				 const char *restrict server_addr,
				 const char *restrict server_port,
				 const char *restrict rw)
{
	return	alx_telnet_open_client(telnet, server_addr, server_port, rw);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
inline
int	telnet_login		(FILE *restrict telnet,
				 const char *restrict user,
				 const char *restrict passwd,
				 int delay_us)
{
	return	alx_telnet_login(telnet, user, passwd, delay_us);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	telnet_send		(FILE *restrict telnet,
				 const char *restrict msg)
{
	return	alx_telnet_send(telnet, msg);
}
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

