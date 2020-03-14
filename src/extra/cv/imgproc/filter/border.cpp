/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/filter/border.hpp"

#include <cstddef>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#include "libalx/extra/cv/alx/median.hpp"


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
void	alx::CV::border_black		(class cv::Mat *img, ptrdiff_t size)
{
	class cv::Mat	tmp;

	tmp	= cv::Mat(cv::Size(img->cols + size * 2, img->rows + size * 2),
								img->depth());
	cv::copyMakeBorder(*img, tmp, size, size, size, size,
					cv::BORDER_CONSTANT, cv::Scalar(0));
	tmp.copyTo(*img);
	tmp.release();
}

void	alx_cv_border_black		(void *img, ptrdiff_t size)
{
	alx::CV::border_black((class cv::Mat *)img, size);
}

int	alx::CV::border1D_median	(class cv::Mat *img, ptrdiff_t size)
{
	class cv::Mat	tmp;
	uint8_t		m;

	if (img->channels() != 1)
		return	-1;

	img->copyTo(tmp);
	m	= alx::CV::median(&tmp);
	tmp	= cv::Mat(cv::Size(img->cols + size * 2, img->rows + size * 2),
								img->depth());
	cv::copyMakeBorder(*img, tmp, size, size, size, size,
					cv::BORDER_CONSTANT, cv::Scalar(m));
	tmp.copyTo(*img);
	tmp.release();
	return	0;
}

int	alx_cv_border1D_median		(void *img, ptrdiff_t size)
{
	return	alx::CV::border1D_median((class cv::Mat *)img, size);
}

int	alx::CV::border1D		(class cv::Mat *img,
					 ptrdiff_t size, uint8_t value)
{
	class cv::Mat	tmp;

	if (img->channels() != 1)
		return	-1;

	tmp	= cv::Mat(cv::Size(img->cols + size * 2, img->rows + size * 2),
								img->depth());
	cv::copyMakeBorder(*img, tmp, size, size, size, size,
					cv::BORDER_CONSTANT, cv::Scalar(value));
	tmp.copyTo(*img);
	tmp.release();
	return	0;
}

int	alx_cv_border1D			(void *img,
					 ptrdiff_t size, uint8_t value)
{
	return	alx::CV::border1D((class cv::Mat *)img, size, value);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
