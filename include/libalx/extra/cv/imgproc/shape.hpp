/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/shape.hpp */


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
int	alx_cv_contours		(void *restrict img, void *restrict contours);
[[gnu::nonnull(1)]]
void	alx_cv_contour_dimensions(const void *restrict contour,
				 double *restrict area,
				 double *restrict perimeter);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_cv_conts_largest	(const void **restrict cont,
				 const void *restrict conts);
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
int	contours	(class cv::Mat *restrict img,
			 class std::vector<
				class std::vector<
				class cv::Point_<
				int>>>  *restrict contours);
[[gnu::nonnull(1)]]
void	contour_dimensions(const class std::vector<
				class cv::Point_<
				int>>  *restrict contour,
			 double *restrict area,
			 double *restrict perimeter);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	conts_largest	(const class std::vector<
				class cv::Point_<int>> **restrict cont,
			 const class std::vector<
				class std::vector<
				class cv::Point_<int>>> *restrict conts);
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
