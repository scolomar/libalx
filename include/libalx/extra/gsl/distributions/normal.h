/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distributions/normal.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* headers **************************************************************
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
long double	alx_gsl_dist_normal_A_ldbl	(long double o);
__attribute__((const))
double		alx_gsl_dist_normal_A		(double o);
__attribute__((const))
float		alx_gsl_dist_normal_A_flt	(float o);

__attribute__((const))
long double	alx_gsl_dist_normal_B_ldbl	(long double u, long double o);
__attribute__((const))
double		alx_gsl_dist_normal_B		(double u, double o);
__attribute__((const))
float		alx_gsl_dist_normal_B_flt	(float u, float o);

__attribute__((const))
long double	alx_gsl_dist_normal_X2Z_ldbl	(long double a, long double b,
						 long double x);
__attribute__((const))
double		alx_gsl_dist_normal_X2Z		(double a, double b, double x);
__attribute__((const))
float		alx_gsl_dist_normal_X2Z_flt	(float a, float b, float x);

__attribute__((const))
long double	alx_gsl_dist_normal_Z2X_ldbl	(long double a, long double b,
						 long double z);
__attribute__((const))
double		alx_gsl_dist_normal_Z2X		(double a, double b, double z);
__attribute__((const))
float		alx_gsl_dist_normal_Z2X_flt	(float a, float b, float z);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
