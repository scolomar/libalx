/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/miscellaneous/threshold.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <opencv2/core/base.hpp>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_CV_THR_OTSU		(-1)
#define ALX_CV_THR_TRIANGLE	(-2)


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]]
int	alx_cv_adaptive_thr		(void *img,
					 int method, int thr_typ, int ksize);
[[gnu::nonnull]]
int	alx_cv_threshold		(void *img, int thr_typ, int thr_val);
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
[[gnu::nonnull]]
int	adaptive_thr		(class cv::Mat *img,
				 int method, int thr_typ, int ksize);
[[gnu::nonnull]]
int	threshold		(class cv::Mat *img, int thr_typ, int thr_val);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
