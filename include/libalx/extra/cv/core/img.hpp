/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/core/img.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>

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
int	alx_cv_alloc_img	(void **img);
[[gnu::nonnull]]
void	alx_cv_free_img		(void *img);
/* ----- Init */
[[gnu::nonnull]]
int	alx_cv_init_img		(void *img, ptrdiff_t w, ptrdiff_t h);
[[gnu::nonnull]]
void	alx_cv_deinit_img	(void *img);
/* ----- Extract */
[[gnu::nonnull(1)]]
void	alx_cv_extract_imgdata	(const void *restrict img,
				 void **restrict data,
				 ptrdiff_t *restrict rows,
				 ptrdiff_t *restrict cols,
				 ptrdiff_t *restrict width,
				 ptrdiff_t *restrict height,
				 ptrdiff_t *restrict B_per_pix,
				 ptrdiff_t *restrict B_per_line,
				 int *restrict type);
/* ----- Copy */
[[gnu::nonnull]]
void	alx_cv_clone		(void *restrict clone,
				 const void *restrict img);
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
int	alloc_img	(class cv::Mat **img);
[[gnu::nonnull]]
void	free_img	(class cv::Mat *img);
/* ----- Init */
[[gnu::nonnull]]
int	init_img	(class cv::Mat *img, ptrdiff_t w, ptrdiff_t h);
[[gnu::nonnull]]
void	deinit_img	(class cv::Mat *img);
/* ----- Extract */
[[gnu::nonnull(1)]]
void	extract_imgdata	(const class cv::Mat *restrict img,
			 void **restrict data,
			 ptrdiff_t *restrict rows,
			 ptrdiff_t *restrict cols,
			 ptrdiff_t *restrict width,
			 ptrdiff_t *restrict height,
			 ptrdiff_t *restrict B_per_pix,
			 ptrdiff_t *restrict B_per_line,
			 int *restrict type);
/* ----- Copy */
[[gnu::nonnull]]
void	clone		(class cv::Mat *restrict clone,
			 const class cv::Mat *restrict img);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
