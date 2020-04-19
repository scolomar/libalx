/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdint/constants.h */

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
 ******* define ***************************************************************
 ******************************************************************************/
#define SQRT_U8_MAX	(UINT8_C(0xF))
#define SQRT_S8_MAX	( INT8_C(0xB))

#define SQRT_U16_MAX	(UINT16_C(0xFF))
#define SQRT_S16_MAX	( INT16_C(0xB5))

#define SQRT_U32_MAX	(UINT32_C(0xFFFF))
#define SQRT_S32_MAX	( INT32_C(0xB504))

#define SQRT_U64_MAX	(UINT64_C(0xFFFFFFFF))
#define SQRT_S64_MAX	( INT64_C(0xB504F333))




/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static variables *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
