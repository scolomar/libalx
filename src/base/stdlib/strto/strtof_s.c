/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/strto/strtof_s.h"

#include <ctype.h>
#include <errno.h>
#include <stddef.h>
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
int	alx_strtod_s	(double *restrict num, const char *restrict str,
			 ptrdiff_t *restrict nread)
{
	const int	errno_before = errno;
	char		*endptr;

	errno	= 0;
	*num	= strtod(str, &endptr);
	if (nread)
		*nread	= endptr - str;

	return	alx_strtof_status(str, endptr, errno, errno_before);
}

int	alx_strtof_s	(float *restrict num, const char *restrict str,
			 ptrdiff_t *restrict nread)
{
	const int	errno_before = errno;
	char		*endptr;

	errno	= 0;
	*num	= strtof(str, &endptr);
	if (nread)
		*nread	= endptr - str;

	return	alx_strtof_status(str, endptr, errno, errno_before);
}

int	alx_strtold_s	(long double *restrict num, const char *restrict str,
			 ptrdiff_t *restrict nread)
{
	const int	errno_before = errno;
	char		*endptr;

	errno	= 0;
	*num	= strtold(str, &endptr);
	if (nread)
		*nread	= endptr - str;

	return	alx_strtof_status(str, endptr, errno, errno_before);
}


extern
int	alx_strtof_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_WEAK_DEFINITION(strtod_s,	alx_strtod_s);
ALX_ALIAS_WEAK_DEFINITION(strtof_s,	alx_strtof_s);
ALX_ALIAS_WEAK_DEFINITION(strtold_s,	alx_strtold_s);
#endif


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
