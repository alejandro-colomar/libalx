/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/statistics/mean.hxx */

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
long double alx_gsl_stats_mean_ldbl(ptrdiff_t nmemb,
				 const long double *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
float	alx_gsl_stats_mean_flt	(ptrdiff_t nmemb,
				 const float *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_u32	(ptrdiff_t nmemb,
				 const uint32_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_s32	(ptrdiff_t nmemb,
				 const int32_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double alx_gsl_stats_mean_u64(ptrdiff_t nmemb,
				 const uint64_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double alx_gsl_stats_mean_s64(ptrdiff_t nmemb,
				 const int64_t *restrict arr);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(gsl_stats_mean_ldbl,	alx_gsl_stats_mean_ldbl);
ALX_ALIAS_DECLARATION(gsl_stats_mean_flt,	alx_gsl_stats_mean_flt);
ALX_ALIAS_DECLARATION(gsl_stats_mean_u8,	alx_gsl_stats_mean_u8);
ALX_ALIAS_DECLARATION(gsl_stats_mean_s8,	alx_gsl_stats_mean_s8);
ALX_ALIAS_DECLARATION(gsl_stats_mean_u16,	alx_gsl_stats_mean_u16);
ALX_ALIAS_DECLARATION(gsl_stats_mean_s16,	alx_gsl_stats_mean_s16);
ALX_ALIAS_DECLARATION(gsl_stats_mean_u32,	alx_gsl_stats_mean_u32);
ALX_ALIAS_DECLARATION(gsl_stats_mean_s32,	alx_gsl_stats_mean_s32);
ALX_ALIAS_DECLARATION(gsl_stats_mean_u64,	alx_gsl_stats_mean_u64);
ALX_ALIAS_DECLARATION(gsl_stats_mean_s64,	alx_gsl_stats_mean_s64);
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
}	/* extern "C" */


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace gsl {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace gsl */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
