/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/geometric/resize.hxx"

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>


/******************************************************************************
 ******* define ***************************************************************
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
void	alx::CV::resize_w_2largest	(class cv::Mat *restrict img_a,
					 class cv::Mat *restrict img_b)
{
	ptrdiff_t	aw, ah, bw, bh;

	aw	= img_a->cols;
	ah	= img_a->rows;
	bw	= img_b->cols;
	bh	= img_b->rows;

	if (aw < bw)
		cv::resize(*img_a, *img_a, cv::Size(bw, ah), 0, 0);
	else
		cv::resize(*img_b, *img_b, cv::Size(aw, bh), 0, 0);
}

void	alx_cv_resize_w_2largest	(void *restrict img_a,
					 void *restrict img_b)
{
	alx::CV::resize_w_2largest((class cv::Mat *)img_a,
							(class cv::Mat *)img_b);
}

void	alx::CV::resize_h_2largest	(class cv::Mat *restrict img_a,
					 class cv::Mat *restrict img_b)
{
	ptrdiff_t	aw, ah, bw, bh;

	aw	= img_a->cols;
	ah	= img_a->rows;
	bw	= img_b->cols;
	bh	= img_b->rows;

	if (ah < bh)
		cv::resize(*img_a, *img_a, cv::Size(aw, bh), 0, 0);
	else
		cv::resize(*img_b, *img_b, cv::Size(bw, ah), 0, 0);
}

void	alx_cv_resize_h_2largest	(void *restrict img_a,
					 void *restrict img_b)
{
	alx::CV::resize_h_2largest((class cv::Mat *)img_a,
							(class cv::Mat *)img_b);
}

void	alx::CV::resize_2largest	(class cv::Mat *restrict img_a,
					 class cv::Mat *restrict img_b)
{

	alx::CV::resize_w_2largest(img_a, img_b);
	alx::CV::resize_h_2largest(img_a, img_b);
}

void	alx_cv_resize_2largest		(void *restrict img_a,
					 void *restrict img_b)
{
	alx::CV::resize_2largest((class cv::Mat *)img_a,(class cv::Mat *)img_b);
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
