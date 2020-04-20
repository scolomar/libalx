/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/cblas/iXamin.h */

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
ptrdiff_t alx_cblas_iXamin_ldbl	(ptrdiff_t nmemb,
				 const long double arr[restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamin_uint	(ptrdiff_t nmemb,
				 const unsigned arr[restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamin_int	(ptrdiff_t nmemb,
				 const int arr[restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamin_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamin_s8	(ptrdiff_t nmemb,
				 const int8_t arr[restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamin_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamin_s16	(ptrdiff_t nmemb,
				 const int16_t arr[restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamin_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamin_s32	(ptrdiff_t nmemb,
				 const int32_t arr[restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamin_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamin_s64	(ptrdiff_t nmemb,
				 const int64_t arr[restrict nmemb],
				 ptrdiff_t step);
__attribute__((nonnull, pure))
ptrdiff_t alx_cblas_iXamin_pdif	(ptrdiff_t nmemb,
				 const ptrdiff_t arr[restrict nmemb],
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
