/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/strto/strtoi_s.h */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define strtoi8_s(num, str, base, nread)   alx_strtoi8_s(num, str, base, nread)
#define strtoi16_s(num, str, base, nread)  alx_strtoi16_s(num, str, base, nread)
#define strtoi32_s(num, str, base, nread)  alx_strtoi32_s(num, str, base, nread)
#define strtoi64_s(num, str, base, nread)  alx_strtoi64_s(num, str, base, nread)
#endif	/* defined(ALX_NO_PREFIX) */


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
int	alx_strtoi8_s		(int8_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtoi16_s		(int16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtoi32_s		(int32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtoi64_s		(int64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);

__attribute__((nonnull, warn_unused_result))
int	alx_strtol_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
