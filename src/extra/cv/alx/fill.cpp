/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx/fill.hpp"

#include <cstdint>

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>


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
int	alx::CV::bkgd_fill	(class cv::Mat *img)
{

	if (img->channels() != 1)
		return	1;
	cv::floodFill(*img, cv::Point(0, 0), UINT8_MAX);
	return	0;
}

int	alx_cv_bkgd_fill	(void *img)
{
	return	alx::CV::bkgd_fill((class cv::Mat *)img);
}

int	alx::CV::bkgd_mask	(class cv::Mat *img)
{
	class cv::Mat	tmp;

	if (img->channels() != 1)
		return	1;
	img->copyTo(tmp);
	cv::floodFill(tmp, cv::Point(0, 0), UINT8_MAX);
	cv::bitwise_xor(*img, tmp, *img);

	tmp.release();
	return	0;
}

int	alx_cv_bkgd_mask	(void *img)
{
	return	alx::CV::bkgd_mask((class cv::Mat *)img);
}

int	alx::CV::holes_mask	(class cv::Mat *img)
{

	if (img->channels() != 1)
		return	1;
	cv::floodFill(*img, cv::Point(0, 0), UINT8_MAX);
	cv::bitwise_not(*img, *img);
	return	0;
}

int	alx_cv_holes_mask	(void *img)
{
	return	alx::CV::holes_mask((class cv::Mat *)img);
}

int	alx::CV::holes_fill	(class cv::Mat *img)
{

	if (img->channels() != 1)
		return	1;
	alx::CV::bkgd_mask(img);
	cv::bitwise_not(*img, *img);
	return	0;
}

int	alx_cv_holes_fill	(void *img)
{
	return	alx::CV::holes_fill((class cv::Mat *)img);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
