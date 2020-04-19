/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdint/types.hpp */

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
 ******* typedef **************************************************************
 ******************************************************************************/
#if defined(__SIZEOF_INT128__)
# if !defined(UINT128_MAX)	/* This is to test if uint128_t already exists */
typedef	unsigned __int128	uint128_t;
typedef	__int128		int128_t;
#  if !defined(uint128_t)
#define uint128_t	uint128_t
#  endif
#  if !defined(int128_t)
#define int128_t	int128_t
#  endif
# endif
#endif


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#if defined(uint128_t)
#define UINT128_C(c)	((uint128_t)c)
#define INT128_C(c)	(( int128_t)c)
#define UINT128_MAX	((uint128_t)~UINT128_C(0))
#define INT128_MAX	(( int128_t)(UINT128_MAX >> 1))
#define INT128_MIN	(( int128_t)(-INT128_MAX - 1))
#define SQRT_U128_MAX	((uint128_t)(0xFFFFFFFFFFFFFFFF))
#define SQRT_S128_MAX	(( int128_t)(0xB504F333F9DE6800))
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
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
