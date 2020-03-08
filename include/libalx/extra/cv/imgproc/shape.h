/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/shape.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/types.h"


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
__attribute__((nonnull))
int	alx_cv_contours		(img_s *restrict img,
				 conts_s *restrict contours);
__attribute__((nonnull(1)))
void	alx_cv_contour_dimensions(const cont_s *restrict cont,
				 double *restrict area,
				 double *restrict perimeter);
__attribute__((nonnull(3), warn_unused_result))
int	alx_cv_conts_largest	(const cont_s **restrict cont,
				 ptrdiff_t *restrict i,
				 const conts_s *restrict conts);
__attribute__((nonnull, warn_unused_result))
int	alx_cv_contour_mask	(const img_s **restrict img,
				 const conts_s *restrict conts, ptrdiff_t i)
__attribute__((nonnull))
void	alx_cv_bounding_rect	(rect_s *restrict rect,
				 const cont_s *restrict contour);
__attribute__((nonnull))
void	alx_cv_fit_ellipse	(rect_rot_s *restrict rect_rot,
				 const cont_s *restrict contour);
__attribute__((nonnull))
void	alx_cv_min_area_rect	(rect_rot_s *restrict rect_rot,
				 const cont_s *restrict contour);
__attribute__((nonnull))
void	alx_cv_draw_rect	(img_s *restrict img,
				 const rect_s *restrict rect);
__attribute__((nonnull))
void	alx_cv_draw_rect_rot	(img_s *restrict img,
				 const rect_rot_s *restrict rect_rot);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
