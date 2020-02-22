/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/core/array.h */


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
enum	Alx_Cv_Cmp {
	ALX_CV_CMP_BLUE,
	ALX_CV_CMP_GREEN,
	ALX_CV_CMP_RED
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/* ----- Operations on arrays */
__attribute__((nonnull))
int	alx_cv_and_2ref		(img_s *restrict img,
				 const img_s *restrict ref);
__attribute__((nonnull))
void	alx_cv_invert		(img_s *img);
__attribute__((nonnull))
int	alx_cv_or_2ref		(img_s *restrict img,
				 const img_s *restrict ref);
__attribute__((nonnull))
int	alx_cv_component	(img_s *img, ptrdiff_t cmp);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
