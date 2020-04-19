/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distance/manhattan.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdint>


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define distance2D_manhattan_ldbl(dx, dy)				\
	alx_gsl_distance2D_manhattan_ldbl(dx, dy)
#define distance2D_manhattan(dx, dy)					\
	alx_gsl_distance2D_manhattan(dx, dy)
#define distance2D_manhattan_flt(dx, dy)				\
	alx_gsl_distance2D_manhattan_flt(dx, dy)
#define distance2D_manhattan_8b(dx, dy)					\
	alx_gsl_distance2D_manhattan_8b(dx, dy)
#define distance2D_manhattan_16b(dx, dy)				\
	alx_gsl_distance2D_manhattan_16b(dx, dy)
#define distance2D_manhattan_32b(dx, dy)				\
	alx_gsl_distance2D_manhattan_32b(dx, dy)
#define distance2D_manhattan_64b(dx, dy)				\
	alx_gsl_distance2D_manhattan_64b(dx, dy)
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::const]]
long double alx_gsl_distance2D_manhattan_ldbl	(long double dx, long double dy);
[[gnu::const]]
double	alx_gsl_distance2D_manhattan		(double dx, double dy);
[[gnu::const]]
float	alx_gsl_distance2D_manhattan_flt	(float dx, float dy);
[[gnu::const]]
float	alx_gsl_distance2D_manhattan_8b		(int8_t dx, int8_t dy);
[[gnu::const]]
float	alx_gsl_distance2D_manhattan_16b	(int16_t dx, int16_t dy);
[[gnu::const]]
double	alx_gsl_distance2D_manhattan_32b	(int32_t dx, int32_t dy);
[[gnu::const]]
long double alx_gsl_distance2D_manhattan_64b	(int64_t dx, int64_t dy);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace gsl {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace gsl */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
