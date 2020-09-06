/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/compiler/size.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <climits>
#include <cstddef>

#include <sys/cdefs.h>
#include <sys/types.h>

#include "libalx/base/assert/array.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define ssizeof(x)		((ssize_t)sizeof(x))

#define ARRAY_SIZE(arr)							\
	(__arraycount((arr)) + alx_Static_assert_eval0_array(arr))
#define ARRAY_SSIZE(arr)	((ptrdiff_t)ARRAY_SIZE(arr))
#define ARRAY_BYTES(arr)						\
	(sizeof(arr) + alx_Static_assert_eval0_array(arr))
#define ARRAY_BITS(arr)		(ARRAY_BYTES(arr) * CHAR_BIT)

#define VLA_SIZE(arr)		(__arraycount(arr))
#define VLA_SSIZE(arr)		((ptrdiff_t)VLA_SIZE(arr))
#define VLA_BYTES(arr)		(sizeof(arr))
#define VLA_BITS(arr)		(VLA_BYTES(arr) * CHAR_BIT)

#define FIELD_SIZEOF(t, f)	(sizeof(((t *)NULL)->f))
#define FIELD_ARRAY_SIZE(t, f)						\
	(__arraycount((((t *)NULL)->f)) +				\
	 alx_Static_assert_eval0_array(((t *)NULL)->f))
#define FIELD_ARRAY_SSIZE(t, f)	((ptrdiff_t)FIELD_ARRAY_SIZE(t, f))
#define FIELD_ARRAY_BYTES(t, f)						\
	(FIELD_SIZEOF(t, f) + alx_Static_assert_eval0_array(((t *)NULL)->f))


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
