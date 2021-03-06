/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/miscellaneous/fill.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/types.h"


/******************************************************************************
 ******* define ***************************************************************
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
[[gnu::nonnull]]
int	alx_cv_bkgd_mask	(img_s *img);
[[gnu::nonnull]]
int	alx_cv_bkgd_fill	(img_s *img);
[[gnu::nonnull]]
int	alx_cv_holes_mask	(img_s *img);
[[gnu::nonnull]]
int	alx_cv_holes_fill	(img_s *img);
[[gnu::nonnull]]
int	alx_cv_holes_mask_fill	(img_s *img);
[[gnu::nonnull]]
int	alx_cv_holes_remove	(img_s *img);
[[gnu::nonnull]]
int	alx_cv_holes_extract	(img_s *img);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
