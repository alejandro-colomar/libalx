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

#include "libalx/base/assert/array.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define ssizeof(x)		((ssize_t)sizeof(x))

#define ARRAY_SIZE(arr)		(std::size(arr))
#define ARRAY_SSIZE(arr)	(std::ssize(arr))
#define ARRAY_BYTES(arr)	(std::size(arr) * sizeof((arr)[0]))
#define ARRAY_BITS(arr)		(ARRAY_BYTES(arr) * CHAR_BIT)

#define VLA_SIZE(arr)		(__arraycount(arr))
#define VLA_SSIZE(arr)		((ptrdiff_t)VLA_SIZE(arr))
#define VLA_BYTES(arr)		(sizeof(arr))
#define VLA_BITS(arr)		(VLA_BYTES(arr) * CHAR_BIT)

#define FIELD_SIZEOF(t, f)	(sizeof(((t *)NULL)->f))
#define FIELD_ARRAY_SIZE(t, f)	(std::size(((t *)NULL)->f))
#define FIELD_ARRAY_SSIZE(t, f)	(std::ssize(((t *)NULL)->f))
#define FIELD_ARRAY_BYTES(t, f)					\
	(std::size(((t *)NULL)->f) * sizeof((((t *)NULL)->f)[0]))


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