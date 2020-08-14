/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/compiler/size.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <limits.h>
#include <stddef.h>

#include <sys/cdefs.h>
#include <sys/types.h>

#include "libalx/base/assert/array.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define ssizeof(x)		((ssize_t)sizeof(x))

#define ARRAY_SIZE(arr)		(__arraycount((arr)) + alx_Static_assert_eval0_array(arr))
#define ARRAY_SSIZE(arr)	((ptrdiff_t)ARRAY_SIZE(arr))
#define ARRAY_BYTES(arr)	(sizeof((arr)[0]) * ARRAY_SIZE(arr))
#define ARRAY_BITS(arr)		(ARRAY_BYTES(arr) * CHAR_BIT)

#define FIELD_SIZEOF(t, f)	(sizeof(((t *)NULL)->f))
#define FIELD_ARRAY_SIZE(t, f)						\
	(__arraycount((((t *)NULL)->f)) + alx_Static_assert_eval0_array(((t *)NULL)->f))

#define FIELD_ARRAY_BYTES(t, f)	(sizeof((((t *)NULL)->f)[0]) *		\
				 FIELD_ARRAY_SIZE(t, f))


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
