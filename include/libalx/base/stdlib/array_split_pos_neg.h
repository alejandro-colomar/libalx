/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/array_split_pos_neg.h */

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
void	alx_array_split_pos_neg_ldbl(ptrdiff_t nmemb,
				 const long double mix[static restrict nmemb],
				 long double pos[static restrict nmemb],
				 long double neg[static restrict nmemb]);
[[gnu::nonnull]]
void	alx_array_split_pos_neg	(ptrdiff_t nmemb,
				 const double mix[static restrict nmemb],
				 double pos[static restrict nmemb],
				 double neg[static restrict nmemb]);
[[gnu::nonnull]]
void	alx_array_split_pos_neg_flt(ptrdiff_t nmemb,
				 const float mix[static restrict nmemb],
				 float pos[static restrict nmemb],
				 float neg[static restrict nmemb]);
[[gnu::nonnull]]
void	alx_array_split_pos_neg_int(ptrdiff_t nmemb,
				 const int mix[static restrict nmemb],
				 int pos[static restrict nmemb],
				 int neg[static restrict nmemb]);
[[gnu::nonnull]]
void	alx_array_split_pos_neg_s8(ptrdiff_t nmemb,
				 const int8_t mix[static restrict nmemb],
				 int8_t pos[static restrict nmemb],
				 int8_t neg[static restrict nmemb]);
[[gnu::nonnull]]
void	alx_array_split_pos_neg_s16(ptrdiff_t nmemb,
				 const int16_t mix[static restrict nmemb],
				 int16_t pos[static restrict nmemb],
				 int16_t neg[static restrict nmemb]);
[[gnu::nonnull]]
void	alx_array_split_pos_neg_s32(ptrdiff_t nmemb,
				 const int32_t mix[static restrict nmemb],
				 int32_t pos[static restrict nmemb],
				 int32_t neg[static restrict nmemb]);
[[gnu::nonnull]]
void	alx_array_split_pos_neg_s64(ptrdiff_t nmemb,
				 const int64_t mix[static restrict nmemb],
				 int64_t pos[static restrict nmemb],
				 int64_t neg[static restrict nmemb]);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
