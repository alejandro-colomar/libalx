/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/cblas/iXamax.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>

#include "libalx/base/compiler/attribute.hxx"
#include "libalx/base/compiler/restrict.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern "C" {


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* C prototypes *********************************************************
 ******************************************************************************/
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_ldbl	(ptrdiff_t nmemb,
				 const long double *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_uint	(ptrdiff_t nmemb,
				 const unsigned *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_int	(ptrdiff_t nmemb,
				 const int *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_u32	(ptrdiff_t nmemb,
				 const uint32_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_s32	(ptrdiff_t nmemb,
				 const int32_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_u64	(ptrdiff_t nmemb,
				 const uint64_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_s64	(ptrdiff_t nmemb,
				 const int64_t *restrict arr,
				 ptrdiff_t step);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cblas_iXamax_pdif	(ptrdiff_t nmemb,
				 const ptrdiff_t *restrict arr,
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
 ******* extern "C" ***********************************************************
 ******************************************************************************/
}	/* extern "C" */


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
