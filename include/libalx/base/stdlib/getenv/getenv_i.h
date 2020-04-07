/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/getenv/getenv_i.h */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdint.h>


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
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull, warn_unused_result))
int	alx_getenv_i64		(int64_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_getenv_i32		(int32_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_getenv_i16		(int16_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_getenv_i8		(int8_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_secure_getenv_i64	(int64_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_secure_getenv_i32	(int32_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_secure_getenv_i16	(int16_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_secure_getenv_i8	(int8_t *restrict num,
				 const char *restrict name);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

