/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/strto/strtou_s.h"

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
int	alx_strtou8_s		(uint8_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	const int	errno_before = errno;
	char		*endptr;
	unsigned long	tmp;

	errno	= 0;
	tmp	= strtoul(str, &endptr, base);
	*num	= tmp;
	if (nread)
		*nread	= endptr - str;
	if (tmp > UINT8_MAX)
		errno	= ERANGE;

	return	alx_strtoul_status(str, endptr, errno, errno_before);
}

int	alx_strtou16_s		(uint16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	const int	errno_before = errno;
	char		*endptr;
	unsigned long	tmp;

	errno	= 0;
	tmp	= strtoul(str, &endptr, base);
	*num	= tmp;
	if (nread)
		*nread	= endptr - str;
	if (tmp > UINT16_MAX)
		errno	= ERANGE;

	return	alx_strtoul_status(str, endptr, errno, errno_before);
}

int	alx_strtou32_s		(uint32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	const int	errno_before = errno;
	char		*endptr;
	unsigned long	tmp;

	errno	= 0;
	tmp	= strtoul(str, &endptr, base);
	*num	= tmp;
	if (nread)
		*nread	= endptr - str;
	if (tmp > UINT32_MAX)
		errno	= ERANGE;

	return	alx_strtoul_status(str, endptr, errno, errno_before);
}

int	alx_strtou64_s		(uint64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	const int	errno_before = errno;
	char		*endptr;

	errno	= 0;
	*num	= strtoul(str, &endptr, base);
	if (nread)
		*nread	= endptr - str;

	return	alx_strtoul_status(str, endptr, errno, errno_before);
}
//#pragma GCC diagnostic pop


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(strtou8_s,	alx_strtou8_s);
ALX_ALIAS_WEAK_DEF(strtou16_s,	alx_strtou16_s);
ALX_ALIAS_WEAK_DEF(strtou32_s,	alx_strtou32_s);
ALX_ALIAS_WEAK_DEF(strtou64_s,	alx_strtou64_s);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
