/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distance/chebyshev.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdint.h>

#include <sys/param.h>

#include "libalx/base/compiler/attribute.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::const]]
inline
long double alx_gsl_dist2D_chebyshev_ldbl	(long double dx, long double dy);
[[gnu::const]]
inline
double	alx_gsl_dist2D_chebyshev		(double dx, double dy);
[[gnu::const]]
inline
float	alx_gsl_dist2D_chebyshev_flt		(float dx, float dy);
[[gnu::const]]
inline
float	alx_gsl_dist2D_chebyshev_8b		(int8_t dx, int8_t dy);
[[gnu::const]]
inline
float	alx_gsl_dist2D_chebyshev_16b		(int16_t dx, int16_t dy);
[[gnu::const]]
inline
double	alx_gsl_dist2D_chebyshev_32b		(int32_t dx, int32_t dy);
[[gnu::const]]
inline
long double alx_gsl_dist2D_chebyshev_64b	(int64_t dx, int64_t dy);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(gsl_dist2D_chebyshev_ldbl, alx_gsl_dist2D_chebyshev_ldbl);
ALX_ALIAS_DECLARATION(gsl_dist2D_chebyshev,	 alx_gsl_dist2D_chebyshev);
ALX_ALIAS_DECLARATION(gsl_dist2D_chebyshev_flt,	 alx_gsl_dist2D_chebyshev_flt);
ALX_ALIAS_DECLARATION(gsl_dist2D_chebyshev_8b,	 alx_gsl_dist2D_chebyshev_8b);
ALX_ALIAS_DECLARATION(gsl_dist2D_chebyshev_16b,	 alx_gsl_dist2D_chebyshev_16b);
ALX_ALIAS_DECLARATION(gsl_dist2D_chebyshev_32b,	 alx_gsl_dist2D_chebyshev_32b);
ALX_ALIAS_DECLARATION(gsl_dist2D_chebyshev_64b,	 alx_gsl_dist2D_chebyshev_64b);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double alx_gsl_dist2D_chebyshev_ldbl	(long double dx, long double dy)
{
	return	MAX(dx, dy);
}

inline
double	alx_gsl_dist2D_chebyshev		(double dx, double dy)
{
	return	MAX(dx, dy);
}

inline
float	alx_gsl_dist2D_chebyshev_flt		(float dx, float dy)
{
	return	MAX(dx, dy);
}

inline
float	alx_gsl_dist2D_chebyshev_8b		(int8_t dx, int8_t dy)
{
	return	MAX(dx, dy);
}

inline
float	alx_gsl_dist2D_chebyshev_16b		(int16_t dx, int16_t dy)
{
	return	MAX(dx, dy);
}

inline
double	alx_gsl_dist2D_chebyshev_32b		(int32_t dx, int32_t dy)
{
	return	MAX(dx, dy);
}

inline
long double alx_gsl_dist2D_chebyshev_64b	(int64_t dx, int64_t dy)
{
	return	MAX(dx, dy);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
