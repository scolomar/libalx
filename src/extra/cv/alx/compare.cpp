/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx/compare.hpp"

#include <cstddef>

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#include "libalx/base/compiler/restrict.hpp"
#include "libalx/extra/cv/imgproc/filter/border.hpp"
#include "libalx/extra/cv/imgproc/geometric/resize.hpp"


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
double	alx::CV::compare_bitwise	(const class cv::Mat *restrict img_a,
					 const class cv::Mat *restrict img_b,
					 ptrdiff_t tolerance)
{
	class cv::Mat	a;
	class cv::Mat	b;
	class cv::Mat	_xor;
	class cv::Mat	_and;
	ptrdiff_t	pix_and;
	ptrdiff_t	pix_dif;
	double		match;

	if (img_a->channels() != 1)
		return	-1;
	if (img_b->channels() != 1)
		return	-2;
	img_a->copyTo(a);
	img_b->copyTo(b);

	alx::CV::resize_2largest(&a, &b);

	cv::bitwise_xor(a, b, _xor);
	cv::bitwise_and(a, b, _and);
	pix_and	= cv::countNonZero(_and);
	cv::bitwise_not(_and, _and);

	alx::CV::border_black(&_xor, tolerance);
	alx::CV::border_black(&_and, tolerance);
	cv::dilate(_xor, _xor, cv::Mat(), cv::Point(-1,-1), tolerance,
					cv::BORDER_CONSTANT, cv::Scalar(0));
	cv::erode(_and, _and, cv::Mat(), cv::Point(-1,-1), tolerance,
					cv::BORDER_CONSTANT, cv::Scalar(0));

	cv::bitwise_and(_xor, _and, a);
	pix_dif	= cv::countNonZero(a);

	match	= (pix_and - pix_dif) / (double)pix_and;

	a.release();
	b.release();
	_xor.release();
	_and.release();

	return	match;
}

double	alx_cv_compare_bitwise		(const void *restrict img_a,
					 const void *restrict img_b,
					 ptrdiff_t tolerance)
{
	return	alx::CV::compare_bitwise((const class cv::Mat *)img_a,
						(const class cv::Mat *)img_b,
						tolerance);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
