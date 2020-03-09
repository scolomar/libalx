/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/core/img.hpp"

#include <cstddef>

#include <memory>

#include <opencv2/core/mat.hpp>

#include "libalx/base/compiler/restrict.hpp"
#include "libalx/base/stdlib/alloc/mallocarrays.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
/* ----- alloc / free */
int	alx::CV::alloc_img	(class cv::Mat **img)
{
	return	alx_mallocarrays(img, 1);
}

int	alx_cv_alloc_img	(void **img)
{
	return	alx::CV::alloc_img((class cv::Mat **)img);
}

void	alx::CV::free_img	(class cv::Mat *img)
{
	free(img);
}

void	alx_cv_free_img		(void *img)
{
	alx::CV::free_img((class cv::Mat *)img);
}

/* ----- init / deinit */
int	alx::CV::init_img	(class cv::Mat *img, ptrdiff_t w, ptrdiff_t h)
{

	if (w < 1 || h < 1)
		return	1;
	new (img)	cv::Mat(cv::Size(w, h), CV_8UC3, 0.0);

	return	0;
}

int	alx_cv_init_img		(void *img, ptrdiff_t w, ptrdiff_t h)
{
	return	alx::CV::init_img((class cv::Mat *)img, w, h);
}

void	alx::CV::deinit_img	(class cv::Mat *img)
{
	std::destroy_at(img);
}

void	alx_cv_deinit_img	(void *img)
{
	alx::CV::deinit_img((class cv::Mat *)img);
}

/* ----- Extract */
void	alx::CV::extract_imgdata(const class cv::Mat *restrict img,
				 void **restrict data,
				 ptrdiff_t *restrict w,
				 ptrdiff_t *restrict h,
				 ptrdiff_t *restrict B_per_pix,
				 ptrdiff_t *restrict B_per_line,
				 int *restrict type)
{

	if (data)
		*data		= img->data;
	if (w)
		*w		= img->cols;
	if (h)
		*h		= img->rows;
	if (B_per_pix)
		*B_per_pix	= img->channels();
	if (B_per_line)
		*B_per_line	= img->step1();
	if (type)
		*type		= img->type();
}

void	alx_cv_extract_imgdata	(const void *restrict img,
				 void **restrict data,
				 ptrdiff_t *restrict w,
				 ptrdiff_t *restrict h,
				 ptrdiff_t *restrict B_per_pix,
				 ptrdiff_t *restrict B_per_line,
				 int *restrict type)
{
	alx::CV::extract_imgdata((const class cv::Mat *)img, data, w, h,
						B_per_pix, B_per_line, type);
}

/* ----- Copy */
void	alx::CV::clone		(class cv::Mat *restrict clone,
				 const class cv::Mat *restrict img)
{
	img->copyTo(*clone);
}

void	alx_cv_clone		(void *restrict clone, const void *restrict img)
{
	alx::CV::clone((class cv::Mat *)clone, (const class cv::Mat *)img);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
