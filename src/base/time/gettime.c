/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/time/gettime.h"

#include <stdint.h>
#include <time.h>

#include "libalx/base/time/timespec.h"


/******************************************************************************
 ******* macros ***************************************************************
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
	struct timespec	now;

	alx_clock_gettime_diff(clk_id, &now, rt_base);
	return	now.tv_sec;
}

int64_t	alx_clock_gettime_diff_ms	(clockid_t clk_id,
					 const struct timespec *rt_base)
{
	struct timespec	now;

	alx_clock_gettime_diff(clk_id, &now, rt_base);
	return	alx_timespec_ms(&now);
}

int64_t	alx_clock_gettime_diff_us	(clockid_t clk_id,
					 const struct timespec *rt_base)
{
	struct timespec	now;

	alx_clock_gettime_diff(clk_id, &now, rt_base);
	return	alx_timespec_us(&now);
}

int64_t	alx_clock_gettime_diff_ns	(clockid_t clk_id,
					 const struct timespec *rt_base)
{
	struct timespec	now;

	alx_clock_gettime_diff(clk_id, &now, rt_base);
	return	alx_timespec_ns(&now);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

