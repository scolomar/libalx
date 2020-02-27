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
enum	Alx_Telnet_TCP_Log {
	ALX_TELNET_TCP_LOG_NOT,
	ALX_TELNET_TCP_LOG_APPEND,
	ALX_TELNET_TCP_LOG_OVR
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull(1, 2, 4), warn_unused_result))
int	alx_telnet_open_client	(FILE **restrict telnet,
				 char *restrict server_addr,
				 char *restrict server_port, char *restrict rw,
				 int log, char *fout, char *ferr);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_telnet_login	(FILE *restrict telnet,
				 char *restrict user, char *restrict passwd);
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
				 char *restrict server_port, char *restrict rw,
				 int log, char *fout, char *ferr)
{
	return	alx_telnet_open_client(telnet, server_addr, server_port, rw,
							log, fout, ferr);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
inline
int	telnet_login		(FILE *restrict telnet,
				 char *restrict user, char *restrict passwd)
{
	return	alx_telnet_login(telnet, user, passwd);
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

