/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/clz.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <limits.h>
#include <stdint.h>

#include "libalx/base/assert/stdint.h"
#include "libalx/base/compiler/attribute.h"
#include "libalx/base/stdint/types.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/
alx_Static_assert_stdint_types();


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
uint8_t		alx_clz_u8	(uint8_t n);
[[gnu::const]]
inline
uint16_t	alx_clz_u16	(uint16_t n);
[[gnu::const]]
inline
uint32_t	alx_clz_u32	(uint32_t n);
[[gnu::const]]
inline
uint64_t	alx_clz_u64	(uint64_t n);
[[gnu::const]]
#if defined(UINT128_MAX)
[[gnu::const]]
inline
uint64_t	alx_clz_u128	(uint128_t n);
#endif
#if defined(UINT256_MAX)
[[gnu::const]]
inline
uint64_t	alx_clz_u256	(uint256_t n);
#endif


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(clz_u8,	alx_clz_u8);
ALX_ALIAS_DECLARATION(clz_u16,	alx_clz_u16);
ALX_ALIAS_DECLARATION(clz_u32,	alx_clz_u32);
ALX_ALIAS_DECLARATION(clz_u64,	alx_clz_u64);
# if defined(UINT128_MAX)
ALX_ALIAS_DECLARATION(clz_u128,	alx_clz_u128);
# endif
# if defined(UINT256_MAX)
ALX_ALIAS_DECLARATION(clz_u256,	alx_clz_u256);
# endif
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
//#pragma GCC diagnostic push	/* Over/underflow is impossible */
//#pragma GCC diagnostic ignored	"-Wconversion"
inline
uint8_t		alx_clz_u8	(uint8_t n)
{
	static const uint8_t unused_bytes = sizeof(unsigned) - sizeof(uint8_t);
	static const uint8_t unused_bits = unused_bytes * CHAR_BIT;

	return	__builtin_clz(n) - unused_bits;
}

inline
uint16_t	alx_clz_u16	(uint16_t n)
{
	static const uint8_t unused_bytes = sizeof(unsigned) - sizeof(uint16_t);
	static const uint8_t unused_bits = unused_bytes * CHAR_BIT;

	return	__builtin_clz(n) - unused_bits;
}
//#pragma GCC diagnostic pop

//#pragma GCC diagnostic push	/* Overflow is impossible */
//#pragma GCC diagnostic ignored	"-Wsign-conversion"
inline
uint32_t	alx_clz_u32	(uint32_t n)
{

	return	__builtin_clz(n);
}

inline
uint64_t	alx_clz_u64	(uint64_t n)
{

	return	__builtin_clzl(n);
}
//#pragma GCC diagnostic pop

//#pragma GCC diagnostic push	/* Modulo truncation is useful here */
//#pragma GCC diagnostic ignored	"-Wconversion"
#if defined(UINT128_MAX)
inline
uint64_t	alx_clz_u128	(uint128_t n)
{

	if (!(uint64_t)(n >> 64))
		return	64 + alx_clz_u64(n);
	return	alx_clz_u64(n >> 64);
}
#endif

#if defined(UINT256_MAX)
inline
uint64_t	alx_clz_u256	(uint256_t n)
{

	if (!(uint128_t)(n >> 128))
		return	128 + alx_clz_u128(n);
	return	alx_clz_u128(n >> 128);
}
#endif
//#pragma GCC diagnostic pop


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
