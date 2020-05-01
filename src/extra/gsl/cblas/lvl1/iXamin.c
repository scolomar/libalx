/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/gsl/cblas/lvl1/iXamin.h"

#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>


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
ptrdiff_t alx_cblas_iXamin_ldbl	(ptrdiff_t nmemb,
				 const long double arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	long double	val;

	pos	= 0;
	val	= INFINITY;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamin_uint	(ptrdiff_t nmemb,
				 const unsigned arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	unsigned	val;

	pos	= 0;
	val	= UINT_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamin_int	(ptrdiff_t nmemb,
				 const int arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	int		val;

	pos	= 0;
	val	= INT_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamin_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	uint_fast8_t	val;

	pos	= 0;
	val	= UINT8_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamin_s8	(ptrdiff_t nmemb,
				 const int8_t arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	int_fast8_t	val;

	pos	= 0;
	val	= INT8_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamin_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	uint_fast16_t	val;

	pos	= 0;
	val	= UINT16_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamin_s16	(ptrdiff_t nmemb,
				 const int16_t arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	int_fast16_t	val;

	pos	= 0;
	val	= INT16_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamin_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	uint_fast32_t	val;

	pos	= 0;
	val	= UINT32_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamin_s32	(ptrdiff_t nmemb,
				 const int32_t arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	int_fast32_t	val;

	pos	= 0;
	val	= INT32_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamin_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	uint_fast64_t	val;

	pos	= 0;
	val	= UINT64_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamin_s64	(ptrdiff_t nmemb,
				 const int64_t arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	int_fast64_t	val;

	pos	= 0;
	val	= INT64_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamin_pdif	(ptrdiff_t nmemb,
				 const ptrdiff_t arr[restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	ptrdiff_t	val;

	pos	= 0;
	val	= PTRDIFF_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] <= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(cblas_iXamin_ldbl,	alx_cblas_iXamin_ldbl);
ALX_ALIAS_WEAK_DEF(cblas_iXamin_uint,	alx_cblas_iXamin_uint);
ALX_ALIAS_WEAK_DEF(cblas_iXamin_int,	alx_cblas_iXamin_int);
ALX_ALIAS_WEAK_DEF(cblas_iXamin_u8,	alx_cblas_iXamin_u8);
ALX_ALIAS_WEAK_DEF(cblas_iXamin_s8,	alx_cblas_iXamin_s8);
ALX_ALIAS_WEAK_DEF(cblas_iXamin_u16,	alx_cblas_iXamin_u16);
ALX_ALIAS_WEAK_DEF(cblas_iXamin_s16,	alx_cblas_iXamin_s16);
ALX_ALIAS_WEAK_DEF(cblas_iXamin_u32,	alx_cblas_iXamin_u32);
ALX_ALIAS_WEAK_DEF(cblas_iXamin_s32,	alx_cblas_iXamin_s32);
ALX_ALIAS_WEAK_DEF(cblas_iXamin_u64,	alx_cblas_iXamin_u64);
ALX_ALIAS_WEAK_DEF(cblas_iXamin_s64,	alx_cblas_iXamin_s64);
ALX_ALIAS_WEAK_DEF(cblas_iXamin_pdif,	alx_cblas_iXamin_pdif);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
