/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/core/pixel/pixel.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstddef>

#include <opencv2/core/base.hpp>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]]
int	alx_cv_pixel_get_u8	(const void *restrict img,
				 uint8_t *restrict val,
				 ptrdiff_t x, ptrdiff_t y);
[[gnu::nonnull]]
int	alx_cv_pixel_set_u8	(void *img,
				 uint8_t val, ptrdiff_t x, ptrdiff_t y);
[[gnu::nonnull]]
int	alx_cv_pixel_get_flt	(const void *restrict img,
				 float *restrict val, ptrdiff_t x, ptrdiff_t y);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::nonnull]]
int	pixel_get_u8	(const class cv::Mat *restrict img,
			 uint8_t *restrict val, ptrdiff_t x, ptrdiff_t y);
[[gnu::nonnull]]
int	pixel_set_u8	(class cv::Mat *img,
			 uint8_t val, ptrdiff_t x, ptrdiff_t y);
[[gnu::nonnull]]
int	pixel_get_flt	(const class cv::Mat *restrict img,
			 float *restrict val, ptrdiff_t x, ptrdiff_t y);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
