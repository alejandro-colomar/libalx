/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/type.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cassert>

#include "libalx/base/assert/assert.hpp"
#include "libalx/base/compiler/type.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define alx_Static_assert_unsigned(x)					\
	static_assert(alx_unsigned_type(x),				\
			"Not an unsigned type!")

#define alx_Static_assert_signed(x)					\
	static_assert(alx_signed_type(x),				\
			"Not a signed type!")

#define alx_assert_unsigned(x)						\
	alx_assert_msg(alx_unsigned_type(x),				\
			"BUG:   Not an unsigned type!")

#define alx_assert_signed(x)						\
	alx_assert_msg(alx_signed_type(x),				\
			"BUG:   Not a signed type!")

#define alx_Static_assert_same_type(a, b)				\
	static_assert(alx_same_type(a, b),				\
			"Incompatible types!")

#define alx_assert_same_type(a, b)					\
	alx_assert_msg(alx_same_type(a, b),				\
			"BUG:   Incompatible types!")

#define alx_Static_assert_bit_fits_type(b, t)				\
	_Static_assert(!alx_bit_overflows_type(b, t),			\
			"Bit overflows type!")

#define alx_assert_bit_fits_type(b, t)					\
	alx_assert_msg(!alx_bit_overflows_type(b, t),			\
			"BUG:   Bit overflows type!")


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define Static_assert_unsigned(x)	alx_Static_assert_unsigned(x)
#define Static_assert_signed(x)		alx_Static_assert_signed(x)
#define assert_unsigned(x)		alx_assert_unsigned(x)
#define assert_signed(x)		alx_assert_signed(x)
#define Static_assert_same_type(a, b)	alx_Static_assert_same_type(a, b)
#define assert_same_type(a, b)		alx_assert_same_type(a, b)
#define Static_assert_bit_fits_type(b, t)  alx_Static_assert_bit_fits_type(b, t)
#define assert_bit_fits_type(b, t)	alx_assert_bit_fits_type(b, t)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


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
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/