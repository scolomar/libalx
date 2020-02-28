/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/telnet-tcp/client/client.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdio.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


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
				 char *restrict server_addr,
				 char *restrict server_port, char *restrict rw);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_telnet_login	(FILE *restrict telnet,
				 char *restrict user, char *restrict passwd,
				 int delay_us);
__attribute__((nonnull(1), warn_unused_result))
int	alx_telnet_send		(FILE *restrict telnet, char *restrict msg);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull(1, 2, 4), warn_unused_result))
inline
int	telnet_open_client	(FILE **restrict telnet,
				 char *restrict server_addr,
				 char *restrict server_port, char *restrict rw)
{
	return	alx_telnet_open_client(telnet, server_addr, server_port, rw);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
inline
int	telnet_login		(FILE *restrict telnet,
				 char *restrict user, char *restrict passwd,
				 int delay_us)
{
	return	alx_telnet_login(telnet, user, passwd, delay_us);
}

__attribute__((always_inline, nonnull(1), warn_unused_result))
inline
int	telnet_send		(FILE *restrict telnet, char *restrict msg)
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

