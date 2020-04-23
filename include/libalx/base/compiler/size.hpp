/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/compiler/size.hpp */

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

#include "libalx/base/assert/array.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define ARRAY_SIZE(arr)		(					\
{									\
	/* alx_Static_assert_array(arr); */				\
	__arraycount((arr));						\
}									\
)

#define ARRAY_SSIZE(arr)	((ptrdiff_t)ARRAY_SIZE(arr))
#define ARRAY_BYTES(arr)	(ARRAY_SIZE(arr) * sizeof((arr)[0]))
#define ARRAY_BITS(arr)		(ARRAY_BYTES(arr) * CHAR_BIT)

#define FIELD_SIZEOF(t, f)	(sizeof(((t *)NULL)->f))
#define FIELD_ARRAY_SIZE(t, f)	(					\
{									\
	/* alx_Static_assert_array(((t *)NULL)->f); */			\
	__arraycount(((t *)NULL)->f)					\
}									\
)

#define FIELD_ARRAY_BYTES(t, f)	(sizeof(((t *)NULL)->f[0]) *		\
				 FIELD_ARRAY_SIZE(t, f))


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
