/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/core/array.hpp"

#include <cstddef>

#include <opencv2/core.hpp>

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
/* ----- Operations on arrays */
int	alx::CV::and_2ref	(class cv::Mat *restrict img,
				 const class cv::Mat *restrict ref)
{

	if (img->channels() != ref->channels())
		return	1;
	cv::bitwise_and(*img, *ref, *img);

	return	0;
}

int	alx_cv_and_2ref		(void *restrict img, const void *restrict ref)
{
	return	alx::CV::and_2ref((class cv::Mat *)img,
						(const class cv::Mat *)ref);
}

void	alx::CV::invert		(class cv::Mat *restrict img)
{
	cv::bitwise_not(*img, *img);
}

void	alx_cv_invert		(void *restrict img)
{
	alx::CV::invert((class cv::Mat *)img);
}

int	alx::CV::or_2ref	(class cv::Mat *restrict img,
				 const class cv::Mat *restrict ref)
{

	if (img->channels() != ref->channels())
		return	1;
	cv::bitwise_or(*img, *ref, *img);

	return	0;
}

int	alx_cv_or_2ref		(void *restrict img, const void *restrict ref)
{
	return	alx::CV::or_2ref((class cv::Mat *)img,
						(const class cv::Mat *)ref);
}

int	alx::CV::component	(class cv::Mat *restrict img, ptrdiff_t cmp)
{
	const ptrdiff_t	chans	= img->channels();
	class cv::Mat	cmp_img[chans];

	if (chans < 2)
		return	1;
	if (cmp < 0 || cmp >= chans)
		return	1;

	cv::split(*img, cmp_img);
	img->release();
	cmp_img[cmp].copyTo(*img);

	for (ptrdiff_t i = 0; i < chans; i++)
		cmp_img[i].release();
	return	0;
}

int	alx_cv_component	(void *restrict img, ptrdiff_t cmp)
{
	return	alx::CV::component((class cv::Mat *)img, cmp);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
