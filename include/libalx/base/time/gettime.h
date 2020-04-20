/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/time/gettime.h */

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


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define clock_gettime_diff(clk_id, diff, rt_base)			\
	alx_clock_gettime_diff(clk_id, diff, rt_base)
#define clock_gettime_diff_s(clk_id, rt_base)				\
	alx_clock_gettime_diff_s(clk_id, rt_base)
#define clock_gettime_diff_ms(clk_id, rt_base)				\
	alx_clock_gettime_diff_ms(clk_id, rt_base)
#define clock_gettime_diff_us(clk_id, rt_base)				\
	alx_clock_gettime_diff_us(clk_id, rt_base)
#define clock_gettime_diff_ns(clk_id, rt_base)				\
	alx_clock_gettime_diff_ns(clk_id, rt_base)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull))
void	alx_clock_gettime_diff		(clockid_t clk_id,
					 struct timespec *diff,
					 const struct timespec *rt_base);
__attribute__((nonnull))
int64_t	alx_clock_gettime_diff_s	(clockid_t clk_id,
					 const struct timespec *rt_base);
__attribute__((nonnull))
int64_t	alx_clock_gettime_diff_ms	(clockid_t clk_id,
					 const struct timespec *rt_base);
__attribute__((nonnull))
int64_t	alx_clock_gettime_diff_us	(clockid_t clk_id,
					 const struct timespec *rt_base);
__attribute__((nonnull))
int64_t	alx_clock_gettime_diff_ns	(clockid_t clk_id,
					 const struct timespec *rt_base);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

