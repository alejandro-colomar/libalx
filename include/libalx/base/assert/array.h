/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/array.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/assert/static_assert_eval0.h"
#include "libalx/base/compiler/type.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define alx_Static_assert_array(a)					\
	_Static_assert(alx_is_array(a), "Not a `[]` !")

#define alx_Static_assert_char_array(a)					\
	_Static_assert(alx_is_char_array(a), "Not a `char[]` !")

#define alx_Static_assert_eval0_array(a)				\
	alx_Static_assert_eval0(alx_is_array(a), "Not a `[]` !")


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
#define Static_assert_array(a)		alx_Static_assert_array(a)
#define Static_assert_char_array(a)	alx_Static_assert_char_array(a)
#define Static_assert_eval0_array(a)	alx_Static_assert_eval0_array(a)
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
