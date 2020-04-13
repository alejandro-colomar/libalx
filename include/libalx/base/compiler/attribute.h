/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/compiler/attribute.h */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define ALX_ALIAS(aka, original)					\
__attribute__((alias(#original)))					\
__attribute__((copy(original)))						\
typeof(original)	aka;


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
#if defined(ALX_NO_PREFIX)
#define ALIAS(aka, original)	ALX_ALIAS(aka, original)
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
