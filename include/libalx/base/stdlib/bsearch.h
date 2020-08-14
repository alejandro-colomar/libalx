/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/bsearch.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>
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
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t	alx_bsearch_uint(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb],
				 unsigned x);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t	alx_bsearch_int	(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb],
				 int x);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t	alx_bsearch_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb],
				 uint8_t x);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t	alx_bsearch_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb],
				 int8_t x);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t	alx_bsearch_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb],
				 uint16_t x);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t	alx_bsearch_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb],
				 int16_t x);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t	alx_bsearch_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb],
				 uint32_t x);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t	alx_bsearch_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb],
				 int32_t x);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t	alx_bsearch_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb],
				 uint64_t x);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t	alx_bsearch_s64	(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb],
				 int64_t x);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(bsearch_uint,	alx_bsearch_uint);
ALX_ALIAS_DECLARATION(bsearch_int,	alx_bsearch_int);
ALX_ALIAS_DECLARATION(bsearch_u8,	alx_bsearch_u8);
ALX_ALIAS_DECLARATION(bsearch_s8,	alx_bsearch_s8);
ALX_ALIAS_DECLARATION(bsearch_u16,	alx_bsearch_u16);
ALX_ALIAS_DECLARATION(bsearch_s16,	alx_bsearch_s16);
ALX_ALIAS_DECLARATION(bsearch_u32,	alx_bsearch_u32);
ALX_ALIAS_DECLARATION(bsearch_s32,	alx_bsearch_s32);
ALX_ALIAS_DECLARATION(bsearch_u64,	alx_bsearch_u64);
ALX_ALIAS_DECLARATION(bsearch_s64,	alx_bsearch_s64);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
