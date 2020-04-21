/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distance/manhattan.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
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
long double alx_gsl_dist2D_manhattan_ldbl	(long double dx, long double dy);
__attribute__((const))
inline
double	alx_gsl_dist2D_manhattan		(double dx, double dy);
__attribute__((const))
inline
float	alx_gsl_dist2D_manhattan_flt		(float dx, float dy);
__attribute__((const))
inline
float	alx_gsl_dist2D_manhattan_8b		(int8_t dx, int8_t dy);
__attribute__((const))
inline
float	alx_gsl_dist2D_manhattan_16b		(int16_t dx, int16_t dy);
__attribute__((const))
inline
double	alx_gsl_dist2D_manhattan_32b		(int32_t dx, int32_t dy);
__attribute__((const))
inline
long double alx_gsl_dist2D_manhattan_64b	(int64_t dx, int64_t dy);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double alx_gsl_dist2D_manhattan_ldbl	(long double dx, long double dy)
{
	return	dx + dy;
}

inline
double	alx_gsl_dist2D_manhattan		(double dx, double dy)
{
	return	dx + dy;
}

inline
float	alx_gsl_dist2D_manhattan_flt		(float dx, float dy)
{
	return	dx + dy;
}

inline
float	alx_gsl_dist2D_manhattan_8b		(int8_t dx, int8_t dy)
{
	return	dx + dy;
}

inline
float	alx_gsl_dist2D_manhattan_16b		(int16_t dx, int16_t dy)
{
	return	dx + dy;
}

inline
double	alx_gsl_dist2D_manhattan_32b		(int32_t dx, int32_t dy)
{
	return	dx + dy;
}

inline
long double alx_gsl_dist2D_manhattan_64b	(int64_t dx, int64_t dy)
{
	return	dx + dy;
}


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, const))
long double dist2D_manhattan_ldbl	(long double dx, long double dy)
{
	return	alx_gsl_dist2D_manhattan_ldbl(dx, dy);
}

__attribute__((always_inline, const))
double	dist2D_manhattan		(double dx, double dy)
{
	return	alx_gsl_dist2D_manhattan(dx, dy);
}

__attribute__((always_inline, const))
float	dist2D_manhattan_flt	(float dx, float dy)
{
	return	alx_gsl_dist2D_manhattan_flt(dx, dy);
}

__attribute__((always_inline, const))
float	dist2D_manhattan_8b		(int8_t dx, int8_t dy)
{
	return	alx_gsl_dist2D_manhattan_8b(dx, dy);
}

__attribute__((always_inline, const))
float	dist2D_manhattan_16b	(int16_t dx, int16_t dy)
{
	return	alx_gsl_dist2D_manhattan_16b(dx, dy);
}

__attribute__((always_inline, const))
double	dist2D_manhattan_32b	(int32_t dx, int32_t dy)
{
	return	alx_gsl_dist2D_manhattan_32b(dx, dy);
}

__attribute__((always_inline, const))
long double dist2D_manhattan_64b	(int64_t dx, int64_t dy)
{
	return	alx_gsl_dist2D_manhattan_64b(dx, dy);
}
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
