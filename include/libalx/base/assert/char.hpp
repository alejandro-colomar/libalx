/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/char.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cassert>

#include "libalx/base/assert/assert.h"
#include "libalx/base/compiler/type.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define alx_Static_assert_char_signed()					\
	static_assert(alx_signed_type(char), "char != signed char")

#define alx_Static_assert_char_unsigned()				\
	static_assert(alx_unsigned_type(char), "char != unsigned char")

#define alx_assert_char_signed()					\
	alx_assert_msg(alx_signed_type(char), "BUG:   char != signed char")

#define alx_assert_char_unsigned()					\
	alx_assert_msg(alx_unsigned_type(char), "BUG:   char != unsigned char")


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define Static_assert_char_signed()	alx_Static_assert_char_signed()
#define Static_assert_char_unsigned()	alx_Static_assert_char_unsigned()
#define assert_char_signed()		alx_assert_char_signed()
#define assert_char_unsigned()		alx_assert_char_unsigned()
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
