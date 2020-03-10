/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/miscellaneous/color.hpp"

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
int	alx::CV::cvt_color		(class cv::Mat *img, int method)
{

	if (method < 0 || method > cv::COLOR_COLORCVT_MAX)
		return	1;
	cv::cvtColor(*img, *img, method, 0);

	return	0;
}

int	alx_cv_cvt_color		(void *img, int method)
{
	return	alx::CV::cvt_color((class cv::Mat *)img, method);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
