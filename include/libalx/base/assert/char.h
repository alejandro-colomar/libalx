/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/char.h */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/assert/assert.h"
#include "libalx/base/compiler/type.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define alx_Static_assert_char_signed()					\
	_Static_assert(alx_is_signed_type(char), "char != signed char")

#define alx_Static_assert_char_unsigned()				\
	_Static_assert(alx_is_unsigned_type(char), "char != unsigned char")

#define alx_assert_char_signed()					\
	alx_assert_msg(alx_is_signed_type(char), "BUG:   char != signed char")

#define alx_assert_char_unsigned()					\
	alx_assert_msg(alx_is_unsigned_type(char),"BUG:   char != unsigned char")


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
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define Static_assert_char_signed()	alx_Static_assert_char_signed()
#define Static_assert_char_unsigned()	alx_Static_assert_char_unsigned()
#define assert_char_signed()		alx_assert_char_signed()
#define assert_char_unsigned()		alx_assert_char_unsigned()
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
