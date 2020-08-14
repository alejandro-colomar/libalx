/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/getenv/getenv_i.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdint.h>

#include "libalx/base/compiler/attribute.h"


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
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_getenv_i64		(int64_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_getenv_i32		(int32_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_getenv_i16		(int16_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_getenv_i8		(int8_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_secure_getenv_i64	(int64_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_secure_getenv_i32	(int32_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_secure_getenv_i16	(int16_t *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_secure_getenv_i8	(int8_t *restrict num,
				 const char *restrict name);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(getenv_i64,		alx_getenv_i64);
ALX_ALIAS_DECLARATION(getenv_i32,		alx_getenv_i32);
ALX_ALIAS_DECLARATION(getenv_i16,		alx_getenv_i16);
ALX_ALIAS_DECLARATION(getenv_i8,		alx_getenv_i8);
ALX_ALIAS_DECLARATION(secure_getenv_i64,	alx_secure_getenv_i64);
ALX_ALIAS_DECLARATION(secure_getenv_i32,	alx_secure_getenv_i32);
ALX_ALIAS_DECLARATION(secure_getenv_i16,	alx_secure_getenv_i16);
ALX_ALIAS_DECLARATION(secure_getenv_i8,		alx_secure_getenv_i8);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

