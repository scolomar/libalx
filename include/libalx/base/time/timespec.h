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
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdint.h>
#include <time.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define timespec_ms(tm)			    alx_timespec_ms(tm)
#define timespec_us(tm)			    alx_timespec_us(tm)
#define timespec_ns(tm)			    alx_timespec_ns(tm)
#define timespec_diff(diff, start, stop)    alx_timespec_diff(diff, start, stop)
#define timespec_diff_ms(start, stop)	    alx_timespec_diff_ms(start, stop)
#define timespec_diff_us(start, stop)	    alx_timespec_diff_us(start, stop)
#define timespec_diff_ns(start, stop)	    alx_timespec_diff_ns(start, stop)


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
int64_t	alx_timespec_ms			(const struct timespec *tm);
__attribute__((pure, nonnull))
int64_t	alx_timespec_us			(const struct timespec *tm);
__attribute__((pure, nonnull))
int64_t	alx_timespec_ns			(const struct timespec *tm);
__attribute__((nonnull))
void	alx_timespec_diff		(struct timespec *diff,
					 const struct timespec *start,
					 const struct timespec *stop);
__attribute__((pure, nonnull))
int64_t	alx_timespec_diff_ms		(const struct timespec *start,
					 const struct timespec *stop);
__attribute__((pure, nonnull))
int64_t	alx_timespec_diff_us		(const struct timespec *start,
					 const struct timespec *stop);
__attribute__((pure, nonnull))
int64_t	alx_timespec_diff_ns		(const struct timespec *start,
					 const struct timespec *stop);



/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

