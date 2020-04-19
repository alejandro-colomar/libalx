/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/local_maxima.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


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
__attribute__((nonnull))
void	alx_local_maxima_ldbl	(ptrdiff_t rows, ptrdiff_t cols,
			 const long double arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima	(ptrdiff_t rows, ptrdiff_t cols,
			 const double arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima_f	(ptrdiff_t rows, ptrdiff_t cols,
			 const float arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima_uint	(ptrdiff_t rows, ptrdiff_t cols,
			 const unsigned arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima_int	(ptrdiff_t rows, ptrdiff_t cols,
			 const int arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima_u8	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint8_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima_s8	(ptrdiff_t rows, ptrdiff_t cols,
			 const int8_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima_u16	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint16_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima_s16	(ptrdiff_t rows, ptrdiff_t cols,
			 const int16_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima_u32	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint32_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima_s32	(ptrdiff_t rows, ptrdiff_t cols,
			 const int32_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima_u64	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint64_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);
__attribute__((nonnull))
void	alx_local_maxima_s64	(ptrdiff_t rows, ptrdiff_t cols,
			 const int64_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols]);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
