/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx/median.hxx"

#include <cstddef>
#include <cstdint>

#include <opencv2/core/mat.hpp>

#include "libalx/extra/gsl/rstat/median.hxx"


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
int	alx::CV::median_horizontal	(class cv::Mat *img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	__extension__
	uint8_t		row[cols];
	uint8_t		median;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	-1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			row[j]	= *pix;
		}
		median	= alx_gsl_rstat_median_u8(cols, row);
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			*pix	= median;
		}
	}
	return	0;
}

int	alx_cv_median_horizontal	(void *img)
{
	return	alx::CV::median_horizontal((class cv::Mat *)img);
}

int	alx::CV::median_vertical	(class cv::Mat *img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	__extension__
	uint8_t		col[rows];
	uint8_t		median;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	-1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < cols; i++) {
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			col[j]	= *pix;
		}
		median	= alx_gsl_rstat_median_u8(rows, col);
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			*pix	= median;
		}
	}
	return	0;
}

int	alx_cv_median_vertical		(void *img)
{
	return	alx::CV::median_vertical((class cv::Mat *)img);
}

int	alx::CV::median			(class cv::Mat *img)
{
	const ptrdiff_t	rows	= img->rows;
	const ptrdiff_t	cols	= img->cols;
	const ptrdiff_t	step	= img->step;
	const ptrdiff_t	sz	= step * rows;
	uint8_t		*data	= img->data;
	uint8_t		median;
	uint8_t		*pix;

	if (img->channels() != 1)
		return	-1;

	median	= alx_gsl_rstat_median_u8(sz, data);
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < cols; i++) {
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= data + j * step + i;
			*pix	= median;
		}
	}
	return	median;
}

int	alx_cv_median			(void *img)
{
	return	alx::CV::median((class cv::Mat *)img);
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
