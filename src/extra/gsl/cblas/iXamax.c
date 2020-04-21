/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/gsl/cblas/iXamax.h"

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
ptrdiff_t alx_cblas_iXamax_ldbl	(ptrdiff_t nmemb,
				 const long double arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	long double	val;

	pos	= 0;
	val	= -INFINITY;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_f	(ptrdiff_t nmemb,
				 const float arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	float		val;

	pos	= 0;
	val	= -INFINITY;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_uint	(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	unsigned	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_int	(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	int		val;

	pos	= 0;
	val	= INT_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	uint_fast8_t	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	int_fast8_t	val;

	pos	= 0;
	val	= INT8_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	uint_fast16_t	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	int_fast16_t	val;

	pos	= 0;
	val	= INT16_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	uint_fast32_t	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	int_fast32_t	val;

	pos	= 0;
	val	= INT32_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	uint_fast64_t	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_s64	(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	int_fast64_t	val;

	pos	= 0;
	val	= INT64_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t alx_cblas_iXamax_pdif	(ptrdiff_t nmemb,
				 const ptrdiff_t arr[static restrict nmemb],
				 ptrdiff_t step)
{
	ptrdiff_t	pos;
	ptrdiff_t	val;

	pos	= 0;
	val	= PTRDIFF_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i * step] >= val) {
			val	= arr[i * step];
			pos	= i;
		}
	}

	return	pos;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_ldbl,	alx_cblas_iXamax_ldbl);
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_uint,	alx_cblas_iXamax_uint);
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_int,	alx_cblas_iXamax_int);
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_u8,	alx_cblas_iXamax_u8);
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_s8,	alx_cblas_iXamax_s8);
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_u16,	alx_cblas_iXamax_u16);
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_s16,	alx_cblas_iXamax_s16);
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_u32,	alx_cblas_iXamax_u32);
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_s32,	alx_cblas_iXamax_s32);
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_u64,	alx_cblas_iXamax_u64);
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_s64,	alx_cblas_iXamax_s64);
ALX_ALIAS_WEAK_DEFINITION(cblas_iXamax_pdif,	alx_cblas_iXamax_pdif);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
