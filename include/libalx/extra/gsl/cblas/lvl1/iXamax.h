/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/cblas/iXamax.h */

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
ptrdiff_t alx_cblas_iXamax_ldbl	(ptrdiff_t nmemb,
				 const long double arr[static restrict nmemb],
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_uint	(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb],
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_int	(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb],
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb],
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb],
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb],
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb],
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb],
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb],
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb],
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_s64	(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb],
				 ptrdiff_t step);
[[gnu::nonnull]] [[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_pdif	(ptrdiff_t nmemb,
				 const ptrdiff_t arr[static restrict nmemb],
				 ptrdiff_t step);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(cblas_iXamax_ldbl,	alx_cblas_iXamax_ldbl);
ALX_ALIAS_DECLARATION(cblas_iXamax_uint,	alx_cblas_iXamax_uint);
ALX_ALIAS_DECLARATION(cblas_iXamax_int,		alx_cblas_iXamax_int);
ALX_ALIAS_DECLARATION(cblas_iXamax_u8,		alx_cblas_iXamax_u8);
ALX_ALIAS_DECLARATION(cblas_iXamax_s8,		alx_cblas_iXamax_s8);
ALX_ALIAS_DECLARATION(cblas_iXamax_u16,		alx_cblas_iXamax_u16);
ALX_ALIAS_DECLARATION(cblas_iXamax_s16,		alx_cblas_iXamax_s16);
ALX_ALIAS_DECLARATION(cblas_iXamax_u32,		alx_cblas_iXamax_u32);
ALX_ALIAS_DECLARATION(cblas_iXamax_s32,		alx_cblas_iXamax_s32);
ALX_ALIAS_DECLARATION(cblas_iXamax_u64,		alx_cblas_iXamax_u64);
ALX_ALIAS_DECLARATION(cblas_iXamax_s64,		alx_cblas_iXamax_s64);
ALX_ALIAS_DECLARATION(cblas_iXamax_pdif,	alx_cblas_iXamax_pdif);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
