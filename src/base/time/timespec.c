/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/time/timespec.h"

#include <stdint.h>
#include <time.h>


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
int64_t	alx_timespec_ms			(const struct timespec *tm)
{
	return	tm->tv_sec * INT64_C(1000)  +  tm->tv_nsec / INT64_C(1000000);
}

int64_t	alx_timespec_us			(const struct timespec *tm)
{
	return	tm->tv_sec * INT64_C(1000000)  +  tm->tv_nsec / INT64_C(1000);
}

int64_t	alx_timespec_ns			(const struct timespec *tm)
{
	return	tm->tv_sec * INT64_C(1000000000)  +  tm->tv_nsec;
}

void	alx_timespec_diff		(struct timespec *diff,
					 const struct timespec *start,
					 const struct timespec *stop)
{

	if (stop->tv_nsec < start->tv_nsec) {
		diff->tv_sec	= stop->tv_sec - start->tv_sec - 1;
		diff->tv_nsec	= stop->tv_nsec - start->tv_nsec + 1000000000l;
	} else {
		diff->tv_sec	= stop->tv_sec - start->tv_sec;
		diff->tv_nsec	= stop->tv_nsec - start->tv_nsec;
	}
}

int64_t	alx_timespec_diff_ms		(const struct timespec *start,
					 const struct timespec *stop)
{
	struct timespec	diff;

	alx_timespec_diff(&diff, start, stop);
	return	alx_timespec_ms(&diff);
}

int64_t	alx_timespec_diff_us		(const struct timespec *start,
					 const struct timespec *stop)
{
	struct timespec	diff;

	alx_timespec_diff(&diff, start, stop);
	return	alx_timespec_us(&diff);
}

int64_t	alx_timespec_diff_ns		(const struct timespec *start,
					 const struct timespec *stop)
{
	struct timespec	diff;

	alx_timespec_diff(&diff, start, stop);
	return	alx_timespec_ns(&diff);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

