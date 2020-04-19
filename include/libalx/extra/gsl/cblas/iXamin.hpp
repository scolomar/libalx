/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/cblas/iXamin.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_ldbl	(ptrdiff_t nmemb,
				 const long double *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_uint	(ptrdiff_t nmemb,
				 const unsigned *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_int	(ptrdiff_t nmemb,
				 const int *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_u32	(ptrdiff_t nmemb,
				 const uint32_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_s32	(ptrdiff_t nmemb,
				 const int32_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_u64	(ptrdiff_t nmemb,
				 const uint64_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_s64	(ptrdiff_t nmemb,
				 const int64_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamin_pdif	(ptrdiff_t nmemb,
				 const ptrdiff_t *restrict arr,
				 ptrdiff_t step);
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
