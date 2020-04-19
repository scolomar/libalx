/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/errno/error.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/*
 * [[noreturn]] [[gnu::format(printf, 2, 3)]]
 * void	alx_errorx(int status, const char *restrict fmt, ...);
 */
#define alx_errorx(status, fmt, ...)	do				\
{									\
	alx__errorx__(status, __FILE__, __LINE__, __func__, errno,	\
						fmt, ##__VA_ARGS__);	\
} while (0)


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[noreturn]] [[gnu::nonnull(2, 4)]] [[gnu::format(printf, 6, 7)]] [[gnu::cold]]
void	alx__errorx__	(int status, const char *restrict file, int line,
			 const char *restrict func, int errno_val,
			 const char *restrict format, ...);
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
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define errorx(status, fmt, ...)	alx_errorx(status, fmt, ##__VA_ARGS__)
#endif


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
