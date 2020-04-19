/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/time/timespec.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdint>
#include <ctime>


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define timespec_diff(diff, start, stop)   alx_timespec_diff(diff, start, stop)
#define timespec_ms(tm)			   alx_timespec_ms(tm)
#define timespec_us(tm)			   alx_timespec_us(tm)
#define timespec_ns(tm)			   alx_timespec_ns(tm)


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::pure]]] [[gnu::nonnull]]
int64_t	alx_timespec_ms			(const struct timespec *tm);
[[gnu::pure]]] [[gnu::nonnull]]
int64_t	alx_timespec_us			(const struct timespec *tm);
[[gnu::pure]]] [[gnu::nonnull]]
int64_t	alx_timespec_ns			(const struct timespec *tm);
[[gnu::nonnull]]
void	alx_timespec_diff		(struct timespec *diff,
					 const struct timespec *start,
					 const struct timespec *stop);
[[gnu::pure]]] [[gnu::nonnull]]
int64_t	alx_timespec_diff_ms		(const struct timespec *start,
					 const struct timespec *stop);
[[gnu::pure]]] [[gnu::nonnull]]
int64_t	alx_timespec_diff_us		(const struct timespec *start,
					 const struct timespec *stop);
[[gnu::pure]]] [[gnu::nonnull]]
int64_t	alx_timespec_diff_ns		(const struct timespec *start,
					 const struct timespec *stop);
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

