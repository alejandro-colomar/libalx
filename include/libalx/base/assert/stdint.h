/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/stdint.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdint.h>

#include "libalx/base/assert/assert.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define alx_Static_assert_stdint_types()				\
	alx_Static_assert_u8_uchar();					\
	alx_Static_assert_s8_schar();					\
	alx_Static_assert_u16_ushort();					\
	alx_Static_assert_s16_short();					\
	alx_Static_assert_u32_unsigned();				\
	alx_Static_assert_s32_int();					\
	alx_Static_assert_u64_ulong();					\
	alx_Static_assert_s64_long()

#define alx_Static_assert_u8_uchar()					\
	_Static_assert(__builtin_types_compatible_p(			\
			 uint8_t, unsigned char),			\
			"uint8_t != unsigned char")

#define alx_Static_assert_s8_schar()					\
	_Static_assert(__builtin_types_compatible_p(			\
			 int8_t, signed char),				\
			"int8_t != signed char")

#define alx_Static_assert_u16_ushort()					\
	_Static_assert(__builtin_types_compatible_p(			\
			 uint16_t, unsigned short),			\
			"uint16_t != unsigned short")

#define alx_Static_assert_s16_short()					\
	_Static_assert(__builtin_types_compatible_p(			\
			 int16_t, short),				\
			"int16_t != short")

#define alx_Static_assert_u32_unsigned()				\
	_Static_assert(__builtin_types_compatible_p(			\
			 uint32_t, unsigned),				\
			"uint32_t != unsigned")

#define alx_Static_assert_s32_int()					\
	_Static_assert(__builtin_types_compatible_p(			\
			 int32_t, int),					\
			"int32_t != int")

#define alx_Static_assert_u64_ulong()					\
	_Static_assert(__builtin_types_compatible_p(			\
			 uint64_t, unsigned long),			\
			"uint64_t != unsigned long")

#define alx_Static_assert_s64_long()					\
	_Static_assert(__builtin_types_compatible_p(			\
			 int64_t, long),				\
			"int64_t != long")

#define alx_assert_stdint_types()					\
	alx_assert_u8_uchar();						\
	alx_assert_s8_schar();						\
	alx_assert_u16_ushort();					\
	alx_assert_s16_short();						\
	alx_assert_u32_unsigned();					\
	alx_assert_s32_int();						\
	alx_assert_u64_ulong();						\
	alx_assert_s64_long()

#define alx_assert_u8_uchar()						\
	alx_assert_msg(__builtin_types_compatible_p(			\
				uint8_t, unsigned char),		\
			"BUG:   uint8_t != unsigned char")

#define alx_assert_s8_schar()						\
	alx_assert_msg(__builtin_types_compatible_p(			\
				int8_t, signed char),			\
			"BUG:   int8_t != signed char")

#define alx_assert_u16_ushort()						\
	alx_assert_msg(__builtin_types_compatible_p(			\
				uint16_t, unsigned short),		\
			"BUG:   uint16_t != unsigned short")

#define alx_assert_s16_short()						\
	alx_assert_msg(__builtin_types_compatible_p(			\
				int16_t, short),			\
			"BUG:   int16_t != short")

#define alx_assert_u32_unsigned()					\
	alx_assert_msg(__builtin_types_compatible_p(			\
				uint32_t, unsigned),			\
			"BUG:   uint32_t != unsigned")

#define alx_assert_s32_int()						\
	alx_assert_msg(__builtin_types_compatible_p(			\
				int32_t, int),				\
			"BUG:   int32_t != int")

#define alx_assert_u64_ulong()						\
	alx_assert_msg(__builtin_types_compatible_p(			\
				uint64_t, unsigned long),		\
			"BUG:   uint64_t != unsigned long")

#define alx_assert_s64_long()						\
	alx_assert_msg(__builtin_types_compatible_p(			\
				int64_t, long),				\
			"BUG:   int64_t != long")


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define Static_assert_stdint_types()	alx_Static_assert_stdint_types()
#define Static_assert_u8_uchar()	alx_Static_assert_u8_uchar()
#define Static_assert_s8_schar()	alx_Static_assert_s8_schar()
#define Static_assert_u16_ushort()	alx_Static_assert_u16_ushort()
#define Static_assert_s16_short()	alx_Static_assert_s16_short()
#define Static_assert_u32_unsigned()	alx_Static_assert_u32_unsigned()
#define Static_assert_s32_int()		alx_Static_assert_s32_int()
#define Static_assert_u64_ulong()	alx_Static_assert_u64_ulong()
#define Static_assert_s64_long()	alx_Static_assert_s64_long()
#define assert_stdint_types()		alx_assert_stdint_types()
#define assert_u8_uchar()		alx_assert_u8_uchar()
#define assert_s8_schar()		alx_assert_s8_schar()
#define assert_u16_ushort()		alx_assert_u16_ushort()
#define assert_s16_short()		alx_assert_s16_short()
#define assert_u32_unsigned()		alx_assert_u32_unsigned()
#define assert_s32_int()		alx_assert_s32_int()
#define assert_u64_ulong()		alx_assert_u64_ulong()
#define assert_s64_long()		alx_assert_s64_long()
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
