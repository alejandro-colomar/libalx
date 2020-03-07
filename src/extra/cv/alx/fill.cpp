/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx/fill.hpp"

#include <cstdint>

#include <opencv2/core.hpp>
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
void	alx::CV::bkgd_mask	(class cv::Mat *img)
{
	cv::floodFill(*img, cv::Point(0, 0), UINT8_MAX);
}

void	alx_cv_bkgd_mask	(void *img)
{
	alx::CV::bkgd_mask((class cv::Mat *)img);
}

void	alx::CV::bkgd_fill	(class cv::Mat *img)
{
	class cv::Mat	tmp;

	img->copyTo(tmp);
	alx::CV::bkgd_mask(&tmp);
	cv::bitwise_or(*img, tmp, *img);

	tmp.release();
}

void	alx_cv_bkgd_fill	(void *img)
{
	alx::CV::bkgd_fill((class cv::Mat *)img);
}

void	alx::CV::holes_mask	(class cv::Mat *img)
{

	alx::CV::bkgd_fill(img);
	cv::bitwise_not(*img, *img);
}

void	alx_cv_holes_mask	(void *img)
{
	alx::CV::holes_mask((class cv::Mat *)img);
}

void	alx::CV::holes_fill	(class cv::Mat *img)
{

	alx::CV::bkgd_mask(img);
	cv::bitwise_not(*img, *img);
}

void	alx_cv_holes_fill	(void *img)
{
	alx::CV::holes_fill((class cv::Mat *)img);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/