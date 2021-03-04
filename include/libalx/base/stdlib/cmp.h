/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/cmp.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
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
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_ldbl	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp		(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_f	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_uint	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_int	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_char	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_u8	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_s8	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_u16	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_s16	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_u32	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_s32	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_u64	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]] [[gnu::pure]]
inline
int	alx_cmp_s64	(const void *a_ptr, const void *b_ptr);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(cmp_ldbl,	alx_cmp_ldbl);
ALX_ALIAS_DECLARATION(cmp,	alx_cmp);
ALX_ALIAS_DECLARATION(cmp_f,	alx_cmp_f);
ALX_ALIAS_DECLARATION(cmp_uint,	alx_cmp_uint);
ALX_ALIAS_DECLARATION(cmp_int,	alx_cmp_int);
ALX_ALIAS_DECLARATION(cmp_char,	alx_cmp_char);
ALX_ALIAS_DECLARATION(cmp_u8,	alx_cmp_u8);
ALX_ALIAS_DECLARATION(cmp_s8,	alx_cmp_s8);
ALX_ALIAS_DECLARATION(cmp_u16,	alx_cmp_u16);
ALX_ALIAS_DECLARATION(cmp_s16,	alx_cmp_s16);
ALX_ALIAS_DECLARATION(cmp_u32,	alx_cmp_u32);
ALX_ALIAS_DECLARATION(cmp_s32,	alx_cmp_s32);
ALX_ALIAS_DECLARATION(cmp_u64,	alx_cmp_u64);
ALX_ALIAS_DECLARATION(cmp_s64,	alx_cmp_s64);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
int	alx_cmp_ldbl	(const void *a_ptr, const void *b_ptr)
{
	long double	a =	*(const long double *)a_ptr;
	long double	b =	*(const long double *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp		(const void *a_ptr, const void *b_ptr)
{
	double	a =	*(const double *)a_ptr;
	double	b =	*(const double *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_f	(const void *a_ptr, const void *b_ptr)
{
	float	a =	*(const float *)a_ptr;
	float	b =	*(const float *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_uint	(const void *a_ptr, const void *b_ptr)
{
	unsigned	a =	*(const unsigned *)a_ptr;
	unsigned	b =	*(const unsigned *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_int	(const void *a_ptr, const void *b_ptr)
{
	int	a =	*(const int *)a_ptr;
	int	b =	*(const int *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_char	(const void *a_ptr, const void *b_ptr)
{
	char	a =	*(const char *)a_ptr;
	char	b =	*(const char *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_u8	(const void *a_ptr, const void *b_ptr)
{
	uint8_t	a =	*(const uint8_t *)a_ptr;
	uint8_t	b =	*(const uint8_t *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_s8	(const void *a_ptr, const void *b_ptr)
{
	int8_t	a =	*(const int8_t *)a_ptr;
	int8_t	b =	*(const int8_t *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_u16	(const void *a_ptr, const void *b_ptr)
{
	uint16_t	a =	*(const uint16_t *)a_ptr;
	uint16_t	b =	*(const uint16_t *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_s16	(const void *a_ptr, const void *b_ptr)
{
	int16_t	a =	*(const int16_t *)a_ptr;
	int16_t	b =	*(const int16_t *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_u32	(const void *a_ptr, const void *b_ptr)
{
	uint32_t	a =	*(const uint32_t *)a_ptr;
	uint32_t	b =	*(const uint32_t *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_s32	(const void *a_ptr, const void *b_ptr)
{
	int32_t	a =	*(const int32_t *)a_ptr;
	int32_t	b =	*(const int32_t *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_u64	(const void *a_ptr, const void *b_ptr)
{
	uint64_t	a =	*(const uint64_t *)a_ptr;
	uint64_t	b =	*(const uint64_t *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}

inline
int	alx_cmp_s64	(const void *a_ptr, const void *b_ptr)
{
	int64_t	a =	*(const int64_t *)a_ptr;
	int64_t	b =	*(const int64_t *)b_ptr;

	if (a < b)
		return	-1;
	if (a > b)
		return	1;
	return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
