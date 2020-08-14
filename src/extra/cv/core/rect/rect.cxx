/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/core/rect/rect.hxx"

#include <cstddef>

#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

#include "libalx/base/compiler/restrict.hxx"
#include "libalx/base/stdlib/alloc/mallocarrays.hxx"
#include "libalx/base/stdlib/swap.hxx"


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
/* ----- alloc / free */
int	alx::CV::init_rect	(class cv::Rect_<int> **rect)
{
	return	alx_mallocarrays(rect, 1);
}

int	alx_cv_init_rect	(void **rect)
{
	return	alx::CV::init_rect((class cv::Rect_<int> **)rect);
}

void	alx::CV::deinit_rect	(class cv::Rect_<int> *rect)
{
	free(rect);
}

void	alx_cv_deinit_rect	(void *rect)
{
	alx::CV::deinit_rect((class cv::Rect_<int> *)rect);
}

int	alx::CV::init_rect_rot	(class cv::RotatedRect **rect_rot)
{
	return	alx_mallocarrays(rect_rot, 1);
}

int	alx_cv_init_rect_rot	(void **rect_rot)
{
	return	alx::CV::init_rect_rot((class cv::RotatedRect **)rect_rot);
}

void	alx::CV::deinit_rect_rot(class cv::RotatedRect *rect_rot)
{
	free(rect_rot);
}

void	alx_cv_deinit_rect_rot	(void *restrict rect_rot)
{
	alx::CV::deinit_rect_rot((class cv::RotatedRect *)rect_rot);
}

/* ----- init / deinit */
int	alx::CV::set_rect	(class cv::Rect_<int> *rect,
				 ptrdiff_t x, ptrdiff_t y,
				 ptrdiff_t w, ptrdiff_t h)
{

	rect->x		= x;
	rect->y		= y;
	rect->width	= w;
	rect->height	= h;

	if (x < 0 || y < 0 || w < 1 || h < 1)
		return	1;
	return	0;
}

int	alx_cv_set_rect		(void *rect,
				 ptrdiff_t x, ptrdiff_t y,
				 ptrdiff_t w, ptrdiff_t h)
{
	return	alx::CV::set_rect((class cv::Rect_<int> *)rect, x, y, w, h);
}

/* ----- Extract */
void	alx::CV::extract_rect	(const class cv::Rect_<int> *restrict rect,
				 ptrdiff_t *restrict x, ptrdiff_t *restrict y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h)
{

	if (x)
		*x = rect->x;
	if (y)
		*y = rect->y;
	if (w)
		*w = rect->width;
	if (h)
		*h = rect->height;
}

void	alx_cv_extract_rect	(const void *restrict rect,
				 ptrdiff_t *restrict x, ptrdiff_t *restrict y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h)
{
	alx::CV::extract_rect((const class cv::Rect_<int> *)rect, x, y, w, h);
}

void	alx::CV::extract_rect_rot(const class cv::RotatedRect *restrict rect_rot,
				 ptrdiff_t *restrict ctr_x,
				 ptrdiff_t *restrict ctr_y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h,
				 double *restrict angle)
{

	if (ctr_x)
		*ctr_x	= rect_rot->center.x;
	if (ctr_y)
		*ctr_y	= rect_rot->center.y;
	if (w)
		*w	= rect_rot->size.width;
	if (h)
		*h	= rect_rot->size.height;
	if (angle) {
		*angle	= rect_rot->angle;
		/* If angle < -45º, it is taking the incorrect side */
		if (*angle < -45.0) {
			*angle += 90.0;
			ALX_SWAP(w, h);
		}
	}
}

void	alx_cv_extract_rect_rot	(const void *restrict rect_rot,
				 ptrdiff_t *restrict ctr_x,
				 ptrdiff_t *restrict ctr_y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h,
				 double *restrict angle)
{
	alx::CV::extract_rect_rot((const class cv::RotatedRect *)rect_rot,
						ctr_x, ctr_y, w, h, angle);
}

void	alx::CV::rect_within_img(const class cv::Mat *restrict img,
				 class cv::Rect_<int> *restrict rect)
{
	ptrdiff_t	rx, ry, rw, rh;
	ptrdiff_t	iw, ih;

	rx	= rect->x;
	ry	= rect->y;
	rw	= rect->width;
	rh	= rect->height;
	iw	= img->cols;
	ih	= img->rows;

	if (rx + rw > iw)
		rw	= iw - rx;
	if (ry + rh > ih)
		rh	= ih - ry;
	if (rx < 0) {
		rw	+= rx;
		rx	= 0;
	}
	if (ry < 0) {
		rh	+= ry;
		ry	= 0;
	}

	rect->x		= rx;
	rect->y		= ry;
	rect->width	= rw;
	rect->height	= rh;
}

void	alx_cv_rect_within_img	(const void *restrict img, void *restrict rect)
{
	alx::CV::rect_within_img((const class cv::Mat *)img,
					(class cv::Rect_<int> *)rect);
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
