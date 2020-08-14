/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/core/rect/rect.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstddef>

#include <opencv2/core/base.hpp>

#include "libalx/base/compiler/restrict.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern "C" {


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* C prototypes *********************************************************
 ******************************************************************************/
/* ----- Alloc */
[[gnu::nonnull]]
int	alx_cv_init_rect	(void **rect);
void	alx_cv_deinit_rect	(void *rect);
[[gnu::nonnull]]
int	alx_cv_init_rect_rot	(void **rect_rot);
void	alx_cv_deinit_rect_rot	(void *rect_rot);
/* ----- Init */
[[gnu::nonnull]]
int	alx_cv_set_rect		(void *rect,
				 ptrdiff_t x, ptrdiff_t y,
				 ptrdiff_t w, ptrdiff_t h);
/* ----- Extract */
[[gnu::nonnull(1)]]
void	alx_cv_extract_rect	(const void *restrict rect,
				 ptrdiff_t *restrict x, ptrdiff_t *restrict y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h);
[[gnu::nonnull(1)]]
void	alx_cv_extract_rect_rot	(const void *restrict rect_rot,
				 ptrdiff_t *restrict ctr_x,
				 ptrdiff_t *restrict ctr_y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h,
				 double *restrict angle);

[[gnu::nonnull]]
void	alx_cv_rect_within_img	(const void *restrict img, void *restrict rect);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
}	/* extern "C" */


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/* ----- Alloc */
[[gnu::nonnull]]
int	init_rect	(class cv::Rect_<int> **rect);
void	deinit_rect	(class cv::Rect_<int> *rect);
[[gnu::nonnull]]
int	init_rect_rot	(class cv::RotatedRect **rect_rot);
void	deinit_rect_rot	(class cv::RotatedRect *rect_rot);
/* ----- Init */
[[gnu::nonnull]]
int	set_rect	(class cv::Rect_<int> *rect,
			 ptrdiff_t x, ptrdiff_t y, ptrdiff_t w, ptrdiff_t h);
/* ----- Extract */
[[gnu::nonnull(1)]]
void	extract_rect	(const class cv::Rect_<int> *restrict rect,
			 ptrdiff_t *restrict x, ptrdiff_t *restrict y,
			 ptrdiff_t *restrict w, ptrdiff_t *restrict h);
[[gnu::nonnull(1)]]
void	extract_rect_rot(const class cv::RotatedRect *restrict rect_rot,
			 ptrdiff_t *restrict ctr_x, ptrdiff_t *restrict ctr_y,
			 ptrdiff_t *restrict w, ptrdiff_t *restrict h,
			 double *restrict angle);

[[gnu::nonnull]]
void	rect_within_img	(const class cv::Mat *restrict img,
			 class cv::Rect_<int> *restrict rect);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
