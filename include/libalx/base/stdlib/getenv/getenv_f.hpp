/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/getenv/getenv_f.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define getenv_d(num, name)		alx_getenv_d(num, name)
#define getenv_f(num, name)		alx_getenv_f(num, name)
#define getenv_ld(num, name)		alx_getenv_ld(num, name)
#define secure_getenv_d(num, name)	alx_secure_getenv_d(num, name)
#define secure_getenv_f(num, name)	alx_secure_getenv_f(num, name)
#define secure_getenv_ld(num, name)	alx_secure_getenv_ld(num, name)
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	getenv_d		(double *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	getenv_f		(float *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	getenv_ld		(long double *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	secure_getenv_d		(double *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	secure_getenv_f		(float *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	secure_getenv_ld	(long double *restrict num,
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

