/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/float/constant.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <float.h>


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#if	(FLT_EVAL_METHOD == 0)
#define FLTT_C(c)	c ## f
#define DBLT_C(c)	c

#elif	(FLT_EVAL_METHOD == 1)
#define FLTT_C(c)	c
#define DBLT_C(c)	c

#elif	(FLT_EVAL_METHOD == 2)
#define FLTT_C(c)	c ## L
#define DBLT_C(c)	c ## L
#endif


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
