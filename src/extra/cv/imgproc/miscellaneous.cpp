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

#include "libalx/extra/cv/core/array.hpp"


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

void	alx::CV::bkgd_mask		(class cv::Mat *img)
{
	cv::floodFill(*img, cv::Point(0, 0), UINT8_MAX);
}

void	alx_cv_bkgd_mask		(void *img)
{
	alx::CV::bkgd_mask((class cv::Mat *)img);
}

void	alx::CV::bkgd_fill		(class cv::Mat *img)
{
	class cv::Mat	tmp;

	img->copyTo(tmp);
	alx::CV::bkgd_mask(&tmp);
	cv::bitwise_or(*img, tmp, *img);

	tmp.release();
}

void	alx_cv_bkgd_fill		(void *img)
{
	alx::CV::bkgd_fill((class cv::Mat *)img);
}

void	alx::CV::holes_mask		(class cv::Mat *img)
{

	alx::CV::bkgd_fill(img);
	cv::bitwise_not(*img, *img);
}

void	alx_cv_holes_mask		(void *img)
{
	alx::CV::holes_mask((class cv::Mat *)img);
}

void	alx::CV::holes_fill		(class cv::Mat *img)
{

	alx::CV::bkgd_mask(img);
	cv::bitwise_not(*img, *img);
}

void	alx_cv_holes_fill		(void *img)
{
	alx::CV::holes_fill((class cv::Mat *)img);
}

int	alx::CV::color_white_mask	(class cv::Mat *img, uint8_t tolerance)
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

int	alx_cv_color_white_mask		(void *img, uint8_t tolerance)
{
	return	alx::CV::color_white_mask((class cv::Mat *)img, tolerance);
}

int	alx::CV::color_black_mask	(class cv::Mat *img, uint8_t tolerance)
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

int	alx_cv_color_black_mask		(void *img, uint8_t tolerance)
{
	return	alx::CV::color_black_mask((class cv::Mat *)img, tolerance);
}

int	alx::CV::color_gray_mask	(class cv::Mat *img, uint8_t tolerance)
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

int	alx_cv_color_gray_mask		(void *img, uint8_t tolerance)
{
	return	alx::CV::color_gray_mask((class cv::Mat *)img, tolerance);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
