/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distance/chebyshev.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdint.h>

#include "libalx/base/stdlib/maximum.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* macros ***************************************************************
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
__attribute__((const))
inline
long double alx_gsl_distance2D_chebyshev_ldbl	(long double dx, long double dy);
__attribute__((const))
inline
double	alx_gsl_distance2D_chebyshev		(double dx, double dy);
__attribute__((const))
inline
float	alx_gsl_distance2D_chebyshev_flt	(float dx, float dy);
__attribute__((const))
inline
float	alx_gsl_distance2D_chebyshev_8b		(int8_t dx, int8_t dy);
__attribute__((const))
inline
float	alx_gsl_distance2D_chebyshev_16b	(int16_t dx, int16_t dy);
__attribute__((const))
inline
double	alx_gsl_distance2D_chebyshev_32b	(int32_t dx, int32_t dy);
__attribute__((const))
inline
long double alx_gsl_distance2D_chebyshev_64b	(int64_t dx, int64_t dy);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double alx_gsl_distance2D_chebyshev_ldbl	(long double dx, long double dy)
{
	return	ALX_MAX(dx, dy);
}

inline
double	alx_gsl_distance2D_chebyshev		(double dx, double dy)
{
	return	ALX_MAX(dx, dy);
}

inline
float	alx_gsl_distance2D_chebyshev_flt	(float dx, float dy)
{
	return	ALX_MAX(dx, dy);
}

inline
float	alx_gsl_distance2D_chebyshev_8b		(int8_t dx, int8_t dy)
{
	return	ALX_MAX(dx, dy);
}

inline
float	alx_gsl_distance2D_chebyshev_16b	(int16_t dx, int16_t dy)
{
	return	ALX_MAX(dx, dy);
}

inline
double	alx_gsl_distance2D_chebyshev_32b	(int32_t dx, int32_t dy)
{
	return	ALX_MAX(dx, dy);
}

inline
long double alx_gsl_distance2D_chebyshev_64b	(int64_t dx, int64_t dy)
{
	return	ALX_MAX(dx, dy);
}


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, const))
long double distance2D_chebyshev_ldbl	(long double dx, long double dy)
{
	return	alx_gsl_distance2D_chebyshev_ldbl(dx, dy);
}

__attribute__((always_inline, const))
double	distance2D_chebyshev		(double dx, double dy)
{
	return	alx_gsl_distance2D_chebyshev(dx, dy);
}

__attribute__((always_inline, const))
float	distance2D_chebyshev_flt	(float dx, float dy)
{
	return	alx_gsl_distance2D_chebyshev_flt(dx, dy);
}

__attribute__((always_inline, const))
float	distance2D_chebyshev_8b		(int8_t dx, int8_t dy)
{
	return	alx_gsl_distance2D_chebyshev_8b(dx, dy);
}

__attribute__((always_inline, const))
float	distance2D_chebyshev_16b	(int16_t dx, int16_t dy)
{
	return	alx_gsl_distance2D_chebyshev_16b(dx, dy);
}

__attribute__((always_inline, const))
double	distance2D_chebyshev_32b	(int32_t dx, int32_t dy)
{
	return	alx_gsl_distance2D_chebyshev_32b(dx, dy);
}

__attribute__((always_inline, const))
long double distance2D_chebyshev_64b	(int64_t dx, int64_t dy)
{
	return	alx_gsl_distance2D_chebyshev_64b(dx, dy);
}
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
