/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/videoio/cam.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <opencv2/core/base.hpp>
#include <opencv2/videoio.hpp>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
/* ----- alloc / free */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_cv_alloc_cam	(void **cam);
[[gnu::nonnull]]
void	alx_cv_free_cam		(void *cam);
/* ----- init / deinit */
[[gnu::nonnull(1)]]
void	alx_cv_init_cam		(void *restrict cam,
				 const char *restrict dev, int index, int api);
[[gnu::nonnull]]
void	alx_cv_deinit_cam	(void *cam);
/* ----- read */
[[gnu::nonnull]]
int	alx_cv_cam_read		(void *restrict img, void *restrict cam);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/* ----- alloc / free */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alloc_cam	(class cv::VideoCapture **cam);
[[gnu::nonnull]]
void	free_cam	(class cv::VideoCapture *cam);
/* ----- init / deinit */
[[gnu::nonnull(1)]]
void	init_cam	(class cv::VideoCapture *cam,
			 const char *restrict dev, int index, int api);
[[gnu::nonnull]]
void	deinit_cam	(class cv::VideoCapture *cam);
/* ----- read */
[[gnu::nonnull]]
int	cam_read	(class cv::Mat *restrict img,
			 class cv::VideoCapture *restrict cam);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
