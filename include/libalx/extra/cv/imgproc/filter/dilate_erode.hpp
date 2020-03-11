/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/filter/dilate_erode.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>

#include <opencv2/core/base.hpp>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]]
int	alx_cv_dilate		(void *img, ptrdiff_t i);
[[gnu::nonnull]]
int	alx_cv_dilate_h		(void *img, ptrdiff_t i);
[[gnu::nonnull]]
int	alx_cv_dilate_v		(void *img, ptrdiff_t i);
[[gnu::nonnull]]
int	alx_cv_erode		(void *img, ptrdiff_t i);
[[gnu::nonnull]]
int	alx_cv_erode_h		(void *img, ptrdiff_t i);
[[gnu::nonnull]]
int	alx_cv_erode_v		(void *img, ptrdiff_t i);
[[gnu::nonnull]]
int	alx_cv_dilate_erode	(void *img, ptrdiff_t i);
[[gnu::nonnull]]
int	alx_cv_erode_dilate	(void *img, ptrdiff_t i);
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
int	dilate		(class cv::Mat *img, ptrdiff_t i);
[[gnu::nonnull]]
int	dilate_h	(class cv::Mat *img, ptrdiff_t i);
[[gnu::nonnull]]
int	dilate_v	(class cv::Mat *img, ptrdiff_t i);
[[gnu::nonnull]]
int	erode		(class cv::Mat *img, ptrdiff_t i);
[[gnu::nonnull]]
int	erode_h		(class cv::Mat *img, ptrdiff_t i);
[[gnu::nonnull]]
int	erode_v		(class cv::Mat *img, ptrdiff_t i);
[[gnu::nonnull]]
int	dilate_erode	(class cv::Mat *img, ptrdiff_t i);
[[gnu::nonnull]]
int	erode_dilate	(class cv::Mat *img, ptrdiff_t i);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/