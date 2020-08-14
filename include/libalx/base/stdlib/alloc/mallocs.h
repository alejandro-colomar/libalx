/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/mallocs.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]]  [[gnu::warn_unused_result]]
 * int	mallocs(void **ptr, ssize_t size);
 *
 * Safe & simple wrapper for `malloc()`.
 * To be used for generic buffers of bytes, and not for arrays (use
 * `mallocarray()` family of functions for that purpose).
 *
 * RETURN:
 * ptr:		Memory will be allocated, and a pointer to it will be stored
 *		in *ptr.
 * size:	Size of the buffer (in bytes).
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  *ptr = NULL.
 *	-ERRNO:		Failed.  errno = ENOMEM.  *ptr = NULL.
 *
 * FEATURES:
 * - *ptr is NULL on zero size allocation.
 * - Doesn't cast.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 * - Returns non-zero if the resulting pointer is NULL.
 *
 * EXAMPLE:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/mallocs.h>
 *
 *		char *buf;
 *
 *		if (mallocs(&buf, 7))		// char buf[7];
 *			goto err;
 *
 *		// `buf` has been succesfully allocated here
 *		free(buf);
 *	err:
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
#define alx_mallocs(ptr, size)	__extension__(				\
{									\
	__auto_type	ptr_	= (ptr);				\
	int		err_;						\
									\
	*ptr_	= alx_mallocs__(size, &err_);				\
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
 * void	*alx_mallocs__(ssize_t size, int *error);
 *
 * Helper function for `mallocs()`.
 *
 * PARAMETERS:
 * size:	Size of the buffer (in bytes).
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
 * - error is non-zero if the result is NULL.
 */
[[gnu::malloc]] [[gnu::nonnull]] [[gnu::warn_unused_result]]
void	*alx_mallocs__	(ssize_t size, int *error);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define mallocs(ptr, size)	alx_mallocs(ptr, size)
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
