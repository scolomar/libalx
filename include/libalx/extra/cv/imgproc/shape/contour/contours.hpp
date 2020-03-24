/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/shape/contour/contours.hpp */


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
int	alx_cv_contours		(const void *restrict img,
				 void *restrict conts);
[[gnu::nonnull(1)]]
void	alx_cv_contour_dimensions(const void *restrict contour,
				 double *restrict area,
				 double *restrict perimeter,
				 ptrdiff_t *restrict ctr_x,
				 ptrdiff_t *restrict ctr_y);
[[gnu::nonnull(3)]] [[gnu::warn_unused_result]]
int	alx_cv_conts_largest	(const void **restrict cont,
				 ptrdiff_t *restrict i,
				 const void *restrict conts);
[[gnu::nonnull(3)]] [[gnu::warn_unused_result]]
int	alx_cv_conts_closest	(const void **restrict cont,
				 ptrdiff_t *restrict i,
				 const void *restrict conts,
				 ptrdiff_t x, ptrdiff_t y,
				 double (*fdist)(int32_t dx, int32_t dy));
[[gnu::nonnull]]
int	alx_cv_contour_mask	(const void **restrict img,
				 const void *restrict conts, ptrdiff_t i);
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
int	contours	(const class cv::Mat *restrict img,
			 class std::vector<
				class std::vector<
				class cv::Point_<int>>>  *restrict conts);
[[gnu::nonnull(1)]]
void	contour_dimensions(const class std::vector<
				class cv::Point_<
				int>>  *restrict contour,
			 double *restrict area,
			 double *restrict perimeter,
			 ptrdiff_t *restrict ctr_x,
			 ptrdiff_t *restrict ctr_y);
[[gnu::nonnull(3)]] [[gnu::warn_unused_result]]
int	conts_largest	(const class std::vector<
				class cv::Point_<int>> **restrict cont,
			 ptrdiff_t *restrict i,
			 const class std::vector<
				class std::vector<
				class cv::Point_<int>>> *restrict conts);
[[gnu::nonnull(3)]] [[gnu::warn_unused_result]]
int	conts_closest	(const class std::vector<
				class cv::Point_<int>> **restrict cont,
			 ptrdiff_t *restrict i,
			 const class std::vector<
				class std::vector<
				class cv::Point_<int>>> *restrict conts,
			 ptrdiff_t x, ptrdiff_t y,
			 double (*fdist)(int32_t dx, int32_t dy));
[[gnu::nonnull]]
int	contour_mask	(class cv::Mat *restrict img,
			 const class std::vector<
				class std::vector<
				class cv::Point_<int>>> *restrict conts,
			 ptrdiff_t i);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
