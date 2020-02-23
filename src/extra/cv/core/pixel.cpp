/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/core/pixel.hpp"

#include <cstddef>

#include <opencv2/core/mat.hpp>

#include "libalx/base/compiler/restrict.hpp"


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
int	alx::CV::pixel_get_u8	(const class cv::Mat *restrict img,
				 unsigned char *restrict val,
				 ptrdiff_t x, ptrdiff_t y)
{

	/* TODO: multichannel images */
	if (img->channels() != 1)
		return	-1;
	if (x < 0 || y < 0)
		return	-1;
	*val	= img->at<unsigned char>(y, x);

	return	0;
}

int	alx_cv_pixel_get_u8	(const void *restrict img,
				 unsigned char *restrict val,
				 ptrdiff_t x, ptrdiff_t y)
{
	return	alx::CV::pixel_get_u8((const class cv::Mat *)img, val, x, y);
}

int	alx::CV::pixel_set_u8	(class cv::Mat *img,
				 unsigned char val, ptrdiff_t x, ptrdiff_t y)
{

	/* TODO: multichannel images */
	if (img->channels() != 1)
		return	1;
	if (x < 0 || y < 0)
		return	1;
	img->at<unsigned char>(y, x)	= val;

	return	0;
}

int	alx_cv_pixel_set_u8	(void *img,
				 unsigned char val, ptrdiff_t x, ptrdiff_t y)
{
	return	alx::CV::pixel_set_u8((class cv::Mat *)img, val, x, y);
}

int	alx::CV::pixel_get_flt	(const class cv::Mat *restrict img,
				 float *restrict val, ptrdiff_t x, ptrdiff_t y)
{

	/* TODO: multichannel images */
	if (img->channels() != 1)
		return	-1;
	if (x < 0 || y < 0)
		return	-1;
	*val	= img->at<float>(y, x);

	return	0;
}

int	alx_cv_pixel_get_flt	(const void *restrict img,
				 float *restrict val, ptrdiff_t x, ptrdiff_t y)
{
	return	alx::CV::pixel_get_flt((const class cv::Mat *)img, val, x, y);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
