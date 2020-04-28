/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/bsearch.h"

#include <stddef.h>
#include <stdint.h>

#include "libalx/base/stdlib/avg.h"


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
#pragma GCC diagnostic push	/* Overflow is avoided with a wide cast */
#pragma GCC diagnostic ignored	"-Wsign-conversion"
ptrdiff_t	alx_bsearch_uint(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb],
				 unsigned x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= nmemb;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= ALX_AVG((size_t)lim_lo, (size_t)lim_hi);
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_bsearch_int	(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb],
				 int x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= nmemb;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= ALX_AVG((size_t)lim_lo, (size_t)lim_hi);
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_bsearch_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb],
				 uint8_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= nmemb;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= ALX_AVG((size_t)lim_lo, (size_t)lim_hi);
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_bsearch_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb],
				 int8_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= nmemb;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= ALX_AVG((size_t)lim_lo, (size_t)lim_hi);
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_bsearch_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb],
				 uint16_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= nmemb;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= ALX_AVG((size_t)lim_lo, (size_t)lim_hi);
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_bsearch_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb],
				 int16_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= nmemb;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= ALX_AVG((size_t)lim_lo, (size_t)lim_hi);
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_bsearch_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb],
				 uint32_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= nmemb;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= ALX_AVG((size_t)lim_lo, (size_t)lim_hi);
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_bsearch_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb],
				 int32_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= nmemb;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= ALX_AVG((size_t)lim_lo, (size_t)lim_hi);
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_bsearch_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb],
				 uint64_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= nmemb;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= ALX_AVG((size_t)lim_lo, (size_t)lim_hi);
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_bsearch_s64	(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb],
				 int64_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= nmemb;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= ALX_AVG((size_t)lim_lo, (size_t)lim_hi);
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}
#pragma GCC diagnostic pop


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_WEAK_DEF(bsearch_uint,	alx_bsearch_uint);
ALX_ALIAS_WEAK_DEF(bsearch_int,	alx_bsearch_int);
ALX_ALIAS_WEAK_DEF(bsearch_u8,	alx_bsearch_u8);
ALX_ALIAS_WEAK_DEF(bsearch_s8,	alx_bsearch_s8);
ALX_ALIAS_WEAK_DEF(bsearch_u16,	alx_bsearch_u16);
ALX_ALIAS_WEAK_DEF(bsearch_s16,	alx_bsearch_s16);
ALX_ALIAS_WEAK_DEF(bsearch_u32,	alx_bsearch_u32);
ALX_ALIAS_WEAK_DEF(bsearch_s32,	alx_bsearch_s32);
ALX_ALIAS_WEAK_DEF(bsearch_u64,	alx_bsearch_u64);
ALX_ALIAS_WEAK_DEF(bsearch_s64,	alx_bsearch_s64);
#endif


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
