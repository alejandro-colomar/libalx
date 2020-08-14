/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx/lines.hxx"

#include <cstdbool>
#include <cstddef>
#include <cstdint>

#include <opencv2/core/mat.hpp>


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
int	alx::CV::lines_horizontal	(class cv::Mat *img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	bool		white;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
		white	= false;
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			if (*pix) {
				white	= true;
				break;
			}
		}
		if (!white)
			continue;
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			*pix	= UINT8_MAX;
		}
	}
	return	0;
}

int	alx_cv_lines_horizontal		(void *img)
{
	return	alx::CV::lines_horizontal((class cv::Mat *)img);
}

int	alx::CV::lines_vertical		(class cv::Mat *img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	bool		white;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < cols; i++) {
		white	= false;
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			if (*pix) {
				white	= true;
				break;
			}
		}
		if (!white)
			continue;
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			*pix	= UINT8_MAX;
		}
	}
	return	0;
}

int	alx_cv_lines_vertical		(void *img)
{
	return	alx::CV::lines_vertical((class cv::Mat *)img);
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
