/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/alx/fill.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <opencv2/core/base.hpp>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]]
int	alx_cv_bkgd_mask	(void *img);
[[gnu::nonnull]]
int	alx_cv_bkgd_fill	(void *img);
[[gnu::nonnull]]
int	alx_cv_holes_mask	(void *img);
[[gnu::nonnull]]
int	alx_cv_holes_fill	(void *img);
[[gnu::nonnull]]
int	alx_cv_holes_mask_fill	(void *img);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


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
int	bkgd_mask	(class cv::Mat *img);
[[gnu::nonnull]]
int	bkgd_fill	(class cv::Mat *img);
[[gnu::nonnull]]
int	holes_mask	(class cv::Mat *img);
[[gnu::nonnull]]
int	holes_fill	(class cv::Mat *img);
[[gnu::nonnull]]
int	holes_mask_fill	(class cv::Mat *img);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
