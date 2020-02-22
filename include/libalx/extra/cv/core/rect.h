/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/core/rect.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include "libalx/extra/cv/core/types.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/* ----- alloc / free */
__attribute__((nonnull))
int	alx_cv_alloc_rect	(rect_s **rect);
__attribute__((nonnull))
void	alx_cv_free_rect	(rect_s *rect);
__attribute__((nonnull))
int	alx_cv_alloc_rect_rot	(rect_rot_s **rect_rot);
__attribute__((nonnull))
void	alx_cv_free_rect_rot	(rect_rot_s *rect_rot);
/* ----- init / deinit */
__attribute__((nonnull))
int	alx_cv_init_rect	(rect_s *rect,
				 ptrdiff_t x, ptrdiff_t y,
				 ptrdiff_t w, ptrdiff_t h);
/* ----- Extract */
__attribute__((nonnull(1)))
void	alx_cv_extract_rect	(const rect_s *restrict rect,
				 ptrdiff_t *restrict x, ptrdiff_t *restrict y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h);
__attribute__((nonnull(1)))
void	alx_cv_extract_rect_rot	(const rect_rot_s *restrict rect_rot,
				 ptrdiff_t *restrict ctr_x,
				 ptrdiff_t *restrict ctr_y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h,
				 double *restrict angle);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
