/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/getenv/getenv_u.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdint.h>

#include "libalx/base/compiler/attribute.h"


/******************************************************************************
 ******* define ***************************************************************
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
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_getenv_u64		(uint64_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_getenv_u32		(uint32_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_getenv_u16		(uint16_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_getenv_u8		(uint8_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_secure_getenv_u64	(uint64_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_secure_getenv_u32	(uint32_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_secure_getenv_u16	(uint16_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_secure_getenv_u8	(uint8_t *restrict num,
				 const char *restrict name);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(getenv_u64,		alx_getenv_u64);
ALX_ALIAS_DECLARATION(getenv_u32,		alx_getenv_u32);
ALX_ALIAS_DECLARATION(getenv_u16,		alx_getenv_u16);
ALX_ALIAS_DECLARATION(getenv_u8,		alx_getenv_u8);
ALX_ALIAS_DECLARATION(secure_getenv_u64,	alx_secure_getenv_u64);
ALX_ALIAS_DECLARATION(secure_getenv_u32,	alx_secure_getenv_u32);
ALX_ALIAS_DECLARATION(secure_getenv_u16,	alx_secure_getenv_u16);
ALX_ALIAS_DECLARATION(secure_getenv_u8,		alx_secure_getenv_u8);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

