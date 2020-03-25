/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/miscellaneous/fill.h */


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
int	alx_cv_bkgd_mask	(img_s *img);
__attribute__((nonnull))
int	alx_cv_bkgd_fill	(img_s *img);
__attribute__((nonnull))
int	alx_cv_holes_mask	(img_s *img);
__attribute__((nonnull))
int	alx_cv_holes_fill	(img_s *img);
__attribute__((nonnull))
int	alx_cv_holes_mask_fill	(img_s *img);
__attribute__((nonnull))
int	alx_cv_holes_remove	(img_s *img);
__attribute__((nonnull))
int	alx_cv_holes_extract	(img_s *img);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
