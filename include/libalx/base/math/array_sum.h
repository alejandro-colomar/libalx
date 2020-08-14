/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/math/array_sum.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <math.h>
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
[[gnu::nonnull]] [[gnu::pure]]
inline
long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					 const long double arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
long double	alx_ldbl_array_sum_uint	(ptrdiff_t nmemb,
					 const unsigned arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
long double	alx_ldbl_array_sum_int	(ptrdiff_t nmemb,
					 const int arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
long double	alx_ldbl_array_sum_u8	(ptrdiff_t nmemb,
					 const uint8_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
long double	alx_ldbl_array_sum_s8	(ptrdiff_t nmemb,
					 const int8_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
long double	alx_ldbl_array_sum_u16	(ptrdiff_t nmemb,
					 const uint16_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
long double	alx_ldbl_array_sum_s16	(ptrdiff_t nmemb,
					 const int16_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
long double	alx_ldbl_array_sum_u32	(ptrdiff_t nmemb,
					 const uint32_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
long double	alx_ldbl_array_sum_s32	(ptrdiff_t nmemb,
					 const int32_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
long double	alx_ldbl_array_sum_u64	(ptrdiff_t nmemb,
					 const uint64_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
long double	alx_ldbl_array_sum_s64	(ptrdiff_t nmemb,
					 const int64_t arr[restrict nmemb]);

[[gnu::nonnull]] [[gnu::pure]]
inline
double	alx_dbl_array_sum		(ptrdiff_t nmemb,
					 const double arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
double	alx_dbl_array_sum_uint		(ptrdiff_t nmemb,
					 const unsigned arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
double	alx_dbl_array_sum_int		(ptrdiff_t nmemb,
					 const int arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
double	alx_dbl_array_sum_u8		(ptrdiff_t nmemb,
					 const uint8_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
double	alx_dbl_array_sum_s8		(ptrdiff_t nmemb,
					 const int8_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
double	alx_dbl_array_sum_u16		(ptrdiff_t nmemb,
					 const uint16_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
double	alx_dbl_array_sum_s16		(ptrdiff_t nmemb,
					 const int16_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
double	alx_dbl_array_sum_u32		(ptrdiff_t nmemb,
					 const uint32_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
double	alx_dbl_array_sum_s32		(ptrdiff_t nmemb,
					 const int32_t arr[restrict nmemb]);

[[gnu::nonnull]] [[gnu::pure]]
inline
float	alx_flt_array_sum_flt		(ptrdiff_t nmemb,
					 const float arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
float	alx_flt_array_sum_u8		(ptrdiff_t nmemb,
					 const uint8_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
float	alx_flt_array_sum_s8		(ptrdiff_t nmemb,
					 const int8_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
float	alx_flt_array_sum_u16		(ptrdiff_t nmemb,
					 const uint16_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
inline
float	alx_flt_array_sum_s16		(ptrdiff_t nmemb,
					 const int16_t arr[restrict nmemb]);

[[gnu::nonnull]] [[gnu::pure]]
unsigned	alx_array_sum_uint	(ptrdiff_t nmemb,
					 const unsigned arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
int		alx_array_sum_int	(ptrdiff_t nmemb,
					 const int arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
uint8_t		alx_array_sum_u8	(ptrdiff_t nmemb,
					 const uint8_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
int8_t		alx_array_sum_s8	(ptrdiff_t nmemb,
					 const int8_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
uint16_t	alx_array_sum_u16	(ptrdiff_t nmemb,
					 const uint16_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
int16_t		alx_array_sum_s16	(ptrdiff_t nmemb,
					 const int16_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
uint32_t	alx_array_sum_u32	(ptrdiff_t nmemb,
					 const uint32_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
int32_t		alx_array_sum_s32	(ptrdiff_t nmemb,
					 const int32_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
uint64_t	alx_array_sum_u64	(ptrdiff_t nmemb,
					 const uint64_t arr[restrict nmemb]);
[[gnu::nonnull]] [[gnu::pure]]
int64_t		alx_array_sum_s64	(ptrdiff_t nmemb,
					 const int64_t arr[restrict nmemb]);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					 const long double arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	alx_ldbl_array_sum_uint	(ptrdiff_t nmemb,
					 const unsigned arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	alx_ldbl_array_sum_int	(ptrdiff_t nmemb,
					 const int arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	alx_ldbl_array_sum_u8	(ptrdiff_t nmemb,
					 const uint8_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	alx_ldbl_array_sum_s8	(ptrdiff_t nmemb,
					 const int8_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	alx_ldbl_array_sum_u16	(ptrdiff_t nmemb,
					 const uint16_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	alx_ldbl_array_sum_s16	(ptrdiff_t nmemb,
					 const int16_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	alx_ldbl_array_sum_u32	(ptrdiff_t nmemb,
					 const uint32_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	alx_ldbl_array_sum_s32	(ptrdiff_t nmemb,
					 const int32_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	alx_ldbl_array_sum_u64	(ptrdiff_t nmemb,
					 const uint64_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	alx_ldbl_array_sum_s64	(ptrdiff_t nmemb,
					 const int64_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


inline
double	alx_dbl_array_sum	(ptrdiff_t nmemb,
				 const double arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	alx_dbl_array_sum_uint	(ptrdiff_t nmemb,
				 const unsigned arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	alx_dbl_array_sum_int	(ptrdiff_t nmemb,
				 const int arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	alx_dbl_array_sum_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	alx_dbl_array_sum_s8	(ptrdiff_t nmemb,
				 const int8_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	alx_dbl_array_sum_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	alx_dbl_array_sum_s16	(ptrdiff_t nmemb,
				 const int16_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	alx_dbl_array_sum_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	alx_dbl_array_sum_s32	(ptrdiff_t nmemb,
				 const int32_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


inline
float	alx_flt_array_sum_flt	(ptrdiff_t nmemb,
				 const float arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
float	alx_flt_array_sum_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
float	alx_flt_array_sum_s8	(ptrdiff_t nmemb,
				 const int8_t arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
float	alx_flt_array_sum_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
float	alx_flt_array_sum_s16	(ptrdiff_t nmemb,
				 const int16_t arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
