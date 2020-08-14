/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx/gray.hxx"

#include <cstdint>

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#include "libalx/extra/cv/core/array/component.hxx"


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
int	alx::CV::white_mask	(class cv::Mat *img, int16_t SL_tolerance,
				 int16_t L_tolerance, int16_t S_tolerance)
{
	class cv::Mat	cmp_img[3];
	class cv::Mat	tmp;

	if (img->channels() != 3)
		return	1;
	cv::cvtColor(*img, *img, cv::COLOR_BGR2HLS, 0);
	cv::split(*img, cmp_img);
	img->release();
	cmp_img[0].copyTo(*img);
	img->setTo(cv::Scalar(0));
	/* light white */
	if (L_tolerance >= 0)
		cv::threshold(cmp_img[alx::CV::CMP_HLS_L], *img,
				UINT8_MAX - L_tolerance - 1,
				UINT8_MAX, cv::THRESH_BINARY);
	/* grayish white */
	if (S_tolerance >= 0) {
		cv::threshold(cmp_img[alx::CV::CMP_HLS_L], cmp_img[0],
				UINT8_MAX / 2, UINT8_MAX, cv::THRESH_BINARY);
		cv::threshold(cmp_img[alx::CV::CMP_HLS_S], tmp,
				S_tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
		cv::bitwise_and(cmp_img[0], tmp, tmp);
		cv::bitwise_or(*img, tmp, *img);
	}
	/* pure white */
	if (SL_tolerance >= 0) {
		cv::threshold(cmp_img[alx::CV::CMP_HLS_L],
				cmp_img[alx::CV::CMP_HLS_L],
				UINT8_MAX - SL_tolerance - 1,
				UINT8_MAX, cv::THRESH_BINARY);
		cv::threshold(cmp_img[alx::CV::CMP_HLS_S],
				cmp_img[alx::CV::CMP_HLS_S],
				SL_tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
		cv::bitwise_and(cmp_img[alx::CV::CMP_HLS_S],
				cmp_img[alx::CV::CMP_HLS_L],
				cmp_img[alx::CV::CMP_HLS_S]);
		cv::bitwise_or(*img, cmp_img[alx::CV::CMP_HLS_S], *img);
	}

	for (ptrdiff_t i = 0; i < 3; i++)
		cmp_img[i].release();
	tmp.release();
	return	0;
}

int	alx_cv_white_mask	(void *img, int16_t SL_tolerance,
				 int16_t L_tolerance, int16_t S_tolerance)
{
	return	alx::CV::white_mask((class cv::Mat *)img, SL_tolerance,
						L_tolerance, S_tolerance);
}

int	alx::CV::black_mask	(class cv::Mat *img, int16_t SL_tolerance,
				 int16_t L_tolerance, int16_t S_tolerance)
{
	class cv::Mat	cmp_img[3];
	class cv::Mat	tmp;

	if (img->channels() != 3)
		return	1;
	cv::cvtColor(*img, *img, cv::COLOR_BGR2HLS, 0);
	cv::split(*img, cmp_img);
	img->release();
	cmp_img[0].copyTo(*img);
	img->setTo(cv::Scalar(0));
	/* dark black */
	if (L_tolerance >= 0)
		cv::threshold(cmp_img[alx::CV::CMP_HLS_L], *img,
				L_tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
	/* grayish black */
	if (S_tolerance >= 0) {
		cv::threshold(cmp_img[alx::CV::CMP_HLS_L], cmp_img[0],
				UINT8_MAX /2, UINT8_MAX, cv::THRESH_BINARY_INV);
		cv::threshold(cmp_img[alx::CV::CMP_HLS_S], tmp,
				S_tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
		cv::bitwise_and(cmp_img[0], tmp, tmp);
		cv::bitwise_or(*img, tmp, *img);
	}
	/* pure black */
	if (SL_tolerance >= 0) {
		cv::threshold(cmp_img[alx::CV::CMP_HLS_L],
				cmp_img[alx::CV::CMP_HLS_L],
				SL_tolerance,
				UINT8_MAX, cv::THRESH_BINARY_INV);
		cv::threshold(cmp_img[alx::CV::CMP_HLS_S],
				cmp_img[alx::CV::CMP_HLS_S],
				SL_tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
		cv::bitwise_and(cmp_img[alx::CV::CMP_HLS_S],
				cmp_img[alx::CV::CMP_HLS_L],
				cmp_img[alx::CV::CMP_HLS_S]);
		cv::bitwise_or(*img, cmp_img[alx::CV::CMP_HLS_S], *img);
	}

	for (ptrdiff_t i = 0; i < 3; i++)
		cmp_img[i].release();
	tmp.release();
	return	0;
}

int	alx_cv_black_mask	(void *img, int16_t SL_tolerance,
				 int16_t L_tolerance, int16_t S_tolerance)
{
	return	alx::CV::black_mask((class cv::Mat *)img, SL_tolerance,
						L_tolerance, S_tolerance);
}

int	alx::CV::gray_mask	(class cv::Mat *img, int16_t SL_tolerance,
				 int16_t L_tolerance, int16_t S_tolerance)
{
	class cv::Mat	cmp_img[3];
	class cv::Mat	tmp;

	if (img->channels() != 3)
		return	1;
	cv::cvtColor(*img, *img, cv::COLOR_BGR2HLS, 0);
	cv::split(*img, cmp_img);
	img->release();
	cmp_img[0].copyTo(*img);
	img->setTo(cv::Scalar(0));
	/* light B&W */
	if (L_tolerance >= 0) {
		/* light white */
		cv::threshold(cmp_img[alx::CV::CMP_HLS_L], *img,
				UINT8_MAX - L_tolerance - 1,
				UINT8_MAX, cv::THRESH_BINARY);
		/* dark black */
		cv::threshold(cmp_img[alx::CV::CMP_HLS_L], tmp,
				L_tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
		cv::bitwise_or(*img, tmp, *img);
	}
	/* gray */
	if (S_tolerance >= 0) {
		cv::threshold(cmp_img[alx::CV::CMP_HLS_S], tmp,
				S_tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
		cv::bitwise_or(*img, tmp, *img);
	}
	/* pure B&W */
	if (SL_tolerance >= 0) {
		cv::threshold(cmp_img[alx::CV::CMP_HLS_L], tmp,
				UINT8_MAX - SL_tolerance - 1,
				UINT8_MAX, cv::THRESH_BINARY);
		cv::threshold(cmp_img[alx::CV::CMP_HLS_L], cmp_img[0],
				SL_tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
		cv::bitwise_or(tmp, cmp_img[0], cmp_img[alx::CV::CMP_HLS_L]);
		cv::threshold(cmp_img[alx::CV::CMP_HLS_S],
				cmp_img[alx::CV::CMP_HLS_S],
				SL_tolerance, UINT8_MAX, cv::THRESH_BINARY_INV);
		cv::bitwise_and(cmp_img[alx::CV::CMP_HLS_S],
				cmp_img[alx::CV::CMP_HLS_L],
				cmp_img[alx::CV::CMP_HLS_S]);
		cv::bitwise_or(*img, cmp_img[alx::CV::CMP_HLS_S], *img);
	}

	for (ptrdiff_t i = 0; i < 3; i++)
		cmp_img[i].release();
	tmp.release();
	return	0;
}

int	alx_cv_gray_mask	(void *img, int16_t SL_tolerance,
				 int16_t L_tolerance, int16_t S_tolerance)
{
	return	alx::CV::gray_mask((class cv::Mat *)img, SL_tolerance,
						L_tolerance, S_tolerance);
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
