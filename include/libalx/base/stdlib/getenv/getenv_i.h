/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/getenv/getenv_i.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdint.h>


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
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	getenv_i64		(int64_t *restrict num,
				 const char *restrict name)
{
	return	alx_getenv_i64(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	getenv_i32		(int32_t *restrict num,
				 const char *restrict name)
{
	return	alx_getenv_i32(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	getenv_i16		(int16_t *restrict num,
				 const char *restrict name)
{
	return	alx_getenv_i16(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	getenv_i8		(int8_t *restrict num,
				 const char *restrict name)
{
	return	alx_getenv_i8(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	secure_getenv_i64	(int64_t *restrict num,
				 const char *restrict name)
{
	return	alx_secure_getenv_i64(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	secure_getenv_i32	(int32_t *restrict num,
				 const char *restrict name)
{
	return	alx_secure_getenv_i32(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	secure_getenv_i16	(int16_t *restrict num,
				 const char *restrict name)
{
	return	alx_secure_getenv_i16(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	secure_getenv_i8	(int8_t *restrict num,
				 const char *restrict name)
{
	return	alx_secure_getenv_i8(num, name);
}
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

