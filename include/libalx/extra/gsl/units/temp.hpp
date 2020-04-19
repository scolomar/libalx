/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/units/temp.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::const]]
long double	alx_gsl_units_K_to_C_ldbl	(long double k);
[[gnu::const]]
double		alx_gsl_units_K_to_C		(double k);
[[gnu::const]]
float		alx_gsl_units_K_to_C_flt	(float k);

[[gnu::const]]
long double	alx_gsl_units_C_to_K_ldbl	(long double c);
[[gnu::const]]
double		alx_gsl_units_C_to_K		(double c);
[[gnu::const]]
float		alx_gsl_units_C_to_K_flt	(float c);

[[gnu::const]]
long double	alx_gsl_units_K_to_F_ldbl	(long double k);
[[gnu::const]]
double		alx_gsl_units_K_to_F		(double k);
[[gnu::const]]
float		alx_gsl_units_K_to_F_flt	(float k);

[[gnu::const]]
long double	alx_gsl_units_F_to_K_ldbl	(long double f);
[[gnu::const]]
double		alx_gsl_units_F_to_K		(double f);
[[gnu::const]]
float		alx_gsl_units_F_to_K_flt	(float f);

[[gnu::const]]
long double	alx_gsl_units_K_to_R_ldbl	(long double k);
[[gnu::const]]
double		alx_gsl_units_K_to_R		(double k);
[[gnu::const]]
float		alx_gsl_units_K_to_R_flt	(float k);

[[gnu::const]]
long double	alx_gsl_units_R_to_K_ldbl	(long double r);
[[gnu::const]]
double		alx_gsl_units_R_to_K		(double r);
[[gnu::const]]
float		alx_gsl_units_R_to_K_flt	(float r);
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
