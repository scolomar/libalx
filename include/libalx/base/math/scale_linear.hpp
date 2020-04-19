/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/math/scale_linear.hpp */

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


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::const]]
long double	scale_linear_ldbl(long double input,
				  long double in_lo, long double in_hi,
				  long double out_lo, long double out_hi);
[[gnu::const]]
double		scale_linear	(double input,
				 double in_lo, double in_hi,
				 double out_lo, double out_hi);
[[gnu::const]]
float		scale_linear_flt(float input,
				 float in_lo, float in_hi,
				 float out_lo, float out_hi);
[[gnu::const]]
unsigned	scale_linear_uint(unsigned input,
				  unsigned in_lo, unsigned in_hi,
				  unsigned out_lo, unsigned out_hi);
[[gnu::const]]
int		scale_linear_int(int input,
				 int in_lo, int in_hi,
				 int out_lo, int out_hi);
[[gnu::const]]
uint8_t		scale_linear_u8	(uint8_t input,
				 uint8_t in_lo, uint8_t in_hi,
				 uint8_t out_lo, uint8_t out_hi);
[[gnu::const]]
int8_t		scale_linear_s8	(int8_t input,
				 int8_t in_lo, int8_t in_hi,
				 int8_t out_lo, int8_t out_hi);
[[gnu::const]]
uint16_t	scale_linear_u16(uint16_t input,
				 uint16_t in_lo, uint16_t in_hi,
				 uint16_t out_lo, uint16_t out_hi);
[[gnu::const]]
int16_t		scale_linear_s16(int16_t input,
				 int16_t in_lo, int16_t in_hi,
				 int16_t out_lo, int16_t out_hi);
[[gnu::const]]
uint32_t	scale_linear_u32(uint32_t input,
				 uint32_t in_lo, uint32_t in_hi,
				 uint32_t out_lo, uint32_t out_hi);
[[gnu::const]]
int32_t		scale_linear_s32(int32_t input,
				 int32_t in_lo, int32_t in_hi,
				 int32_t out_lo, int32_t out_hi);
[[gnu::const]]
uint64_t	scale_linear_u64(uint64_t input,
				 uint64_t in_lo, uint64_t in_hi,
				 uint64_t out_lo, uint64_t out_hi);
[[gnu::const]]
int64_t		scale_linear_s64(int64_t input,
				 int64_t in_lo, int64_t in_hi,
				 int64_t out_lo, int64_t out_hi);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


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
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
