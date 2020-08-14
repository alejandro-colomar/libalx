/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/math/scale_linear.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <math.h>
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
[[gnu::const]]
inline
long double	alx_scale_linear_ldbl	(long double input,
					 long double in_lo, long double in_hi,
					 long double out_lo, long double out_hi);
[[gnu::const]]
inline
double		alx_scale_linear	(double input,
					 double in_lo, double in_hi,
					 double out_lo, double out_hi);
[[gnu::const]]
inline
float		alx_scale_linear_flt	(float input,
					 float in_lo, float in_hi,
					 float out_lo, float out_hi);
[[gnu::const]]
inline
unsigned	alx_scale_linear_uint	(unsigned input,
					 unsigned in_lo, unsigned in_hi,
					 unsigned out_lo, unsigned out_hi);
[[gnu::const]]
inline
int		alx_scale_linear_int	(int input,
					 int in_lo, int in_hi,
					 int out_lo, int out_hi);
[[gnu::const]]
inline
uint8_t		alx_scale_linear_u8	(uint8_t input,
					 uint8_t in_lo, uint8_t in_hi,
					 uint8_t out_lo, uint8_t out_hi);
[[gnu::const]]
inline
int8_t		alx_scale_linear_s8	(int8_t input,
					 int8_t in_lo, int8_t in_hi,
					 int8_t out_lo, int8_t out_hi);
[[gnu::const]]
inline
uint16_t	alx_scale_linear_u16	(uint16_t input,
					 uint16_t in_lo, uint16_t in_hi,
					 uint16_t out_lo, uint16_t out_hi);
[[gnu::const]]
inline
int16_t		alx_scale_linear_s16	(int16_t input,
					 int16_t in_lo, int16_t in_hi,
					 int16_t out_lo, int16_t out_hi);
[[gnu::const]]
inline
uint32_t	alx_scale_linear_u32	(uint32_t input,
					 uint32_t in_lo, uint32_t in_hi,
					 uint32_t out_lo, uint32_t out_hi);
[[gnu::const]]
inline
int32_t		alx_scale_linear_s32	(int32_t input,
					 int32_t in_lo, int32_t in_hi,
					 int32_t out_lo, int32_t out_hi);
[[gnu::const]]
inline
uint64_t	alx_scale_linear_u64	(uint64_t input,
					 uint64_t in_lo, uint64_t in_hi,
					 uint64_t out_lo, uint64_t out_hi);
[[gnu::const]]
inline
int64_t		alx_scale_linear_s64	(int64_t input,
					 int64_t in_lo, int64_t in_hi,
					 int64_t out_lo, int64_t out_hi);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double	alx_scale_linear_ldbl	(long double input,
					long double in_lo, long double in_hi,
					long double out_lo, long double out_hi)
{
	long double	normalized;
	long double	output;

	normalized	= (input - in_lo) / (in_hi - in_lo);
	output		= out_lo + normalized * (out_hi - out_lo);

	return	output;
}

inline
double		alx_scale_linear	(double input,
					double in_lo, double in_hi,
					double out_lo, double out_hi)
{
	double_t	normalized;
	double		output;

	normalized	= (input - in_lo) / (in_hi - in_lo);
	output		= out_lo + normalized * (out_hi - out_lo);

	return	output;
}

inline
float		alx_scale_linear_flt	(float input,
					float in_lo, float in_hi,
					float out_lo, float out_hi)
{
	float_t	normalized;
	float	output;

	normalized	= (input - in_lo) / (in_hi - in_lo);
	output		= out_lo + normalized * (out_hi - out_lo);

	return	output;
}

/* FIXME: Write new functions which return error code for over/underflow */
//#pragma GCC diagnostic push	/* No over(/under)flow for valid input */
//#pragma GCC diagnostic ignored	"-Wfloat-conversion"
//#pragma GCC diagnostic ignored	"-Wconversion"
inline
unsigned	alx_scale_linear_uint	(unsigned input,
					unsigned in_lo, unsigned in_hi,
					unsigned out_lo, unsigned out_hi)
{
	double_t	input_	= input;
	double_t	in_lo_	= in_lo;
	double_t	in_hi_	= in_hi;
	double_t	out_lo_	= out_lo;
	double_t	out_hi_	= out_hi;
	double_t	normalized;
	unsigned	output;

	normalized	= (input_ - in_lo_) / (in_hi_ - in_lo_);
	output		= out_lo_ + normalized * (out_hi_ - out_lo_);

	return	output;
}

inline
int		alx_scale_linear_int	(int input,
					int in_lo, int in_hi,
					int out_lo, int out_hi)
{
	double_t	input_	= input;
	double_t	in_lo_	= in_lo;
	double_t	in_hi_	= in_hi;
	double_t	out_lo_	= out_lo;
	double_t	out_hi_	= out_hi;
	double_t	normalized;
	int		output;

	normalized	= (input_ - in_lo_) / (in_hi_ - in_lo_);
	output		= out_lo_ + normalized * (out_hi_ - out_lo_);

	return	output;
}

