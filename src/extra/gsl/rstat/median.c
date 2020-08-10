/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/gsl/rstat/median.h"

#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/stdlib/avg.h"
#include "libalx/base/stdlib/cmp.h"


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
long double alx_gsl_rstat_median_ldbl(ptrdiff_t nmemb,
				 const long double arr[static restrict nmemb])
{
	long double	sorted[nmemb];
	long double	median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_ldbl);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= ALX_AVG(sorted[nmemb/2], sorted[nmemb/2 - 1]);

	return	median;
}

float	alx_gsl_rstat_median_flt(ptrdiff_t nmemb,
				 const float arr[static restrict nmemb])
{
	float	sorted[nmemb];
	float	median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_f);

	if (nmemb % 2)
		median = sorted[nmemb/2];
	else
		median = ALX_AVG(sorted[nmemb/2], sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_gsl_rstat_median_uint(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb])
{
	unsigned	sorted[nmemb];
	double		median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_uint);

	if (nmemb % 2)
		median = sorted[nmemb/2];
	else
		median = ALX_AVG((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 -1]);

	return	median;
}

double	alx_gsl_rstat_median_int(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb])
{
	int	sorted[nmemb];
	double	median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_int);

	if (nmemb % 2)
		median = sorted[nmemb/2];
	else
		median = ALX_AVG((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 -1]);

	return	median;
}

double	alx_gsl_rstat_median_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb])
{
	uint8_t	sorted[nmemb];
	double	median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_u8);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= ALX_AVG((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_gsl_rstat_median_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb])
{
	int8_t	sorted[nmemb];
	double	median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_s8);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= ALX_AVG((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_gsl_rstat_median_u16(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb])
{
	uint16_t	sorted[nmemb];
	double		median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_u16);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= ALX_AVG((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_rstat_median_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb])
{
	int16_t	sorted[nmemb];
	double	median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_s16);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= ALX_AVG((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_rgsl_stat_median_u32(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb])
{
	uint32_t	sorted[nmemb];
	double		median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_u32);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= ALX_AVG((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_gsl_rstat_median_s32(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb])
{
	int32_t	sorted[nmemb];
	double	median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_s32);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= ALX_AVG((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

long double alx_gsl_rstat_median_u64(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb])
{
	uint64_t	sorted[nmemb];
	long double	median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_u64);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= ALX_AVG((long double)sorted[nmemb/2],
					(long double)sorted[nmemb/2 - 1]);

	return	median;
}

long double alx_gsl_rstat_median_s64(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb])
{
	int64_t		sorted[nmemb];
	long double	median;

	memcpy(sorted, arr, ARRAY_BYTES(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_cmp_s64);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= ALX_AVG((long double)sorted[nmemb/2],
					(long double)sorted[nmemb/2 - 1]);

	return	median;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_DECLARATION(gsl_rstat_median_ldbl,	alx_gsl_rstat_median_ldbl);
ALX_ALIAS_DECLARATION(gsl_rstat_median_flt,	alx_gsl_rstat_median_flt);
ALX_ALIAS_DECLARATION(gsl_rstat_median_uint,	alx_gsl_rstat_median_uint);
ALX_ALIAS_DECLARATION(gsl_rstat_median_int,	alx_gsl_rstat_median_int);
ALX_ALIAS_DECLARATION(gsl_rstat_median_u8,	alx_gsl_rstat_median_u8);
ALX_ALIAS_DECLARATION(gsl_rstat_median_s8,	alx_gsl_rstat_median_u8);
ALX_ALIAS_DECLARATION(gsl_rstat_median_u16,	alx_gsl_rstat_median_u16);
ALX_ALIAS_DECLARATION(gsl_rstat_median_s16,	alx_gsl_rstat_median_s16);
ALX_ALIAS_DECLARATION(gsl_rstat_median_u32,	alx_gsl_rstat_median_u32);
ALX_ALIAS_DECLARATION(gsl_rstat_median_s32,	alx_gsl_rstat_median_s32);
ALX_ALIAS_DECLARATION(gsl_rstat_median_u64,	alx_gsl_rstat_median_u64);
ALX_ALIAS_DECLARATION(gsl_rstat_median_s64,	alx_gsl_rstat_median_s64);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
