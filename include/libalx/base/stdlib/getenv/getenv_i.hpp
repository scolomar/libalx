/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/getenv/getenv_i.hpp */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdint>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define getenv_i64(num, name)		alx_getenv_i64(num, name)
#define getenv_i32(num, name)		alx_getenv_i32(num, name)
#define getenv_i16(num, name)		alx_getenv_i16(num, name)
#define getenv_i8(num, name)		alx_getenv_i8(num, name)
#define secure_getenv_i64(num, name)	alx_secure_getenv_i64(num, name)
#define secure_getenv_i32(num, name)	alx_secure_getenv_i32(num, name)
#define secure_getenv_i16(num, name)	alx_secure_getenv_i16(num, name)
#define secure_getenv_i8(num, name)	alx_secure_getenv_i8(num, name)
#endif	/* defined(ALX_NO_PREFIX) */


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
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

