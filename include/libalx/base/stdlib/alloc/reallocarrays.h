/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/reallocarrays.h */

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
 * int	reallocarrays(type **ptr, ssize_t nmemb);
 *
 * Safe & simple wrapper for `reallocarray()`.
 *
 * PARAMETERS:
 * ptr:		Memory will be allocated, and a pointer to it will be stored
 *		in *ptr.
 * nmemb:	Number of elements in the array.
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  *ptr = NULL.
 *	-ERRNO:		Failed.  errno = ENOMEM.  *ptr is untouched.
 *
 * FEATURES:
 * - Safely computes the element size (second argument to `reallocarray()`).
 * - *ptr is NULL on zero size reallocation.
 * - Fails safely if (nmemb < 0).
 * - Fails safely if (nmemb * size) would overflow.
 * - Doesn't cast.
 * - Upon failure, the pointer is untouched.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 * - Returns non-zero if the resulting pointer is NULL or untouched.
 *
 * EXAMPLE:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/reallocarrays.h>
 *
 *		int *arr;
 *
 *		if (mallocarrays(&arr, 5))	// int arr[5];
 *			goto err;
 *		if (reallocarrays(&arr, 7))	// int arr[7];
 *			goto err;
 *
 *		// `arr` has been succesfully reallocated here
 *	err:
 *		free(arr);
 *		// No memory leaks
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include <sys/types.h>

#include "libalx/base/compiler/attribute.h"
#include "libalx/base/compiler/size.h"
#include "libalx/base/compiler/unused.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define alx_reallocarrays(ptr, nmemb)	__extension__(			\
{									\
	__auto_type	ptr_	= (ptr);				\
	int		err_;						\
									\
	*ptr_	= alx_reallocarrays__(*ptr_, nmemb, ssizeof(**ptr_), &err_); \
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
 * [[gnu::nonnull]] [[gnu::warn_unused_result]]
 * void	*alx_reallocarrays__(void *restrict ptr, ptrdiff_t nmemb, ssize_t size,
 *			     int *restrict error);
 *
 * Helper function for `reallocarrays()`.
 *
 * PARAMETERS:
 * ptr:		Pointer to allocated memory (or NULL).
 * nmemb:	Number of elements in the array.
 * size:	Size of each element in the array.
 * error:	Variable to pass the error code (through a pointer to it).
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  return NULL.
 *	-ERRNO:		Failure.  errno = ENOMEM.  return ptr.
 *
 * FEATURES:
 * - Returns NULL on zero size allocation.
 * - Fails safely if (nmemb < 0).
 * - Fails safely if (nmemb * size) would overflow.
 * - Upon failure, the pointer is returned untouched.
 * - error is non-zero if the resulting pointer is NULL or untouched.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
void	*alx_reallocarrays__	(void *restrict ptr, ptrdiff_t nmemb,
				 ssize_t size, int *restrict error);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(reallocarrays__,	alx_reallocarrays__);
#define reallocarrays(ptr, nmemb)	alx_reallocarrays(ptr, nmemb)
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
