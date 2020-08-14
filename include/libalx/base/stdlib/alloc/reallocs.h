/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/reallocs.h */

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
 * int	reallocs(type **ptr, ssize_t size);
 *
 * Safe & simple wrapper for `realloc()`.
 * To be used for generic buffers of bytes, and not for arrays (use
 * `reallocarray()` family of functions for that purpose).
 *
 * PARAMETERS:
 * ptr:		Memory will be allocated, and a pointer to it will be stored
 *		in *ptr.
 * size:	Size of the buffer (in bytes).
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  *ptr = NULL.
 *	-ERRNO:		Failed.  errno = ENOMEM.  *ptr is untouched.
 *
 * FEATURES:
 * - *ptr is NULL on zero size allocation.
 * - Doesn't cast.
 * - Upon failure, the pointer is untouched.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 * - Returns non-zero if the resulting pointer is NULL or untouched.
 *
 * EXAMPLE:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/reallocs.h>
 *
 *		char *buf;
 *
 *		if (mallocs(&buf, 5))	// char buf[5];
 *			goto err;
 *		if (reallocs(&buf, 7))	// char buf[7];
 *			goto err;
 *
 *		// `buf` has been succesfully reallocated here
 *	err:
 *		free(buf);
 *		// No memory leaks
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <sys/types.h>

#include "libalx/base/compiler/unused.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define alx_reallocs(ptr, size)		__extension__(			\
{									\
	__auto_type	ptr_	= (ptr);				\
	int		err_;						\
									\
	*ptr_	= alx_reallocs__(*ptr_, size, &err_);			\
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
 * void	*alx_reallocs__(void *restrict ptr, ssize_t size, int *restrict error);
 *
 * Helper function for `reallocfs()`.
 *
 * PARAMETERS:
 * ptr:		Pointer to allocated memory (or NULL).
 * size:	Size of the buffer (in bytes).
 * error:	Variable to pass the error code (through a pointer to it).
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  return NULL.
 *	-ERRNO:		Failure.  errno = ENOMEM.  return ptr.
 *
 * FEATURES:
 * - Returns NULL on zero size allocation.
 * - Upon failure, the pointer is returned untouched.
 * - error is non-zero if the resulting pointer is NULL or untouched.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
void	*alx_reallocs__	(void *restrict ptr, ssize_t size, int *restrict error);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define reallocs(ptr, size)	alx_reallocs(ptr, size)
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
