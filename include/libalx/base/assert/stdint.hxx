/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/stdint.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cassert>
#include <cstdint>

#include "libalx/base/assert/assert.hxx"
#include "libalx/base/compiler/type.hxx"


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
	static_assert(alx_is_same_type(uint8_t, unsigned char),		\
				   "uint8_t != unsigned char")

#define alx_Static_assert_s8_schar()					\
	static_assert(alx_is_same_type( int8_t, signed char),		\
				    "int8_t != signed char")

#define alx_Static_assert_u16_ushort()					\
	static_assert(alx_is_same_type(uint16_t, unsigned short),	\
				   "uint16_t != unsigned short")

#define alx_Static_assert_s16_short()					\
	static_assert(alx_is_same_type( int16_t, short),		\
				    "int16_t != short")

#define alx_Static_assert_u32_unsigned()				\
	static_assert(alx_is_same_type(uint32_t, unsigned),		\
				   "uint32_t != unsigned")

#define alx_Static_assert_s32_int()					\
	static_assert(alx_is_same_type( int32_t, int),			\
				    "int32_t != int")

#define alx_Static_assert_u64_ulong()					\
	static_assert(alx_is_same_type(uint64_t, unsigned long),	\
				   "uint64_t != unsigned long")

#define alx_Static_assert_s64_long()					\
	static_assert(alx_is_same_type( int64_t, long),			\
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
	alx_assert_msg(alx_is_same_type(uint8_t, unsigned char),	\
			 "BUG:   uint8_t != unsigned char")

#define alx_assert_s8_schar()						\
	alx_assert_msg(alx_is_same_type(int8_t, signed char),		\
			 "BUG:   int8_t != signed char")

#define alx_assert_u16_ushort()						\
	alx_assert_msg(alx_is_same_type(uint16_t, unsigned short),	\
			 "BUG:   uint16_t != unsigned short")

#define alx_assert_s16_short()						\
	alx_assert_msg(alx_is_same_type(int16_t, short),		\
			 "BUG:   int16_t != short")

#define alx_assert_u32_unsigned()					\
	alx_assert_msg(alx_is_same_type(uint32_t, unsigned),		\
			 "BUG:   uint32_t != unsigned")

#define alx_assert_s32_int()						\
	alx_assert_msg(alx_is_same_type(int32_t, int),			\
			 "BUG:   int32_t != int")

#define alx_assert_u64_ulong()						\
	alx_assert_msg(alx_is_same_type(uint64_t, unsigned long),	\
			 "BUG:   uint64_t != unsigned long")

#define alx_assert_s64_long()						\
	alx_assert_msg(alx_is_same_type(int64_t, long),			\
			 "BUG:   int64_t != long")


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
