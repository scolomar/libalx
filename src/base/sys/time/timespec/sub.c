/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/sys/time/timespec/sub.h"

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
void	alx_timespec_sub		(const struct timespec *stop,
					 const struct timespec *start,
					 struct timespec *diff)
{

	diff->tv_sec	= stop->tv_sec - start->tv_sec;
	diff->tv_nsec	= stop->tv_nsec - start->tv_nsec;
	if (diff->tv_nsec < 0) {
		diff->tv_sec--;
		diff->tv_nsec += 1000000000l;
	}
}

int64_t	alx_timespec_sub_ms		(const struct timespec *stop,
					 const struct timespec *start)
{
	struct timespec	diff;

	alx_timespec_sub(stop, start, &diff);
	return	alx_timespec_ms(&diff);
}

int64_t	alx_timespec_sub_us		(const struct timespec *stop,
					 const struct timespec *start)
{
	struct timespec	diff;

	alx_timespec_sub(stop, start, &diff);
	return	alx_timespec_us(&diff);
}

int64_t	alx_timespec_sub_ns		(const struct timespec *stop,
					 const struct timespec *start)
{
	struct timespec	diff;

	alx_timespec_sub(stop, start, &diff);
	return	alx_timespec_ns(&diff);
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(timespec_sub,	alx_timespec_sub);
ALX_ALIAS_WEAK_DEF(timespec_sub_ms,	alx_timespec_sub_ms);
ALX_ALIAS_WEAK_DEF(timespec_sub_us,	alx_timespec_sub_us);
ALX_ALIAS_WEAK_DEF(timespec_sub_ns,	alx_timespec_sub_ns);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

