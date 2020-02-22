/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/core/contours.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>

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
/* ----- Alloc */
[[gnu::nonnull]]
int	alx_cv_alloc_conts	(void **contours);
[[gnu::nonnull]]
void	alx_cv_free_conts	(void *contours);
/* ----- Init */
[[gnu::nonnull]]
void	alx_cv_init_conts	(void *conts);
[[gnu::nonnull]]
void	alx_cv_deinit_conts	(void *conts);
/* ----- Extract */
[[gnu::nonnull(1, 3)]]
void	alx_cv_extract_conts	(const void *restrict conts,
				 const void **restrict cont,
				 ptrdiff_t *restrict size);
[[gnu::nonnull]]
int	alx_cv_extract_conts_cont(const void **restrict cont,
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
/* ----- Alloc */
[[gnu::nonnull]]
int	alloc_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> **contours);
[[gnu::nonnull]]
void	free_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> *contours);
/* ----- Init */
[[gnu::nonnull]]
void	init_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> *conts);
[[gnu::nonnull]]
void	deinit_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> *conts);
/* ----- Extract */
[[gnu::nonnull(1, 3)]]
void	extract_conts	(const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts,
			 const class std::vector<
					class cv::Point_<int>> **restrict cont,
			 ptrdiff_t *restrict size);
[[gnu::nonnull]]
int	extract_conts_cont(const class std::vector<
					class cv::Point_<int>> **restrict cont,
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
