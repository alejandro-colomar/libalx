/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/miscellaneous/threshold.hpp"

#include <cstdint>

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
int	alx::CV::adaptive_thr	(class cv::Mat *img, int method,
				 int thr_typ, int ksize, int c)
{

	if (img->channels() != 1)
		return	-1;
	if (method < 0 || method > 1)
		return	-1;
	if (thr_typ < 0 || thr_typ > 1)
		return	-1;
	if (!(ksize % 2) || ksize < 3)
		return	-1;
	cv::adaptiveThreshold(*img, *img, UINT8_MAX, method, thr_typ, ksize, c);

	return	0;
}

int	alx_cv_adaptive_thr	(void *img, int method,
					 int thr_typ, int ksize, int c)
{
	return	alx::CV::adaptive_thr((class cv::Mat *)img,
						method, thr_typ, ksize, c);
}

int	alx::CV::threshold		(class cv::Mat *img,
					 int thr_typ, int thr_val)
{

	if (img->channels() != 1)
		return	-1;
	if (thr_typ < 0 || thr_typ > 4)
		return	-1;
	if (thr_typ < -1 || thr_typ > UINT8_MAX)
		return	-1;
	if (thr_val == ALX_CV_THR_OTSU)
		thr_typ	|= cv::THRESH_OTSU;
	if (thr_val == ALX_CV_THR_TRIANGLE)
		thr_typ	|= cv::THRESH_TRIANGLE;
	return	cv::threshold(*img, *img, thr_val, UINT8_MAX, thr_typ);
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
