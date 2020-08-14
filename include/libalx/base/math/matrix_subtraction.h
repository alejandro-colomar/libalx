/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/math/matrix_subtraction.h */

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
inline
void	alx_matrix_subtraction_ldbl	(ptrdiff_t nmemb,
					 long double dest[static nmemb],
					 const long double src1[static nmemb],
					 const long double src2[static nmemb]);
[[gnu::nonnull]]
inline
void	alx_matrix_subtraction		(ptrdiff_t nmemb,
					 double dest[static nmemb],
					 const double src1[static nmemb],
					 const double src2[static nmemb]);
[[gnu::nonnull]]
inline
void	alx_matrix_subtraction_flt	(ptrdiff_t nmemb,
					 float dest[static nmemb],
					 const float src1[static nmemb],
					 const float src2[static nmemb]);
[[gnu::nonnull]]

int	alx_matrix_subtraction_uint	(ptrdiff_t nmemb,
					 unsigned dest[static nmemb],
					 const unsigned src1[static nmemb],
					 const unsigned src2[static nmemb]);
[[gnu::nonnull]]
int	alx_matrix_subtraction_int	(ptrdiff_t nmemb,
					 int dest[static nmemb],
					 const int src1[static nmemb],
					 const int src2[static nmemb]);
[[gnu::nonnull]]
int	alx_matrix_subtraction_u8	(ptrdiff_t nmemb,
					 uint8_t dest[static nmemb],
					 const uint8_t src1[static nmemb],
					 const uint8_t src2[static nmemb]);
[[gnu::nonnull]]
int	alx_matrix_subtraction_s8	(ptrdiff_t nmemb,
					 int8_t dest[static nmemb],
					 const int8_t src1[static nmemb],
					 const int8_t src2[static nmemb]);
[[gnu::nonnull]]
int	alx_matrix_subtraction_u16	(ptrdiff_t nmemb,
					 uint16_t dest[static nmemb],
					 const uint16_t src1[static nmemb],
					 const uint16_t src2[static nmemb]);
[[gnu::nonnull]]
int	alx_matrix_subtraction_s16	(ptrdiff_t nmemb,
					 int16_t dest[static nmemb],
					 const int16_t src1[static nmemb],
					 const int16_t src2[static nmemb]);
[[gnu::nonnull]]
int	alx_matrix_subtraction_u32	(ptrdiff_t nmemb,
					 uint32_t dest[static nmemb],
					 const uint32_t src1[static nmemb],
					 const uint32_t src2[static nmemb]);
[[gnu::nonnull]]
int	alx_matrix_subtraction_s32	(ptrdiff_t nmemb,
					 int32_t dest[static nmemb],
					 const int32_t src1[static nmemb],
					 const int32_t src2[static nmemb]);
[[gnu::nonnull]]
int	alx_matrix_subtraction_u64	(ptrdiff_t nmemb,
					 uint64_t dest[static nmemb],
					 const uint64_t src1[static nmemb],
					 const uint64_t src2[static nmemb]);
[[gnu::nonnull]]
int	alx_matrix_subtraction_s64	(ptrdiff_t nmemb,
					 int64_t dest[static nmemb],
					 const int64_t src1[static nmemb],
					 const int64_t src2[static nmemb]);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
void	alx_matrix_subtraction_ldbl	(ptrdiff_t nmemb,
					 long double dest[nmemb],
					 const long double src1[nmemb],
					 const long double src2[nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] - src2[i];
}

inline
void	alx_matrix_subtraction		(ptrdiff_t nmemb,
					 double dest[nmemb],
					 const double src1[nmemb],
					 const double src2[nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] - src2[i];
}

inline
void	alx_matrix_subtraction_flt	(ptrdiff_t nmemb,
					 float dest[nmemb],
					 const float src1[nmemb],
					 const float src2[nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] - src2[i];
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
