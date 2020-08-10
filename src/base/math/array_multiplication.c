/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/math/array_multiplication.h"

#include <errno.h>
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
extern
void	alx_array_multiplication_ldbl	(ptrdiff_t nmemb,
					 long double dest[static nmemb],
					 const long double src1[static nmemb],
					 const long double src2[static nmemb]);
extern
void	alx_array_multiplication	(ptrdiff_t nmemb,
					 double dest[static nmemb],
					 const double src1[static nmemb],
					 const double src2[static nmemb]);
extern
void	alx_array_multiplication_flt	(ptrdiff_t nmemb,
					 float dest[static nmemb],
					 const float src1[static nmemb],
					 const float src2[static nmemb]);

int	alx_array_multiplication_uint	(ptrdiff_t nmemb,
					 unsigned dest[static nmemb],
					 const unsigned src1[static nmemb],
					 const unsigned src2[static nmemb])
{
	double_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (double_t)src1[i] * (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > UINT_MAX)
			goto ovf;
		dest[i]	= src1[i] * src2[i];
	}

	return	0;
ovf:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_multiplication_int	(ptrdiff_t nmemb,
					 int dest[static nmemb],
					 const int src1[static nmemb],
					 const int src2[static nmemb])
{
	double_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (double_t)src1[i] * (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > INT_MAX)
			goto ovf;
		if (nextafter(tmp, tmp - 1) < INT_MIN)
			goto ovf;
		dest[i]	= src1[i] * src2[i];
	}

	return	0;
ovf:
	errno	= ERANGE;
	return	-1;
}

//#pragma GCC diagnostic push	/* Over(/under)flow is explicitly handled */
//#pragma GCC diagnostic ignored	"-Wconversion"
int	alx_array_multiplication_u8	(ptrdiff_t nmemb,
					 uint8_t dest[static nmemb],
					 const uint8_t src1[static nmemb],
					 const uint8_t src2[static nmemb])
{
	uint_fast16_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (uint_fast16_t)src1[i] * (uint_fast16_t)src2[i];
		if (tmp > UINT8_MAX)
			goto ovf;
		dest[i]	= tmp;
	}

	return	0;
ovf:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_multiplication_s8	(ptrdiff_t nmemb,
					 int8_t dest[static nmemb],
					 const int8_t src1[static nmemb],
					 const int8_t src2[static nmemb])
{
	int_fast16_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (int_fast16_t)src1[i] * (int_fast16_t)src2[i];
		if (tmp > INT8_MAX)
			goto ovf;
		if (tmp < INT8_MIN)
			goto ovf;
		dest[i]	= tmp;
	}

	return	0;
ovf:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_multiplication_u16	(ptrdiff_t nmemb,
					 uint16_t dest[static nmemb],
					 const uint16_t src1[static nmemb],
					 const uint16_t src2[static nmemb])
{
	uint_fast32_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (uint_fast32_t)src1[i] * (uint_fast32_t)src2[i];
		if (tmp > UINT16_MAX)
			goto ovf;
		dest[i]	= tmp;
	}

	return	0;
ovf:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_multiplication_s16	(ptrdiff_t nmemb,
					 int16_t dest[static nmemb],
					 const int16_t src1[static nmemb],
					 const int16_t src2[static nmemb])
{
	int_fast32_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (int_fast32_t)src1[i] * (int_fast32_t)src2[i];
		if (tmp > INT16_MAX)
			goto ovf;
		if (tmp < INT16_MIN)
			goto ovf;
		dest[i]	= tmp;
	}

	return	0;
ovf:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_multiplication_u32	(ptrdiff_t nmemb,
					 uint32_t dest[static nmemb],
					 const uint32_t src1[static nmemb],
					 const uint32_t src2[static nmemb])
{
	uint_fast64_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (uint_fast64_t)src1[i] * (uint_fast64_t)src2[i];
		if (tmp > UINT32_MAX)
			goto ovf;
		dest[i]	= tmp;
	}

	return	0;
ovf:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_multiplication_s32	(ptrdiff_t nmemb,
					 int32_t dest[static nmemb],
					 const int32_t src1[static nmemb],
					 const int32_t src2[static nmemb])
{
	int_fast64_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (int_fast64_t)src1[i] * (int_fast64_t)src2[i];
		if (tmp > INT32_MAX)
			goto ovf;
		if (tmp < INT32_MIN)
			goto ovf;
		dest[i]	= tmp;
	}

	return	0;
ovf:
	errno	= ERANGE;
	return	-1;
}
//#pragma GCC diagnostic pop

int	alx_array_multiplication_u64	(ptrdiff_t nmemb,
					 uint64_t dest[static nmemb],
					 const uint64_t src1[static nmemb],
					 const uint64_t src2[static nmemb])
{
	double_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (double_t)src1[i] * (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > UINT64_MAX)
			goto ovf;
		dest[i]	= src1[i] * src2[i];
	}

	return	0;
ovf:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_multiplication_s64	(ptrdiff_t nmemb,
					 int64_t dest[static nmemb],
					 const int64_t src1[static nmemb],
					 const int64_t src2[static nmemb])
{
	double_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (double_t)src1[i] * (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > INT64_MAX)
			goto ovf;
		if (nextafter(tmp, tmp - 1) < INT64_MIN)
			goto ovf;
		dest[i]	= src1[i] * src2[i];
	}

	return	0;
ovf:
	errno	= ERANGE;
	return	-1;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