inline
uint8_t		alx_scale_linear_u8	(uint8_t input,
					uint8_t in_lo, uint8_t in_hi,
					uint8_t out_lo, uint8_t out_hi)
{
	uint_fast16_t	input_	= input;
	uint_fast16_t	in_lo_	= in_lo;
	uint_fast16_t	in_hi_	= in_hi;
	uint_fast16_t	out_lo_	= out_lo;
	uint_fast16_t	out_hi_	= out_hi;
	uint_fast16_t	tmp;
	uint8_t		output;

	tmp	= (input_ - in_lo_) * (out_hi_ - out_lo_);
	output	= out_lo_ + tmp / (in_hi_ - in_lo_);

	return	output;
}

inline
int8_t		alx_scale_linear_s8	(int8_t input,
					int8_t in_lo, int8_t in_hi,
					int8_t out_lo, int8_t out_hi)
{
	int_fast16_t	input_	= input;
	int_fast16_t	in_lo_	= in_lo;
	int_fast16_t	in_hi_	= in_hi;
	int_fast16_t	out_lo_	= out_lo;
	int_fast16_t	out_hi_	= out_hi;
	int_fast16_t	tmp;
	int8_t		output;

	tmp	= (input_ - in_lo_) * (out_hi_ - out_lo_);
	output	= out_lo_ + tmp / (in_hi_ - in_lo_);

	return	output;
}

inline
uint16_t	alx_scale_linear_u16	(uint16_t input,
					uint16_t in_lo, uint16_t in_hi,
					uint16_t out_lo, uint16_t out_hi)
{
	uint_fast32_t	input_	= input;
	uint_fast32_t	in_lo_	= in_lo;
	uint_fast32_t	in_hi_	= in_hi;
	uint_fast32_t	out_lo_	= out_lo;
	uint_fast32_t	out_hi_	= out_hi;
	uint_fast32_t	tmp;
	uint16_t	output;

	tmp	= (input_ - in_lo_) * (out_hi_ - out_lo_);
	output	= out_lo_ + tmp / (in_hi_ - in_lo_);

	return	output;
}

inline
int16_t		alx_scale_linear_s16	(int16_t input,
					int16_t in_lo, int16_t in_hi,
					int16_t out_lo, int16_t out_hi)
{
	int_fast32_t	input_	= input;
	int_fast32_t	in_lo_	= in_lo;
	int_fast32_t	in_hi_	= in_hi;
	int_fast32_t	out_lo_	= out_lo;
	int_fast32_t	out_hi_	= out_hi;
	int_fast32_t	tmp;
	int16_t		output;

	tmp	= (input_ - in_lo_) * (out_hi_ - out_lo_);
	output	= out_lo_ + tmp / (in_hi_ - in_lo_);

	return	output;
}

inline
uint32_t	alx_scale_linear_u32	(uint32_t input,
					uint32_t in_lo, uint32_t in_hi,
					uint32_t out_lo, uint32_t out_hi)
{
	uint_fast64_t	input_	= input;
	uint_fast64_t	in_lo_	= in_lo;
	uint_fast64_t	in_hi_	= in_hi;
	uint_fast64_t	out_lo_	= out_lo;
	uint_fast64_t	out_hi_	= out_hi;
	uint_fast64_t	tmp;
	uint32_t	output;

	tmp	= (input_ - in_lo_) * (out_hi_ - out_lo_);
	output	= out_lo_ + tmp / (in_hi_ - in_lo_);

	return	output;
}

inline
int32_t		alx_scale_linear_s32	(int32_t input,
					int32_t in_lo, int32_t in_hi,
					int32_t out_lo, int32_t out_hi)
{
	int_fast64_t	input_	= input;
	int_fast64_t	in_lo_	= in_lo;
	int_fast64_t	in_hi_	= in_hi;
	int_fast64_t	out_lo_	= out_lo;
	int_fast64_t	out_hi_	= out_hi;
	int_fast64_t	tmp;
	int32_t		output;

	tmp	= (input_ - in_lo_) * (out_hi_ - out_lo_);
	output	= out_lo_ + tmp / (in_hi_ - in_lo_);

	return	output;
}

inline
uint64_t	alx_scale_linear_u64	(uint64_t input,
					uint64_t in_lo, uint64_t in_hi,
					uint64_t out_lo, uint64_t out_hi)
{
	long double	input_	= input;
	long double	in_lo_	= in_lo;
	long double	in_hi_	= in_hi;
	long double	out_lo_	= out_lo;
	long double	out_hi_	= out_hi;
	long double	tmp;
	uint64_t	output;

	tmp	= (input_ - in_lo_) * (out_hi_ - out_lo_);
	output	= out_lo_ + tmp / (in_hi_ - in_lo_);

	return	output;
}

inline
int64_t		alx_scale_linear_s64	(int64_t input,
					int64_t in_lo, int64_t in_hi,
					int64_t out_lo, int64_t out_hi)
{
	long double	input_	= input;
	long double	in_lo_	= in_lo;
	long double	in_hi_	= in_hi;
	long double	out_lo_	= out_lo;
	long double	out_hi_	= out_hi;
	long double	tmp;
	int64_t		output;

	tmp	= (input_ - in_lo_) * (out_hi_ - out_lo_);
	output	= out_lo_ + tmp / (in_hi_ - in_lo_);

	return	output;
}
//#pragma GCC diagnostic pop


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
