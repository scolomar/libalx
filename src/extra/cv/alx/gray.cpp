/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx/gray.hpp"

#include <cstdint>

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#include "libalx/extra/cv/core/array.hpp"


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
int	alx::CV::white_mask	(class cv::Mat *img, uint8_t tolerance)
{
	class cv::Mat	cmp_img[3];
	class cv::Mat	lw;

	if (img->channels() != 3)
		return	1;
	cv::cvtColor(*img, *img, cv::COLOR_BGR2HLS, 0);
	cv::split(*img, cmp_img);
	img->release();
	/* light white */
	cmp_img[alx::CV::CMP_HLS_L].copyTo(cmp_img[0]);
	cv::threshold(cmp_img[0], cmp_img[0],
			UINT8_MAX - tolerance -1, UINT8_MAX, cv::THRESH_BINARY);
	/* grayish white */
	cv::threshold(cmp_img[alx::CV::CMP_HLS_L], cmp_img[alx::CV::CMP_HLS_L],
			UINT8_MAX / 2, UINT8_MAX, cv::THRESH_BINARY);
	cv::threshold(cmp_img[alx::CV::CMP_HLS_S], cmp_img[alx::CV::CMP_HLS_S],
			tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
	cv::bitwise_and(cmp_img[alx::CV::CMP_HLS_S],
			cmp_img[alx::CV::CMP_HLS_L],
			cmp_img[alx::CV::CMP_HLS_S]);
	/* merge */
	cmp_img[0].copyTo(*img);
	cv::bitwise_or(*img, cmp_img[alx::CV::CMP_HLS_S], *img);

	for (ptrdiff_t i = 0; i < 3; i++)
		cmp_img[i].release();
	return	0;
}

int	alx_cv_white_mask	(void *img, uint8_t tolerance)
{
	return	alx::CV::white_mask((class cv::Mat *)img, tolerance);
}

int	alx::CV::black_mask	(class cv::Mat *img, uint8_t tolerance)
{
	class cv::Mat	cmp_img[3];

	if (img->channels() != 3)
		return	1;
	cv::cvtColor(*img, *img, cv::COLOR_BGR2HLS, 0);
	cv::split(*img, cmp_img);
	img->release();
	/* dark black */
	cmp_img[alx::CV::CMP_HLS_L].copyTo(cmp_img[0]);
	cv::threshold(cmp_img[0], cmp_img[0],
			tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
	/* grayish black */
	cv::threshold(cmp_img[alx::CV::CMP_HLS_L], cmp_img[alx::CV::CMP_HLS_L],
			UINT8_MAX / 2, UINT8_MAX, cv::THRESH_BINARY_INV);
	cv::threshold(cmp_img[alx::CV::CMP_HLS_S], cmp_img[alx::CV::CMP_HLS_S],
			tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
	cv::bitwise_and(cmp_img[alx::CV::CMP_HLS_S],
			cmp_img[alx::CV::CMP_HLS_L],
			cmp_img[alx::CV::CMP_HLS_S]);
	/* merge */
	cmp_img[0].copyTo(*img);
	cv::bitwise_or(*img, cmp_img[alx::CV::CMP_HLS_S], *img);

	for (ptrdiff_t i = 0; i < 3; i++)
		cmp_img[i].release();
	return	0;
}

int	alx_cv_black_mask	(void *img, uint8_t tolerance)
{
	return	alx::CV::black_mask((class cv::Mat *)img, tolerance);
}

int	alx::CV::gray_mask	(class cv::Mat *img, uint8_t tolerance)
{
	class cv::Mat	cmp_img[3];

	if (img->channels() != 3)
		return	1;
	cv::cvtColor(*img, *img, cv::COLOR_BGR2HLS, 0);
	cv::split(*img, cmp_img);
	img->release();
	/* dark black */
	cmp_img[alx::CV::CMP_HLS_L].copyTo(cmp_img[0]);
	cv::threshold(cmp_img[0], cmp_img[0],
			tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
	/* light white */
	cv::threshold(cmp_img[alx::CV::CMP_HLS_L], cmp_img[alx::CV::CMP_HLS_L],
			UINT8_MAX - tolerance -1, UINT8_MAX, cv::THRESH_BINARY);
	/* gray */
	cv::threshold(cmp_img[alx::CV::CMP_HLS_S], cmp_img[alx::CV::CMP_HLS_S],
			tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
	/* merge */
	cmp_img[0].copyTo(*img);
	cv::bitwise_or(*img, cmp_img[alx::CV::CMP_HLS_L], *img);
	cv::bitwise_or(*img, cmp_img[alx::CV::CMP_HLS_S], *img);

	for (ptrdiff_t i = 0; i < 3; i++)
		cmp_img[i].release();
	return	0;
}

int	alx_cv_gray_mask	(void *img, uint8_t tolerance)
{
	return	alx::CV::gray_mask((class cv::Mat *)img, tolerance);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
