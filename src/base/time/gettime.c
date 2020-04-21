/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/time/gettime.h"

#include <stdint.h>
#include <time.h>

#include "libalx/base/time/timespec.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	alx_clock_gettime_diff		(clockid_t clk_id,
					 struct timespec *diff,
					 const struct timespec *rt_base)
{

	clock_gettime(clk_id, diff);
	alx_timespec_diff(diff, rt_base, diff);
}

int64_t	alx_clock_gettime_diff_s	(clockid_t clk_id,
					 const struct timespec *rt_base)
{
	struct timespec	tm;

	clock_gettime(clk_id, &tm);
	alx_timespec_diff(&tm, rt_base, &tm);
	return	tm.tv_sec;
}

int64_t	alx_clock_gettime_diff_ms	(clockid_t clk_id,
					 const struct timespec *rt_base)
{
	struct timespec	tm;

	clock_gettime(clk_id, &tm);
	return	alx_timespec_diff_ms(rt_base, &tm);
}

int64_t	alx_clock_gettime_diff_us	(clockid_t clk_id,
					 const struct timespec *rt_base)
{
	struct timespec	tm;

	clock_gettime(clk_id, &tm);
	return	alx_timespec_diff_us(rt_base, &tm);
}

int64_t	alx_clock_gettime_diff_ns	(clockid_t clk_id,
					 const struct timespec *rt_base)
{
	struct timespec	tm;

	clock_gettime(clk_id, &tm);
	return	alx_timespec_diff_ns(rt_base, &tm);
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_WEAK_DEF(clock_gettime_diff,	 alx_clock_gettime_diff);
ALX_ALIAS_WEAK_DEF(clock_gettime_diff_s,	 alx_clock_gettime_diff_s);
ALX_ALIAS_WEAK_DEF(clock_gettime_diff_ms, alx_clock_gettime_diff_ms);
ALX_ALIAS_WEAK_DEF(clock_gettime_diff_us, alx_clock_gettime_diff_us);
ALX_ALIAS_WEAK_DEF(clock_gettime_diff_ns, alx_clock_gettime_diff_ns);
#endif


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

