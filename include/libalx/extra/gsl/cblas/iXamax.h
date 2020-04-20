/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/cblas/iXamax.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>


/******************************************************************************
 ******* define ***************************************************************
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
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_ldbl	(ptrdiff_t nmemb,
				 const long double arr[static restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_uint	(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_int	(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_s64	(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamax_pdif	(ptrdiff_t nmemb,
				 const ptrdiff_t arr[static restrict nmemb],
				 ptrdiff_t step);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
