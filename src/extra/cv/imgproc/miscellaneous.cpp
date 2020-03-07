/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/miscellaneous.hpp"

#include <cstdint>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_CV_MAX_KSIZE	(50)


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx::CV::adaptive_thr		(class cv::Mat *img,
					 int method, int thr_typ, int ksize)
{

	if (img->channels() != 1)
		return	1;
	if (method < 0 || method > 1)
		return	1;
	if (thr_typ < 0 || thr_typ > 1)
		return	1;
	if (!(ksize % 2) || ksize < 3 || ksize > ALX_CV_MAX_KSIZE)
		return	1;
	cv::adaptiveThreshold(*img, *img, UINT8_MAX, method, thr_typ, ksize, 0);

	return	0;
}

int	alx_cv_adaptive_thr		(void *img,
					 int method, int thr_typ, int ksize)
{
	return	alx::CV::adaptive_thr((class cv::Mat *)img,
						method, thr_typ, ksize);
}

int	alx::CV::cvt_color		(class cv::Mat *img, int method)
{

	if (img->channels() != 3)
		return	1;
	if (method < 0 || method > cv::COLOR_COLORCVT_MAX)
		return	1;
	cv::cvtColor(*img, *img, method, 0);

	return	0;
}

int	alx_cv_cvt_color		(void *img, int method)
{
	return	alx::CV::cvt_color((class cv::Mat *)img, method);
}

void	alx::CV::cvt_res_8b		(class cv::Mat *img)
{
	class cv::Mat	tmp;

	img->convertTo(tmp, CV_8U);
	tmp.copyTo(*img);

	tmp.release();
}

void	alx_cv_cvt_res_8b		(void *img)
{
	alx::CV::cvt_res_8b((class cv::Mat *)img);
}

int	alx::CV::distance_transform	(class cv::Mat *img)
{
	class cv::Mat	tmp;

	if (img->channels() != 1)
		return	1;
	cv::distanceTransform(*img, tmp, cv::DIST_L2, cv::DIST_MASK_PRECISE);
	tmp.copyTo(*img);

	tmp.release();
	return	0;
}

int	alx_cv_distance_transform	(void *img)
{
	return	alx::CV::distance_transform((class cv::Mat *)img);
}

int	alx::CV::distance_transform_8b	(class cv::Mat *img)
{
	class cv::Mat	tmp;

	if (img->channels() != 1)
		return	1;
	cv::distanceTransform(*img, tmp, cv::DIST_L2, cv::DIST_MASK_PRECISE);
	/* DistanceTransform gives CV_32F image */
	tmp.convertTo(*img, CV_8U);

	tmp.release();
	return	0;
}

int	alx_cv_distance_transform_8b	(void *img)
{
	return	alx::CV::distance_transform_8b((class cv::Mat *)img);
}

int	alx::CV::threshold		(class cv::Mat *img,
					 int thr_typ, int thr_val)
{

	if (img->channels() != 1)
		return	1;
	if (thr_typ < 0 || thr_typ > 4)
		return	1;
	if (thr_typ < -1 || thr_typ > UINT8_MAX)
		return	1;
	if (thr_val == -1)
		thr_typ	|= cv::THRESH_OTSU;
	cv::threshold(*img, *img, thr_val, UINT8_MAX, thr_typ);

	return	0;
}

int	alx_cv_threshold		(void *img, int thr_typ, int thr_val)
{
	return	alx::CV::threshold((class cv::Mat *)img, thr_typ, thr_val);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
