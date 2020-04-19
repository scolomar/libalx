/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/units/len.hpp */

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
#define ALX_GSL_UNITS_ft_TO_m_LDBL	(0.3048L)
#define ALX_GSL_UNITS_ft_TO_m		(0.3048)
#define ALX_GSL_UNITS_ft_TO_m_FLT	(0.3048f)


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::const]]
long double	alx_gsl_units_m_to_ft_ldbl	(long double m);
[[gnu::const]]
double		alx_gsl_units_m_to_ft		(double m);
[[gnu::const]]
float		alx_gsl_units_m_to_ft_flt	(float m);

[[gnu::const]]
long double	alx_gsl_units_ft_to_m_ldbl	(long double ft);
[[gnu::const]]
double		alx_gsl_units_ft_to_m		(double ft);
[[gnu::const]]
float		alx_gsl_units_ft_to_m_flt	(float ft);
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
