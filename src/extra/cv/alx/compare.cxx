/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx/compare.hxx"

#include <cmath>
#include <cstddef>
#include <cstdint>

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#include "libalx/base/compiler/restrict.hxx"
#include "libalx/extra/cv/imgproc/geometric/resize.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#include <opencv2/highgui.hpp>

/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
double	alx::CV::compare_bitwise	(const class cv::Mat *restrict img_a,
					 const class cv::Mat *restrict img_b,
					 double power)
{
	class cv::Mat	a;
	class cv::Mat	b;
	class cv::Mat	dt_a;
	class cv::Mat	dt_b;
	class cv::Mat	dt;
	class cv::Mat	_or;
	class cv::Mat	_and;
	double		sum;
	double		n;
	double		mean;
	double		match;

	if (img_a->channels() != 1)
		return	-1;
	if (img_b->channels() != 1)
		return	-2;
	img_a->copyTo(a);
	img_b->copyTo(b);

	alx::CV::resize_2largest(&a, &b);

	cv::bitwise_or(a, b, _or);

	cv::bitwise_not(a, a);
	cv::bitwise_not(b, b);
	cv::distanceTransform(a, dt_a, cv::DIST_L2, cv::DIST_MASK_PRECISE);
	cv::distanceTransform(b, dt_b, cv::DIST_L2, cv::DIST_MASK_PRECISE);
	cv::max(dt_a, dt_b, dt);
	cv::pow(dt, power, dt);

	cv::bitwise_and(dt, dt, _and, _or);
	sum	= cv::sum(_and)[0];
	n	= cv::countNonZero(_and);
	if (!n) {
		match	= 1.0;
	} else {
		mean	= sum / n;
		mean	= pow(mean, 1.0 / power);
		match	= 1.0 - mean / UINT8_MAX;
	}

	_and.release();
	_or.release();
	dt.release();
	dt_b.release();
	dt_a.release();
	b.release();
	a.release();

	return	match;
}

double	alx_cv_compare_bitwise		(const void *restrict img_a,
					 const void *restrict img_b,
					 double power)
{
	return	alx::CV::compare_bitwise((const class cv::Mat *)img_a,
						(const class cv::Mat *)img_b,
						power);
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
