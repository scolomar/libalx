/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/clz.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdint>

#include "libalx/base/compiler/attribute.hpp"
#include "libalx/base/stdint/types.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::const]]
uint8_t		alx_clz_u8	(uint8_t n);
[[gnu::const]]
uint16_t	alx_clz_u16	(uint16_t n);
[[gnu::const]]
uint32_t	alx_clz_u32	(uint32_t n);
[[gnu::const]]
uint64_t	alx_clz_u64	(uint64_t n);
[[gnu::const]]
#if defined(uint128_t)
[[gnu::const]]
uint64_t	alx_clz_u128	(uint128_t n);
#endif
#if defined(uint256_t)
[[gnu::const]]
uint64_t	alx_clz_u256	(uint256_t n);
#endif
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
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(clz_u8,	alx_clz_u8);
ALX_ALIAS_DECLARATION(clz_u16,	alx_clz_u16);
ALX_ALIAS_DECLARATION(clz_u32,	alx_clz_u32);
ALX_ALIAS_DECLARATION(clz_u64,	alx_clz_u64);
# if defined(uint128_t)
ALX_ALIAS_DECLARATION(clz_u128,	alx_clz_u128);
# endif
# if defined(uint256_t)
ALX_ALIAS_DECLARATION(clz_u256,	alx_clz_u256);
# endif
#endif


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
