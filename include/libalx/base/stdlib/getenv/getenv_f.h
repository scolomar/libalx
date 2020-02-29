/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/getenv/getenv_f.h */


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
int	alx_getenv_d		(double *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_getenv_f		(float *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_getenv_ld		(long double *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_secure_getenv_d	(double *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_secure_getenv_f	(float *restrict num,
				 const char *restrict name);
__attribute__((nonnull, warn_unused_result))
int	alx_secure_getenv_ld	(long double *restrict num,
				 const char *restrict name);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	getenv_d		(double *restrict num,
				 const char *restrict name)
{
	return	alx_getenv_d(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	getenv_f		(float *restrict num,
				 const char *restrict name)
{
	return	alx_getenv_f(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	getenv_ld		(long double *restrict num,
				 const char *restrict name)
{
	return	alx_getenv_ld(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	secure_getenv_d		(double *restrict num,
				 const char *restrict name)
{
	return	alx_secure_getenv_d(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	secure_getenv_f		(float *restrict num,
				 const char *restrict name)
{
	return	alx_secure_getenv_f(num, name);
}

__attribute__((always_inline, nonnull, warn_unused_result))
inline
int	secure_getenv_ld	(long double *restrict num,
				 const char *restrict name)
{
	return	alx_secure_getenv_ld(num, name);
}
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

