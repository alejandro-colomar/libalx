/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/filter/dilate_erode.hxx"

#include <cstddef>

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
int	alx::CV::dilate		(class cv::Mat *img, ptrdiff_t i)
{

	if (i < 1)
		return	1;
	cv::dilate(*img, *img, cv::Mat(), cv::Point(-1,-1), i);
	return	0;
}

int	alx_cv_dilate		(void *img, ptrdiff_t i)
{
	return	alx::CV::dilate((class cv::Mat *)img, i);
}

int	alx::CV::dilate_h	(class cv::Mat *img, ptrdiff_t i)
{
	class cv::Mat	k;

	if (i < 1)
		return	1;
	k	= cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 1));
	cv::dilate(*img, *img, k, cv::Point(-1,-1), i);
	k.release();
	return	0;
}

int	alx_cv_dilate_h		(void *img, ptrdiff_t i)
{
	return	alx::CV::dilate_h((class cv::Mat *)img, i);
}

int	alx::CV::dilate_v	(class cv::Mat *img, ptrdiff_t i)
{
	class cv::Mat	k;

	if (i < 1)
		return	1;
	k	= cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, 3));
	cv::dilate(*img, *img, k, cv::Point(-1,-1), i);
	k.release();
	return	0;
}

int	alx_cv_dilate_v		(void *img, ptrdiff_t i)
{
	return	alx::CV::dilate_v((class cv::Mat *)img, i);
}

int	alx::CV::erode		(class cv::Mat *img, ptrdiff_t i)
{

	if (i < 1)
		return	1;
	cv::erode(*img, *img, cv::Mat(), cv::Point(-1,-1), i);
	return	0;
}

int	alx_cv_erode		(void *img, ptrdiff_t i)
{
	return	alx::CV::erode((class cv::Mat *)img, i);
}

int	alx::CV::erode_h	(class cv::Mat *img, ptrdiff_t i)
{
	class cv::Mat	k;

	if (i < 1)
		return	1;
	k	= cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 1));
	cv::erode(*img, *img, k, cv::Point(-1,-1), i);
	k.release();
	return	0;
}

int	alx_cv_erode_h		(void *img, ptrdiff_t i)
{
	return	alx::CV::erode_h((class cv::Mat *)img, i);
}

int	alx::CV::erode_v	(class cv::Mat *img, ptrdiff_t i)
{
	class cv::Mat	k;

	if (i < 1)
		return	1;
	k	= cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, 3));
	cv::erode(*img, *img, k, cv::Point(-1,-1), i);
	k.release();
	return	0;
}

int	alx_cv_erode_v		(void *img, ptrdiff_t i)
{
	return	alx::CV::erode_v((class cv::Mat *)img, i);
}

int	alx::CV::dilate_erode	(class cv::Mat *img, ptrdiff_t i)
{

	if (alx::CV::dilate(img, i))
		return	1;
	if (alx::CV::erode(img, i))
		return	1;

	return	0;
}

int	alx_cv_dilate_erode	(void *img, ptrdiff_t i)
{
	return	alx::CV::dilate_erode((class cv::Mat *)img, i);
}

int	alx::CV::erode_dilate	(class cv::Mat *img, ptrdiff_t i)
{

	if (alx::CV::erode(img, i))
		return	1;
	if (alx::CV::dilate(img, i))
		return	1;

	return	0;
}

int	alx_cv_erode_dilate	(void *img, ptrdiff_t i)
{
	return	alx::CV::erode_dilate((class cv::Mat *)img, i);
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
