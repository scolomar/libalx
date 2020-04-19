/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distance/euclidean.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <math.h>
#include <stdint.h>


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
__attribute__((const))
inline
long double alx_gsl_distance2D_euclidean_ldbl	(long double dx, long double dy);
__attribute__((const))
inline
double	alx_gsl_distance2D_euclidean		(double dx, double dy);
__attribute__((const))
inline
float	alx_gsl_distance2D_euclidean_flt	(float dx, float dy);
__attribute__((const))
inline
float	alx_gsl_distance2D_euclidean_8b		(int8_t dx, int8_t dy);
__attribute__((const))
inline
float	alx_gsl_distance2D_euclidean_16b	(int16_t dx, int16_t dy);
__attribute__((const))
inline
double	alx_gsl_distance2D_euclidean_32b	(int32_t dx, int32_t dy);
__attribute__((const))
inline
long double alx_gsl_distance2D_euclidean_64b	(int64_t dx, int64_t dy);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double alx_gsl_distance2D_euclidean_ldbl	(long double dx, long double dy)
{
	const long double	dx2	= dx * dx;
	const long double	dy2	= dy * dy;

	return	sqrtl(dx2 + dy2);
}

inline
double	alx_gsl_distance2D_euclidean		(double dx, double dy)
{
	const double_t	dx_	= dx;
	const double_t	dy_	= dy;
	const double_t	dx2	= dx_ * dx_;
	const double_t	dy2	= dy_ * dy_;

	return	sqrt(dx2 + dy2);
}

inline
float	alx_gsl_distance2D_euclidean_flt	(float dx, float dy)
{
	const float_t	dx_	= dx;
	const float_t	dy_	= dy;
	const float_t	dx2	= dx_ * dx_;
	const float_t	dy2	= dy_ * dy_;

	return	sqrtf(dx2 + dy2);
}

inline
float	alx_gsl_distance2D_euclidean_8b		(int8_t dx, int8_t dy)
{
	const float_t	dx_	= dx;
	const float_t	dy_	= dy;
	const float_t	dx2	= dx_ * dx_;
	const float_t	dy2	= dy_ * dy_;

	return	sqrtf(dx2 + dy2);
}

inline
float	alx_gsl_distance2D_euclidean_16b	(int16_t dx, int16_t dy)
{
	const float_t	dx_	= dx;
	const float_t	dy_	= dy;
	const float_t	dx2	= dx_ * dx_;
	const float_t	dy2	= dy_ * dy_;

	return	sqrtf(dx2 + dy2);
}

inline
double	alx_gsl_distance2D_euclidean_32b	(int32_t dx, int32_t dy)
{
	const double_t	dx_	= dx;
	const double_t	dy_	= dy;
	const double_t	dx2	= dx_ * dx_;
	const double_t	dy2	= dy_ * dy_;

	return	sqrt(dx2 + dy2);
}

inline
long double alx_gsl_distance2D_euclidean_64b	(int64_t dx, int64_t dy)
{
	const long double	dx_	= dx;
	const long double	dy_	= dy;
	const long double	dx2	= dx_ * dx_;
	const long double	dy2	= dy_ * dy_;

	return	sqrtl(dx2 + dy2);
}


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, const))
long double distance2D_euclidean_ldbl	(long double dx, long double dy)
{
	return	alx_gsl_distance2D_euclidean_ldbl(dx, dy);
}

__attribute__((always_inline, const))
double	distance2D_euclidean		(double dx, double dy)
{
	return	alx_gsl_distance2D_euclidean(dx, dy);
}

__attribute__((always_inline, const))
float	distance2D_euclidean_flt	(float dx, float dy)
{
	return	alx_gsl_distance2D_euclidean_flt(dx, dy);
}

__attribute__((always_inline, const))
float	distance2D_euclidean_8b		(int8_t dx, int8_t dy)
{
	return	alx_gsl_distance2D_euclidean_8b(dx, dy);
}

__attribute__((always_inline, const))
float	distance2D_euclidean_16b	(int16_t dx, int16_t dy)
{
	return	alx_gsl_distance2D_euclidean_16b(dx, dy);
}

__attribute__((always_inline, const))
double	distance2D_euclidean_32b	(int32_t dx, int32_t dy)
{
	return	alx_gsl_distance2D_euclidean_32b(dx, dy);
}

__attribute__((always_inline, const))
long double distance2D_euclidean_64b	(int64_t dx, int64_t dy)
{
	return	alx_gsl_distance2D_euclidean_64b(dx, dy);
}
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
