/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/math/array_sum.hxx */

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

#include "libalx/base/stddef/restrict.hxx"


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
long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					 const long double *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double	alx_ldbl_array_sum_uint	(ptrdiff_t nmemb,
					 const unsigned *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double	alx_ldbl_array_sum_int	(ptrdiff_t nmemb,
					 const int *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double	alx_ldbl_array_sum_u8	(ptrdiff_t nmemb,
					 const uint8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double	alx_ldbl_array_sum_s8	(ptrdiff_t nmemb,
					 const int8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double	alx_ldbl_array_sum_u16	(ptrdiff_t nmemb,
					 const uint16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double	alx_ldbl_array_sum_s16	(ptrdiff_t nmemb,
					 const int16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double	alx_ldbl_array_sum_u32	(ptrdiff_t nmemb,
					 const uint32_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double	alx_ldbl_array_sum_s32	(ptrdiff_t nmemb,
					 const int32_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double	alx_ldbl_array_sum_u64	(ptrdiff_t nmemb,
					 const uint64_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double	alx_ldbl_array_sum_s64	(ptrdiff_t nmemb,
					 const int64_t *restrict arr);

[[gnu::nonnull]][[gnu::pure]]
double	alx_dbl_array_sum	(ptrdiff_t nmemb,
				 const double *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_dbl_array_sum_uint	(ptrdiff_t nmemb,
				 const unsigned *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_dbl_array_sum_int	(ptrdiff_t nmemb,
				 const int *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_dbl_array_sum_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_dbl_array_sum_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_dbl_array_sum_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_dbl_array_sum_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_dbl_array_sum_u32	(ptrdiff_t nmemb,
				 const uint32_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_dbl_array_sum_s32	(ptrdiff_t nmemb,
				 const int32_t *restrict arr);

[[gnu::nonnull]][[gnu::pure]]
float	alx_flt_array_sum_flt	(ptrdiff_t nmemb,
				 const float *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
float	alx_flt_array_sum_uint	(ptrdiff_t nmemb,
				 const unsigned *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
float	alx_flt_array_sum_int	(ptrdiff_t nmemb,
				 const int *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
float	alx_flt_array_sum_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
float	alx_flt_array_sum_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
float	alx_flt_array_sum_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
float	alx_flt_array_sum_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr);

[[gnu::nonnull]][[gnu::pure]]
unsigned	alx_array_sum_uint	(ptrdiff_t nmemb,
					 const unsigned *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
int		alx_array_sum_int	(ptrdiff_t nmemb,
					 const int *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
uint8_t		alx_array_sum_u8	(ptrdiff_t nmemb,
					 const uint8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
int8_t		alx_array_sum_s8	(ptrdiff_t nmemb,
					 const int8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
uint16_t	alx_array_sum_u16	(ptrdiff_t nmemb,
					 const uint16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
int16_t		alx_array_sum_s16	(ptrdiff_t nmemb,
					 const int16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
uint32_t	alx_array_sum_u32	(ptrdiff_t nmemb,
					 const uint32_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
int32_t		alx_array_sum_s32	(ptrdiff_t nmemb,
					 const int32_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
uint64_t	alx_array_sum_u64	(ptrdiff_t nmemb,
					 const uint64_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
int64_t		alx_array_sum_s64	(ptrdiff_t nmemb,
					 const int64_t *restrict arr);


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
