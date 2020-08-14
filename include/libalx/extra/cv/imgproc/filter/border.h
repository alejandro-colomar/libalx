/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/filter/border.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>

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
void	alx_cv_border_black	(img_s *img, ptrdiff_t size);
[[gnu::nonnull]]
int	alx_cv_border1D_median	(img_s *img, ptrdiff_t size);
[[gnu::nonnull]]
int	alx_cv_border1D		(img_s *img, ptrdiff_t size, uint8_t value);
[[gnu::nonnull]]
void	alx_cv_rm_border	(img_s *img, ptrdiff_t size);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
