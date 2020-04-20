/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/getenv/getenv_i.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdint>

#include "libalx/base/compiler/attribute.hpp"
#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	getenv_i64		(int64_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	getenv_i32		(int32_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	getenv_i16		(int16_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	getenv_i8		(int8_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	secure_getenv_i64	(int64_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	secure_getenv_i32	(int32_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	secure_getenv_i16	(int16_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	secure_getenv_i8	(int8_t *restrict num,
				 const char *restrict name);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


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
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(getenv_i64,		alx_getenv_i64);
ALX_ALIAS_DECLARATION(getenv_i32,		alx_getenv_i32);
ALX_ALIAS_DECLARATION(getenv_i16,		alx_getenv_i16);
ALX_ALIAS_DECLARATION(getenv_i8,		alx_getenv_i8);
ALX_ALIAS_DECLARATION(secure_getenv_i64,	alx_secure_getenv_i64);
ALX_ALIAS_DECLARATION(secure_getenv_i32,	alx_secure_getenv_i32);
ALX_ALIAS_DECLARATION(secure_getenv_i16,	alx_secure_getenv_i16);
ALX_ALIAS_DECLARATION(secure_getenv_i8,		alx_secure_getenv_i8);
#endif


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

