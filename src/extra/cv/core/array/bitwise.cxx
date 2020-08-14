/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/core/array/bitwise.hxx"

#include <opencv2/core/mat.hpp>
#include <opencv2/core.hpp>

#include "libalx/base/compiler/restrict.hxx"


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

void	alx::CV::invert		(class cv::Mat *img)
{
	cv::bitwise_not(*img, *img);
}

void	alx_cv_invert		(void *img)
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

int	alx::CV::xor_2ref	(class cv::Mat *restrict img,
				 const class cv::Mat *restrict ref)
{

	if (img->channels() != ref->channels())
		return	1;
	cv::bitwise_xor(*img, *ref, *img);

	return	0;
}

int	alx_cv_xor_2ref		(void *restrict img, const void *restrict ref)
{
	return	alx::CV::xor_2ref((class cv::Mat *)img,
						(const class cv::Mat *)ref);
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
