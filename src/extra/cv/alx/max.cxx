/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx/max.hxx"

#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstring>

#include <opencv2/core/mat.hpp>

#include "libalx/base/compiler/restrict.hxx"
#include "libalx/base/compiler/size.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/
enum	Cell {
	NOT_LOCAL_MAX,
	MAYBE_LOCAL_MAX,
	LOCAL_MAX
};


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx::CV::maximum_flt		(const class cv::Mat *restrict img,
					 float *restrict max)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	float	img_pix;

	if (img->channels() != 1)
		return	-1;

	*max	= 0.0f;
	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		img_pix		= img->at<float>(i, j);
		if (img_pix > *max)
			*max = img_pix;
	}
	}

	return	0;
}

int	alx_cv_maximum_flt		(const void *restrict img,
					 float *restrict max)
{
	return	alx::CV::maximum_flt((const class cv::Mat *)img, max);
}

int	alx::CV::maximum_u8		(const class cv::Mat *restrict img,
					 uint8_t *restrict max)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	uint8_t	img_pix;

	if (img->channels() != 1)
		return	-1;

	*max	= 0;
	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		img_pix		= img->at<uint8_t>(i, j);
		if (img_pix > *max)
			*max = img_pix;
	}
	}

	return	0;
}

int	alx_cv_maximum_u8		(const void *restrict img,
					 uint8_t *restrict max)
{
	return	alx::CV::maximum_u8((const class cv::Mat *)img, max);
}

int	alx::CV::local_max		(class cv::Mat *img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	/* Minimum distance between local maxima */
	const int	dist = 8;
	/* Minimum value of local maxima */
	const float	val_min = 2.0f;
	class cv::Mat	imgtmp;
	__extension__
	int		arr_tmp[rows][cols];
	bool		wh;
	/* pointer to a pixel (in img) */
	float		img_pix;
	/* pointer to a pixel near img_pix (in img) */
	float		near_pix;

	if (img->channels() != 1)
		return	1;
	/* Tmp image copy */
	img->copyTo(imgtmp);
	imgtmp.convertTo(imgtmp, CV_8U);
	imgtmp	= cv::Scalar(UINT8_MAX);

	memset(arr_tmp, 0, ARRAY_BYTES__(arr_tmp));
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
	for (ptrdiff_t j = 0; j < cols; j++) {
		img_pix		= img->at<float>(i, j);

		if (img_pix < val_min)
			continue;
		for (ptrdiff_t k = (i + dist); k >= (i - dist); k--) {
		for (ptrdiff_t l = (j + dist); l >= (j - dist); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
			if ((l != i) || (k != j)) {
				near_pix	= img->at<float>(k, l);
				if (near_pix > img_pix)
					goto not_maxima;
				if (near_pix == img_pix)
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		arr_tmp[i][j]	= NOT_LOCAL_MAX;
		;
	}
	}

	do {
		wh	= false;
#pragma GCC ivdep
		for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
		for (ptrdiff_t j = 0; j < cols; j++) {
			img_pix		= img->at<float>(i, j);
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = (i+dist); k >= (i-dist); k--) {
			for (ptrdiff_t l = (j+dist); l >= (j-dist); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
				if ((l != i) || (k != j)) {
					near_pix = img->at<float>(k, l);
					if (near_pix == img_pix) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= 0;
		}
		}
	} while (wh);

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
	for (ptrdiff_t j = 0; j < cols; j++) {
		if (!arr_tmp[i][j])
			imgtmp.at<uint8_t>(i, j)	= 0;
	}
	}

	imgtmp.copyTo(*img);
	imgtmp.release();
	return	0;
}

int	alx_cv_local_max		(void *img)
{
	return	alx::CV::local_max((class cv::Mat *)img);
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
