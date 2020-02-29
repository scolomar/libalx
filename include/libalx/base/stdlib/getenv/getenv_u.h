/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/getenv/getenv_u.h */


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
int	alx_getenv_u64		(uint64_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_getenv_u32		(uint32_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_getenv_u16		(uint16_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_getenv_u8		(uint8_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_secure_getenv_u64	(uint64_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_secure_getenv_u32	(uint32_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_secure_getenv_u16	(uint16_t *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_secure_getenv_u8	(uint8_t *restrict num,
				 const char *restrict name);


/******************************************************************************
 ******* always_unline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_unline, nonnull, warn_unused_result))
inline
int	getenv_u64		(uint64_t *restrict num,
				 const char *restrict name)
{
	return	alx_getenv_u64(num, name);
}

__attribute__((always_unline, nonnull, warn_unused_result))
inline
int	getenv_u32		(uint32_t *restrict num,
				 const char *restrict name)
{
	return	alx_getenv_u32(num, name);
}

__attribute__((always_unline, nonnull, warn_unused_result))
inline
int	getenv_u16		(uint16_t *restrict num,
				 const char *restrict name)
{
	return	alx_getenv_u16(num, name);
}

__attribute__((always_unline, nonnull, warn_unused_result))
inline
int	getenv_u8		(uint8_t *restrict num,
				 const char *restrict name)
{
	return	alx_getenv_u8(num, name);
}

__attribute__((always_unline, nonnull, warn_unused_result))
inline
int	secure_getenv_u64	(uint64_t *restrict num,
				 const char *restrict name)
{
	return	alx_secure_getenv_u64(num, name);
}

__attribute__((always_unline, nonnull, warn_unused_result))
inline
int	secure_getenv_u32	(uint32_t *restrict num,
				 const char *restrict name)
{
	return	alx_secure_getenv_u32(num, name);
}

__attribute__((always_unline, nonnull, warn_unused_result))
inline
int	secure_getenv_u16	(uint16_t *restrict num,
				 const char *restrict name)
{
	return	alx_secure_getenv_u16(num, name);
}

__attribute__((always_unline, nonnull, warn_unused_result))
inline
int	secure_getenv_u8	(uint8_t *restrict num,
				 const char *restrict name)
{
	return	alx_secure_getenv_u8(num, name);
}
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

