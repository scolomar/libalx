/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/strto/strtoi_s.h"

#include <ctype.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


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
//#pragma GCC diagnostic push	/* Over/underflow is explicitly handled */
//#pragma GCC diagnostic ignored	"-Wconversion"

int	alx_strtoi8_s		(int8_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	const int	errno_before = errno;
	char		*endptr;
	long		tmp;

	tmp	= strtol(str, &endptr, base);
	*num	= tmp;
	if (nread)
		*nread	= endptr - str;
	if (tmp < INT8_MIN || tmp > INT8_MAX)
		errno	= ERANGE;

	return	alx_strtol_status(str, endptr, errno, errno_before);
}

int	alx_strtoi16_s		(int16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	const int	errno_before = errno;
	char		*endptr;
	long		tmp;

	errno	= 0;
	tmp	= strtol(str, &endptr, base);
	*num	= tmp;
	if (nread)
		*nread	= endptr - str;
	if (tmp < INT16_MIN || tmp > INT16_MAX)
		errno	= ERANGE;

	return	alx_strtol_status(str, endptr, errno, errno_before);
}

int	alx_strtoi32_s		(int32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	const int	errno_before = errno;
	char		*endptr;
	long		tmp;

	errno	= 0;
	tmp	= strtol(str, &endptr, base);
	*num	= tmp;
	if (nread)
		*nread	= endptr - str;
	if (tmp < INT32_MIN || tmp > INT32_MAX)
		errno	= ERANGE;

	return	alx_strtol_status(str, endptr, errno, errno_before);
}

int	alx_strtoi64_s		(int64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	const int	errno_before = errno;
	char		*endptr;

	errno	= 0;
	*num	= strtol(str, &endptr, base);
	if (nread)
		*nread	= endptr - str;

	return	alx_strtol_status(str, endptr, errno, errno_before);
}
//#pragma GCC diagnostic pop


int	alx_strtol_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before)
{
	int	status;

	status	= 0;

	if (str == endptr) {
		status	= -ECANCELED;
		goto out;
	}

	while (isspace((unsigned char)*endptr))
		endptr++;
	if (*endptr) {
		status	= ENOTSUP;
		goto out;
	}

	if (errno_after == EINVAL) {
		status	= -EINVAL;
		goto out;
	}

	/* should be ERANGE */
	if (errno_after) {
		status	= -errno_after;
		goto out;
	}
out:
	if (!errno)
		errno	= errno_before;

	return	status;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(strtoi8_s,	alx_strtoi8_s);
ALX_ALIAS_WEAK_DEF(strtoi16_s,	alx_strtoi16_s);
ALX_ALIAS_WEAK_DEF(strtoi32_s,	alx_strtoi32_s);
ALX_ALIAS_WEAK_DEF(strtoi64_s,	alx_strtoi64_s);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
