/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/core/array/minmax.hxx"

#include <opencv2/core/mat.hpp>
#include <opencv2/core.hpp>


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
void	alx::CV::max	(class cv::Mat *max,
			 const class cv::Mat *a, const class cv::Mat *b)
{
	cv::max(*a, *b, *max);
}

void	alx_cv_max	(void *max, const void *a, const void *b)
{
	return	alx::CV::max((class cv::Mat *)max, (const class cv::Mat *)a,
						(const class cv::Mat *)b);
}

void	alx::CV::min	(class cv::Mat *min,
			 const class cv::Mat *a, const class cv::Mat *b)
{
	cv::min(*a, *b, *min);
}

void	alx_cv_min	(void *min, const void *a, const void *b)
{
	return	alx::CV::min((class cv::Mat *)min, (const class cv::Mat *)a,
						(const class cv::Mat *)b);
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
