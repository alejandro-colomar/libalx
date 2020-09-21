/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/alx/gray.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdint>

#include <opencv2/core/base.hpp>


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
[[gnu::nonnull]]
int	alx_cv_white_mask	(void *img, int16_t SL_tolerance,
				 int16_t S_tolerance, int16_t L_tolerance);
[[gnu::nonnull]]
int	alx_cv_black_mask	(void *img, int16_t SL_tolerance,
				 int16_t S_tolerance, int16_t L_tolerance);
[[gnu::nonnull]]
int	alx_cv_gray_mask	(void *img, int16_t SL_tolerance,
				 int16_t S_tolerance, int16_t L_tolerance);


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
[[gnu::nonnull]]
int	white_mask	(class cv::Mat *img, int16_t SL_tolerance,
			 int16_t S_tolerance, int16_t L_tolerance);
[[gnu::nonnull]]
int	black_mask	(class cv::Mat *img, int16_t SL_tolerance,
			 int16_t S_tolerance, int16_t L_tolerance);
[[gnu::nonnull]]
int	gray_mask	(class cv::Mat *img, int16_t SL_tolerance,
			 int16_t S_tolerance, int16_t L_tolerance);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/