/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/miscellaneous/threshold.h */

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
#define ALX_CV_THR_OTSU		(-1)
#define ALX_CV_THR_TRIANGLE	(-2)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
/** Adaptive threshold methods */
enum	Alx_Cv_Adaptive_Thr_Method {
	ALX_CV_ADAPTIVE_THRESH_MEAN	= 0,
	ALX_CV_ADAPTIVE_THRESH_GAUSSIAN	= 1
};

enum	Alx_Cv_Thresh {
	ALX_CV_THRESH_BINARY      = 0,  /**< value = value > threshold ? max_value : 0       */
	ALX_CV_THRESH_BINARY_INV  = 1,  /**< value = value > threshold ? 0 : max_value       */
	ALX_CV_THRESH_TRUNC       = 2,  /**< value = value > threshold ? threshold : value   */
	ALX_CV_THRESH_TOZERO      = 3,  /**< value = value > threshold ? value : 0           */
	ALX_CV_THRESH_TOZERO_INV  = 4,  /**< value = value > threshold ? 0 : value           */
	ALX_CV_THRESH_MASK        = 7,
	ALX_CV_THRESH_OTSU        = 8,  /**< use Otsu algorithm to choose the optimal threshold value;
					combine the flag with one of the above CV_THRESH_* values */
	ALX_CV_THRESH_TRIANGLE    = 16  /**< use Triangle algorithm to choose the optimal threshold value;
					combine the flag with one of the above CV_THRESH_* values, but not
					with CV_THRESH_OTSU */
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::nonnull]]
int	alx_cv_adaptive_thr	(img_s *img, int method,
				 int thr_typ, int ksize, int c);
[[gnu::nonnull]]
int	alx_cv_threshold	(img_s *img, int thr_typ, int thr_val);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
