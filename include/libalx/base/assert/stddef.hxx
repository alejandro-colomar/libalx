/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/stddef.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cassert>
#include <cstddef>

#include <sys/types.h>

#include "libalx/base/assert/assert.hxx"
#include "libalx/base/compiler/type.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define alx_Static_assert_size_ptrdiff()				\
	static_assert(sizeof(size_t) == sizeof(ptrdiff_t),		\
			"sizeof(size_t) != sizeof(ptrdiff_t)")

#define alx_assert_size_ptrdiff()					\
	alx_assert_msg(sizeof(size_t) == sizeof(ptrdiff_t),		\
			"BUG:   sizeof(size_t) != sizeof(ptrdiff_t)")

#define alx_Static_assert_ssize_ptrdiff()				\
	static_assert(alx_is_same_type(ssize_t, ptrdiff_t),		\
			"ssize_t != ptrdiff_t")

#define alx_assert_ssize_ptrdiff()					\
	alx_assert_msg(alx_is_same_type(ssize_t, ptrdiff_t),		\
			"BUG:   ssize_t != ptrdiff_t")


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern "C" {


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* C prototypes *********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define Static_assert_size_ptrdiff()	alx_Static_assert_size_ptrdiff()
#define assert_size_ptrdiff()		alx_assert_size_ptrdiff()
#define Static_assert_ssize_ptrdiff()	alx_Static_assert_ssize_ptrdiff()
#define assert_ssize_ptrdiff()		alx_assert_ssize_ptrdiff()
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
}	/* extern "C" */


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enum *****************************************************************
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
