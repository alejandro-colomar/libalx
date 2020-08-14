/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/strto/strtof_s.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include "libalx/base/compiler/attribute.h"
#include "libalx/base/stdlib/strto/strtoi_s.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


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
 * `errno` needs to be cleared before calling these functions.  If not, false
 * negatives could happen (the function succeds, but it reports error).
 */
[[gnu::nonnull(1, 2)]] [[gnu::warn_unused_result]]
int	alx_strtod_s	(double *restrict num, const char *restrict str,
			 ptrdiff_t *restrict nread);
[[gnu::nonnull(1, 2)]] [[gnu::warn_unused_result]]
int	alx_strtof_s	(float *restrict num, const char *restrict str,
			 ptrdiff_t *restrict nread);
[[gnu::nonnull(1, 2)]] [[gnu::warn_unused_result]]
int	alx_strtold_s	(long double *restrict num, const char *restrict str,
			 ptrdiff_t *restrict nread);

[[gnu::nonnull]] [[gnu::warn_unused_result]]
inline
int	alx_strtof_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(strtod_s,		alx_strtod_s);
ALX_ALIAS_DECLARATION(strtof_s,		alx_strtof_s);
ALX_ALIAS_DECLARATION(strtold_s,	alx_strtold_s);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
int	alx_strtof_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before)
{
	return	alx_strtol_status(str, endptr, errno_after, errno_before);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
