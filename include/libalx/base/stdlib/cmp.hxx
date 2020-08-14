/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/cmp.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdint>

#include "libalx/base/compiler/attribute.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


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
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_ldbl	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp		(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_f	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_uint	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_int	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_char	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_u8	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_s8	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_u16	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_s16	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_u32	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_s32	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
int	alx_cmp_u64	(const void *a_ptr, const void *b_ptr);
[[gnu::nonnull]][[gnu::pure]]
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
