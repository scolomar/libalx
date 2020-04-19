/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/math/binomial_coefficient.h"

#include <errno.h>
#include <math.h>
#include <stdint.h>

#include "libalx/base/math/pascal_triangle.h"
#include "libalx/base/math/prime.h"


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
long double alx_binomial_coefficient_ldbl	(int32_t n, int32_t k)
{

	if ((n < 0) || (k < 0)) {
		errno	= EDOM;
		return	nanl("");
	}
	if (k > n)
		return	0;
	if ((n == k) || (!k))
		return	1;
	if (k == 1)
		return	n;

	return	alx_pascal_triangle_ldbl(n, k);
}

double	alx_binomial_coefficient		(int16_t n, int16_t k)
{

	if ((n < 0) || (k < 0)) {
		errno	= EDOM;
		return	nan("");
	}
	if (k > n)
		return	0;
	if ((n == k) || (!k))
		return	1;
	if (k == 1)
		return	n;

	return	alx_pascal_triangle(n, k);
}

float	alx_binomial_coefficient_flt		(int16_t n, int16_t k)
{

	if ((n < 0) || (k < 0)) {
		errno	= EDOM;
		return	nanf("");
	}
	if (k > n)
		return	0;
	if ((n == k) || (!k))
		return	1;
	if (k == 1)
		return	n;

	return	alx_pascal_triangle_flt(n, k);
}

int	alx_binomial_coefficient_factorized	(int16_t n, int16_t k,
				int16_t pf[static restrict PRIME_NUMS_QTY_16b])
{

	if ((n < 0) || (k < 0)) {
		errno	= EDOM;
		return	-EDOM;
	}
	if (k > n) {
		errno	= EDOM;
		return	-EDOM;
	}
	if ((n == k) || (!k))
		return	0;

	return	alx_pascal_triangle_factorized(n, k, pf);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
