/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/compiler/type.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/* Are two types/vars the same type (ignoring qualifiers)? */
#define alx_is_same_type(a, b)						\
	__builtin_types_compatible_p(__typeof__(a), __typeof__(b))
/* Is a an array? */
#define alx_is_array(a)			(!alx_is_same_type((a), &(a)[0]))
/* Is p a pointer? */
#define alx_is_pointer(p)		(!alx_is_array(p))
/* Is a a char array */
#define alx_is_char_array(a)		(alx_is_array(a)  &&		\
					 alx_is_same_type(char, (a)[0]))
/* Is x of unsigned type? */
#define alx_is_unsigned_type(x)		(((__typeof__(x))-1) > 0)
/* Is x of signed type? */
#define alx_is_signed_type(x)		(((__typeof__(x))-1) < 0)
/* Bit b overflows type t? */
#define alx_bit_overflows_type(b, t)	((size_t)b >= sizeof(t) * CHAR_BIT)
/* Is x of a basic type? */
#define alx_is_basic_type(x)		_Generic((x),			\
	char:			true,					\
	signed char:		true,					\
	unsigned char:		true,					\
	short:			true,					\
	unsigned char:		true,					\
	int:			true,					\
	unsigned int:		true,					\
	long:			true,					\
	unsigned long:		true,					\
	long long:		true,					\
	unsigned long long:	true,					\
	bool:			true,					\
	default:		false					\
)


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
#define same_type(a, b)			alx_same_type(a, b)
#define is_array(a)			alx_is_array(a)
#define is_pointer(p)			alx_is_pointer(p)
#define is_char_array(a)		alx_is_char_array(a)
#define is_unsigned_type(x)		alx_is_unsigned_type(x)
#define is_signed_type(x)		alx_is_signed_type(x)
#define bit_overflows_type(b, t)	alx_bit_overflows_type(b, t)
#define is_basic_type(x)		alx_is_basic_type(x)
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
