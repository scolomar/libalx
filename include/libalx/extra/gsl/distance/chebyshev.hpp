/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distance/chebyshev.hpp */

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
#define distance2D_chebyshev_ldbl(dx, dy)				\
	alx_gsl_distance2D_chebyshev_ldbl(dx, dy)
#define distance2D_chebyshev(dx, dy)					\
	alx_gsl_distance2D_chebyshev(dx, dy)
#define distance2D_chebyshev_flt(dx, dy)				\
	alx_gsl_distance2D_chebyshev_flt(dx, dy)
#define distance2D_chebyshev_8b(dx, dy)					\
	alx_gsl_distance2D_chebyshev_8b(dx, dy)
#define distance2D_chebyshev_16b(dx, dy)				\
	alx_gsl_distance2D_chebyshev_16b(dx, dy)
#define distance2D_chebyshev_32b(dx, dy)				\
	alx_gsl_distance2D_chebyshev_32b(dx, dy)
#define distance2D_chebyshev_64b(dx, dy)				\
	alx_gsl_distance2D_chebyshev_64b(dx, dy)
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::const]]
long double alx_gsl_distance2D_chebyshev_ldbl	(long double dx, long double dy);
[[gnu::const]]
double	alx_gsl_distance2D_chebyshev		(double dx, double dy);
[[gnu::const]]
float	alx_gsl_distance2D_chebyshev_flt	(float dx, float dy);
[[gnu::const]]
float	alx_gsl_distance2D_chebyshev_8b		(int8_t dx, int8_t dy);
[[gnu::const]]
float	alx_gsl_distance2D_chebyshev_16b	(int16_t dx, int16_t dy);
[[gnu::const]]
double	alx_gsl_distance2D_chebyshev_32b	(int32_t dx, int32_t dy);
[[gnu::const]]
long double alx_gsl_distance2D_chebyshev_64b	(int64_t dx, int64_t dy);
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
