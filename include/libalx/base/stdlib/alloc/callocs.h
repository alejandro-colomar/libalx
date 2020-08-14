/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/callocs.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]] [[gnu::warn_unused_result]]
 * int	callocs(type **ptr, ptrdiff_t nmemb);
 *
 * Safe & simple wrapper for `calloc()`.
 *
 * PARAMETERS:
 * ptr:		Memory will be allocated, and a pointer to it will be stored
 *		in *ptr.
 * nmemb:	Number of elements in the array.
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  *ptr = NULL.
 *	-ERRNO:		Failed.  errno = ENOMEM.  *ptr = NULL.
 *
 * FEATURES:
 * - Safely computes the element size (second argument to `calloc()`).
 * - *ptr is NULL on zero size allocation.
 * - Fails safely if (nmemb < 0).
 * - Fails safely if (nmemb * size) would overflow.
 * - Doesn't cast.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 * - Returns non-zero if the resulting pointer is NULL.
 *
 * EXAMPLE:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/callocs.h>
 *
 *		int *arr;
 *
 *		if (callocs(&arr, 7))		// int arr[7];
 *			goto err;
 *
 *		// `arr` has been succesfully allocated here
 *		free(arr);
 *	err:
 *		// No memory leaks
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include <sys/types.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/compiler/unused.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define alx_callocs(ptr, nmemb)		__extension__(			\
{									\
	__auto_type	ptr_	= (ptr);				\
	int		err_;						\
									\
	*ptr_	= alx_callocs__(nmemb, ssizeof(**ptr_), &err_);		\
	alx_warn_unused_int(err_);					\
}									\
)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/*
 * [[gnu::malloc]] [[gnu::nonnull]] [[gnu::warn_unused_result]]
 * void	*alx_callocs__(ptrdiff_t nmemb, ssize_t size, int *error);
 *
 * Helper function for `callocs()`.
 *
 * PARAMETERS:
 * nmemb:	Number of elements in the array.
 * size:	Size of each element in the array.
 * error:	Variable to pass the error code (through a pointer to it).
 *
 * RETURN:
 *	!= NULL:	OK.
 *	NULL:		Failed  OR  zero size allocation.
 *
 * ERRORS:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  return NULL.
 *	-ERRNO:		Failure.  errno = ENOMEM.  return NULL.
 *
 * FEATURES:
 * - Returns NULL on zero size allocation.
 * - Fails safely if (nmemb < 0).
 * - Fails safely if (nmemb * size) would overflow.
 * - error is non-zero if the result is NULL.
 */
[[gnu::malloc]] [[gnu::nonnull]] [[gnu::warn_unused_result]]
void	*alx_callocs__	(ptrdiff_t nmemb, ssize_t size, int *error);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define callocs(ptr, nmemb)	alx_callocs(ptr, nmemb)
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
