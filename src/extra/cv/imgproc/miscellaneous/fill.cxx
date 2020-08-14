/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/miscellaneous/fill.hxx"

#include <cstdint>

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#include "libalx/extra/cv/imgproc/filter/border.hxx"


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
int	alx::CV::bkgd_fill	(class cv::Mat *img)
{

	if (img->channels() != 1)
		return	1;
	alx::CV::border_black(img, 1);
	cv::floodFill(*img, cv::Point(0, 0), UINT8_MAX);
	alx::CV::rm_border(img, 1);
	return	0;
}

int	alx_cv_bkgd_fill	(void *img)
{
	return	alx::CV::bkgd_fill((class cv::Mat *)img);
}

int	alx::CV::bkgd_mask	(class cv::Mat *img)
{
	class cv::Mat	tmp;

	img->copyTo(tmp);
	if (alx::CV::bkgd_fill(&tmp))
		return	1;
	cv::bitwise_xor(*img, tmp, *img);

	tmp.release();
	return	0;
}

int	alx_cv_bkgd_mask	(void *img)
{
	return	alx::CV::bkgd_mask((class cv::Mat *)img);
}

int	alx::CV::holes_mask	(class cv::Mat *img)
{

	if (alx::CV::bkgd_fill(img))
		return	1;
	cv::bitwise_not(*img, *img);
	return	0;
}

int	alx_cv_holes_mask	(void *img)
{
	return	alx::CV::holes_mask((class cv::Mat *)img);
}

int	alx::CV::holes_fill	(class cv::Mat *img)
{

	if (alx::CV::bkgd_mask(img))
		return	1;
	cv::bitwise_not(*img, *img);
	return	0;
}

int	alx_cv_holes_fill	(void *img)
{
	return	alx::CV::holes_fill((class cv::Mat *)img);
}

int	alx::CV::holes_mask_fill(class cv::Mat *img)
{

	if (alx::CV::holes_mask(img))
		return	1;
	alx::CV::holes_fill(img);
	return	0;
}

int	alx_cv_holes_mask_fill	(void *img)
{
	return	alx::CV::holes_mask_fill((class cv::Mat *)img);
}

int	alx::CV::holes_remove(class cv::Mat *img)
{
	class cv::Mat	mask;

	img->copyTo(mask);
	if (alx::CV::holes_mask_fill(&mask))
		return	1;
	cv::bitwise_not(mask, mask);
	cv::bitwise_and(*img, mask, *img);
	return	0;
}

int	alx_cv_holes_remove	(void *img)
{
	return	alx::CV::holes_remove((class cv::Mat *)img);
}

int	alx::CV::holes_extract(class cv::Mat *img)
{
	class cv::Mat	mask;

	img->copyTo(mask);
	if (alx::CV::holes_mask_fill(&mask))
		return	1;
	cv::bitwise_and(*img, mask, *img);
	return	0;
}

int	alx_cv_holes_extract	(void *img)
{
	return	alx::CV::holes_extract((class cv::Mat *)img);
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
