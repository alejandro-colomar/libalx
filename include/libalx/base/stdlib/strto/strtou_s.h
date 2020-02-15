/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/strto/strtou_s.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>

#include "libalx/base/stdlib/strto/strtoi_s.h"


/******************************************************************************
 ******* macros ***************************************************************
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
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtou8_s		(uint8_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtou16_s		(uint16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtou32_s		(uint32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtou64_s		(uint64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);

__attribute__((nonnull, warn_unused_result))
inline
int	alx_strtoul_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
inline
int	strtou8_s		(uint8_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	return	alx_strtou8_s(num, str, base, nread);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
inline
int	strtou16_s		(uint16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	return	alx_strtou16_s(num, str, base, nread);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
inline
int	strtou32_s		(uint32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	return	alx_strtou32_s(num, str, base, nread);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
inline
int	strtou64_s		(uint64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread)
{
	return	alx_strtou64_s(num, str, base, nread);
}
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
int	alx_strtoul_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before)
{
	return	alx_strtol_status(str, endptr, errno_after, errno_before);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
