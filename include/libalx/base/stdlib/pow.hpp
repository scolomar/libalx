/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/pow.hpp */

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
uint8_t		alx_pow_u8	(uint8_t base, uint8_t exp);
[[gnu::const]]
int8_t		alx_pow_s8	(int8_t base, uint8_t exp);
[[gnu::const]]
uint16_t	alx_pow_u16	(uint16_t base, uint8_t exp);
[[gnu::const]]
int16_t		alx_pow_s16	(int16_t base, uint8_t exp);
[[gnu::const]]
uint32_t	alx_pow_u32	(uint32_t base, uint8_t exp);
[[gnu::const]]
int32_t		alx_pow_s32	(int32_t base, uint8_t exp);
[[gnu::const]]
uint64_t	alx_pow_u64	(uint64_t base, uint8_t exp);
[[gnu::const]]
int64_t		alx_pow_s64	(int64_t base, uint8_t exp);
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
