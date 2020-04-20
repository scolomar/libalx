/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/time/timespec.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdint.h>
#include <time.h>

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
__attribute__((pure, nonnull))
int64_t	alx_timespec_ms		(const struct timespec *tm);
__attribute__((pure, nonnull))
int64_t	alx_timespec_us		(const struct timespec *tm);
__attribute__((pure, nonnull))
int64_t	alx_timespec_ns		(const struct timespec *tm);
__attribute__((nonnull))
void	alx_timespec_diff	(struct timespec *diff,
				 const struct timespec *start,
				 const struct timespec *stop);
__attribute__((pure, nonnull))
int64_t	alx_timespec_diff_ms	(const struct timespec *start,
				 const struct timespec *stop);
__attribute__((pure, nonnull))
int64_t	alx_timespec_diff_us	(const struct timespec *start,
				 const struct timespec *stop);
__attribute__((pure, nonnull))
int64_t	alx_timespec_diff_ns	(const struct timespec *start,
				 const struct timespec *stop);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(timespec_ms,	alx_timespec_ms);
ALX_ALIAS_DECLARATION(timespec_us,	alx_timespec_us);
ALX_ALIAS_DECLARATION(timespec_ns,	alx_timespec_ns);
ALX_ALIAS_DECLARATION(timespec_diff,	alx_timespec_diff);
ALX_ALIAS_DECLARATION(timespec_diff_ms,	alx_timespec_diff_ms);
ALX_ALIAS_DECLARATION(timespec_diff_us,	alx_timespec_diff_us);
ALX_ALIAS_DECLARATION(timespec_diff_ns,	alx_timespec_diff_ns);
#endif



/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

