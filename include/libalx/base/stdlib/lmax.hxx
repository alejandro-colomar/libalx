/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/lmax.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdbool>
#include <cstddef>
#include <cstdint>

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
[[gnu::nonnull]]
void	alx_lmax_ldbl	(ptrdiff_t rows, ptrdiff_t cols,
			 const long double *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax	(ptrdiff_t rows, ptrdiff_t cols,
			 const double *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax_f	(ptrdiff_t rows, ptrdiff_t cols,
			 const float *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax_uint	(ptrdiff_t rows, ptrdiff_t cols,
			 const unsigned *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax_int	(ptrdiff_t rows, ptrdiff_t cols,
			 const int *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax_u8	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint8_t *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax_s8	(ptrdiff_t rows, ptrdiff_t cols,
			 const int8_t *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax_u16	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint16_t *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax_s16	(ptrdiff_t rows, ptrdiff_t cols,
			 const int16_t *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax_u32	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint32_t *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax_s32	(ptrdiff_t rows, ptrdiff_t cols,
			 const int32_t *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax_u64	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint64_t *restrict arr_in,
			 bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_lmax_s64	(ptrdiff_t rows, ptrdiff_t cols,
			 const int64_t *restrict arr_in,
			 bool *restrict arr_out);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


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
