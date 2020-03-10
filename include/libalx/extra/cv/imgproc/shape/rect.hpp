/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/shape/rect.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <vector>

#include <opencv2/core/base.hpp>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]]
void	alx_cv_bounding_rect	(void *restrict rect,
				 const void *restrict contour);
[[gnu::nonnull]]
void	alx_cv_fit_ellipse	(void *restrict rect_rot,
				 const void *restrict contour);
[[gnu::nonnull]]
void	alx_cv_min_area_rect	(void *restrict rect_rot,
				 const void *restrict contour);
[[gnu::nonnull]]
void	alx_cv_draw_rect	(void *restrict img,
				 const void *restrict rect);
[[gnu::nonnull]]
void	alx_cv_draw_rect_rot	(void *restrict img,
				 const void *restrict rect_rot);
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
void	bounding_rect	(class cv::Rect_ <int> *restrict rect,
			 const class std::vector <
				class cv::Point_ <
				int>>  *restrict contour);
[[gnu::nonnull]]
void	fit_ellipse	(class cv::RotatedRect *restrict rect_rot,
			 const class std::vector <
				class cv::Point_ <
				int>>  *restrict contour);
[[gnu::nonnull]]
void	min_area_rect	(class cv::RotatedRect *restrict rect_rot,
			 const class std::vector <
				class cv::Point_ <
				int>>  *restrict contour);
[[gnu::nonnull]]
void	draw_rect	(class cv::Mat *restrict img,
			 const class cv::Rect_ <int> *restrict rect);
[[gnu::nonnull]]
void	draw_rect_rot	(class cv::Mat *restrict img,
			 class cv::RotatedRect *restrict rect_rot);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/