/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/rstat/median.h */

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
[[gnu::nonnull]]
long double alx_gsl_rstat_median_ldbl(ptrdiff_t nmemb,
				 const long double x[static restrict nmemb]);
[[gnu::nonnull]]
float	alx_gsl_rstat_median_flt(ptrdiff_t nmemb,
				 const float x[static restrict nmemb]);
[[gnu::nonnull]]
double	alx_gsl_rstat_median_uint(ptrdiff_t nmemb,
				 const unsigned x[static restrict nmemb]);
[[gnu::nonnull]]
double	alx_gsl_rstat_median_int(ptrdiff_t nmemb,
				 const int x[static restrict nmemb]);
[[gnu::nonnull]]
double	alx_gsl_rstat_median_u8	(ptrdiff_t nmemb,
				 const uint8_t x[static restrict nmemb]);
[[gnu::nonnull]]
double	alx_gsl_rstat_median_s8	(ptrdiff_t nmemb,
				 const int8_t x[static restrict nmemb]);
[[gnu::nonnull]]
double	alx_gsl_rstat_median_u16(ptrdiff_t nmemb,
				 const uint16_t x[static restrict nmemb]);
[[gnu::nonnull]]
double	alx_gsl_rstat_median_s16(ptrdiff_t nmemb,
				 const int16_t x[static restrict nmemb]);
[[gnu::nonnull]]
double	alx_gsl_rstat_median_u32(ptrdiff_t nmemb,
				 const uint32_t x[static restrict nmemb]);
[[gnu::nonnull]]
double	alx_gsl_rstat_median_s32(ptrdiff_t nmemb,
				 const int32_t x[static restrict nmemb]);
[[gnu::nonnull]]
long double alx_gsl_rstat_median_u64(ptrdiff_t nmemb,
				 const uint64_t x[static restrict nmemb]);
[[gnu::nonnull]]
long double alx_gsl_rstat_median_s64(ptrdiff_t nmemb,
				 const int64_t x[static restrict nmemb]);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(gsl_rstat_median_ldbl,	alx_gsl_rstat_median_ldbl);
ALX_ALIAS_DECLARATION(gsl_rstat_median_flt,	alx_gsl_rstat_median_flt);
ALX_ALIAS_DECLARATION(gsl_rstat_median_uint,	alx_gsl_rstat_median_uint);
ALX_ALIAS_DECLARATION(gsl_rstat_median_int,	alx_gsl_rstat_median_int);
ALX_ALIAS_DECLARATION(gsl_rstat_median_u8,	alx_gsl_rstat_median_u8);
ALX_ALIAS_DECLARATION(gsl_rstat_median_s8,	alx_gsl_rstat_median_u8);
ALX_ALIAS_DECLARATION(gsl_rstat_median_u16,	alx_gsl_rstat_median_u16);
ALX_ALIAS_DECLARATION(gsl_rstat_median_s16,	alx_gsl_rstat_median_s16);
ALX_ALIAS_DECLARATION(gsl_rstat_median_u32,	alx_gsl_rstat_median_u32);
ALX_ALIAS_DECLARATION(gsl_rstat_median_s32,	alx_gsl_rstat_median_s32);
ALX_ALIAS_DECLARATION(gsl_rstat_median_u64,	alx_gsl_rstat_median_u64);
ALX_ALIAS_DECLARATION(gsl_rstat_median_s64,	alx_gsl_rstat_median_s64);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
