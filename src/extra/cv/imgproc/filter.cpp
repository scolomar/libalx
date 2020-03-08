/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/filter.hpp"

#include <cstddef>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_CV_MAX_DERIVATIVE	(20)


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx::CV::dilate		(class cv::Mat *img, ptrdiff_t i)
{

	if (i < 1)
		return	1;
	cv::dilate(*img, *img, cv::Mat(), cv::Point(-1,-1), i,
					cv::BORDER_CONSTANT, cv::Scalar(0));
	return	0;
}

int	alx_cv_dilate		(void *img, ptrdiff_t i)
{
	return	alx::CV::dilate((class cv::Mat *)img, i);
}

int	alx::CV::erode		(class cv::Mat *img, ptrdiff_t i)
{

	if (i < 1)
		return	1;
	cv::erode(*img, *img, cv::Mat(), cv::Point(-1,-1), i,
					cv::BORDER_CONSTANT, cv::Scalar(0));
	return	0;
}

int	alx_cv_erode		(void *img, ptrdiff_t i)
{
	return	alx::CV::erode((class cv::Mat *)img, i);
}

int	alx::CV::dilate_erode	(class cv::Mat *img, ptrdiff_t i)
{

	if (alx::CV::dilate(img, i))
		return	1;
	if (alx::CV::erode(img, i))
		return	1;

	return	0;
}

int	alx_cv_dilate_erode	(void *img, ptrdiff_t i)
{
	return	alx::CV::dilate_erode((class cv::Mat *)img, i);
}

int	alx::CV::erode_dilate	(class cv::Mat *img, ptrdiff_t i)
{

	if (alx::CV::erode(img, i))
		return	1;
	if (alx::CV::dilate(img, i))
		return	1;

	return	0;
}

int	alx_cv_erode_dilate	(void *img, ptrdiff_t i)
{
	return	alx::CV::erode_dilate((class cv::Mat *)img, i);
}

int	alx::CV::smooth		(class cv::Mat *img,
				 int method, ptrdiff_t ksize)
{

	if (!(ksize % 2)  ||  ksize < 3)
		return	1;

	switch (method) {
	case alx::CV::SMOOTH_MEAN:
		cv::blur(*img, *img, cv::Size(ksize, ksize), cv::Point(-1,-1),
							cv::BORDER_DEFAULT);
		break;
	case alx::CV::SMOOTH_GAUSS:
		cv::GaussianBlur(*img, *img, cv::Size(ksize, ksize), 0, 0,
							cv::BORDER_DEFAULT);
		break;
	case alx::CV::SMOOTH_MEDIAN:
		cv::medianBlur(*img, *img, ksize);
		break;
	default:
		return	1;
	}

	return	0;
}

int	alx_cv_smooth		(void *img, int method, int ksize)
{
	return	alx::CV::smooth((class cv::Mat *)img, method, ksize);
}

int	alx::CV::sobel		(class cv::Mat *img,
				 int dx, int dy, ptrdiff_t ksize)
{

	if (dx < 0 || dy < 0)
		return	1;
	if (dx > ALX_CV_MAX_DERIVATIVE || dy > ALX_CV_MAX_DERIVATIVE)
		return	1;
	if (!(ksize % 2)  ||  ksize < -1)
		return	1;
	cv::Sobel(*img, *img, -1, dx, dy, ksize, 1, 0, cv::BORDER_DEFAULT);

	return	0;
}

int	alx_cv_sobel		(void *img, int dx, int dy, ptrdiff_t ksize)
{
	return	alx::CV::sobel((class cv::Mat *)img, dx, dy, ksize);
}

int	alx::CV::border		(class cv::Mat *img, ptrdiff_t size)
{
	class cv::Mat	tmp;

	tmp	= cv::Mat(cv::Size(img->cols + size * 2, img->rows + size * 2),
								img->depth());
	cv::copyMakeBorder(*img, tmp, size, size, size, size,
					cv::BORDER_CONSTANT, cv::Scalar(0));
	tmp.copyTo(*img);
	tmp.release();
	return	0;
}

int	alx_cv_border		(void *img, ptrdiff_t size)
{
	return	alx::CV::border((class cv::Mat *)img, size);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
