/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/type.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/assert/assert.h"
#include "libalx/base/compiler/type.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define alx_Static_assert_unsigned(x)					\
	_Static_assert(alx_unsigned_type(x),				\
			"Not an unsigned type!")

#define alx_Static_assert_signed(x)					\
	_Static_assert(alx_signed_type(x),				\
			"Not a signed type!")

#define alx_assert_unsigned(x)						\
	alx_assert_msg(alx_unsigned_type(x),				\
			"BUG:   Not an unsigned type!")

#define alx_assert_signed(x)						\
	alx_assert_msg(alx_signed_type(x),				\
			"BUG:   Not a signed type!")

#define alx_Static_assert_same_type(a, b)				\
	_Static_assert(alx_same_type(a, b),				\
			"Incompatible types!")

#define alx_assert_same_type(a, b)					\
	alx_assert_msg(alx_same_type(a, b),				\
			"BUG:   Incompatible types!")


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define Static_assert_unsigned(x)	alx_Static_assert_unsigned(x)
#define Static_assert_signed(x)		alx_Static_assert_signed(x)
#define assert_unsigned(x)		alx_assert_unsigned(x)
#define assert_signed(x)		alx_assert_signed(x)
#define Static_assert_same_type(a, b)	alx_Static_assert_same_type(a, b)
#define assert_same_type(a, b)		alx_assert_same_type(a, b)
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
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
