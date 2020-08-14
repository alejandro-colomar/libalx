/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/core/img/img.hxx"

#include <cstddef>

#include <memory>

#include <opencv2/core/mat.hpp>

#include "libalx/base/compiler/restrict.hxx"
#include "libalx/base/stdlib/alloc/mallocarrays.hxx"


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
/* ----- init / deinit */
int	alx::CV::init_img	(class cv::Mat **img)
{

	if (alx_mallocarrays(img, 1))
		return	-1;
	new (*img)	cv::Mat(cv::Size(1, 1), CV_8UC3, 0.0);

	return	0;
}

int	alx_cv_init_img		(void **img)
{
	return	alx::CV::init_img((class cv::Mat **)img);
}

void	alx::CV::deinit_img	(class cv::Mat *img)
{

	if (!img)
		return;
	std::destroy_at(img);
	free(img);
}

void	alx_cv_deinit_img	(void *img)
{
	alx::CV::deinit_img((class cv::Mat *)img);
}

/* ----- Extract */
void	alx::CV::extract_imgdata(const class cv::Mat *restrict img,
				 void **restrict data,
				 ptrdiff_t *restrict w,
				 ptrdiff_t *restrict h,
				 ptrdiff_t *restrict B_per_pix,
				 ptrdiff_t *restrict B_per_line,
				 int *restrict type)
{

	if (data)
		*data		= img->data;
	if (w)
		*w		= img->cols;
	if (h)
		*h		= img->rows;
	if (B_per_pix)
		*B_per_pix	= img->channels();
	if (B_per_line)
		*B_per_line	= img->step1();
	if (type)
		*type		= img->type();
}

void	alx_cv_extract_imgdata	(const void *restrict img,
				 void **restrict data,
				 ptrdiff_t *restrict w,
				 ptrdiff_t *restrict h,
				 ptrdiff_t *restrict B_per_pix,
				 ptrdiff_t *restrict B_per_line,
				 int *restrict type)
{
	alx::CV::extract_imgdata((const class cv::Mat *)img, data, w, h,
						B_per_pix, B_per_line, type);
}

/* ----- Copy */
void	alx::CV::clone		(class cv::Mat *restrict clone,
				 const class cv::Mat *restrict img)
{
	img->copyTo(*clone);
}

void	alx_cv_clone		(void *restrict clone, const void *restrict img)
{
	alx::CV::clone((class cv::Mat *)clone, (const class cv::Mat *)img);
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
