/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx/mean.hxx"

#include <cstddef>
#include <cstdint>

#include <opencv2/core/mat.hpp>

#include "libalx/extra/gsl/statistics/mean.hxx"


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
int	alx::CV::mean_horizontal	(class cv::Mat *img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	__extension__
	uint8_t		row[cols];
	uint8_t		mean;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			row[j]	= *pix;
		}
		mean	= alx_gsl_stats_mean_u8(cols, row);
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			*pix	= mean;
		}
	}
	return	0;
}

int	alx_cv_mean_horizontal		(void *img)
{
	return	alx::CV::mean_horizontal((class cv::Mat *)img);
}

int	alx::CV::mean_vertical		(class cv::Mat *img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	__extension__
	uint8_t		col[rows];
	uint8_t		mean;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < cols; i++) {
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			col[j]	= *pix;
		}
		mean	= alx_gsl_stats_mean_u8(rows, col);
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			*pix	= mean;
		}
	}
	return	0;
}

int	alx_cv_mean_vertical		(void *img)
{
	return	alx::CV::mean_vertical((class cv::Mat *)img);
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
