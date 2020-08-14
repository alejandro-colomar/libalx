/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gmp/mpz/arithmetic.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdint.h>

#include <gmp.h>

#include "libalx/base/assert/stdint.h"
#include "libalx/base/compiler/attribute.h"


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
inline
void	alx_mpz_add_u64		(mpz_t rop, const mpz_t op1, uint64_t op2);
inline
void	alx_mpz_sub_u64		(mpz_t rop, const mpz_t op1, uint64_t op2);
inline
void	alx_mpz_u64_sub		(mpz_t rop, uint64_t op1, const mpz_t op2);
inline
void	alx_mpz_mul_u64		(mpz_t rop, const mpz_t op1, uint64_t op2);
inline
void	alx_mpz_mul_s64		(mpz_t rop, const mpz_t op1, int64_t op2);
inline
void	alx_mpz_addmul_u64	(mpz_t rop, const mpz_t op1, uint64_t op2);
inline
void	alx_mpz_submul_u64	(mpz_t rop, const mpz_t op1, uint64_t op2);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(mpz_add_u64,	alx_mpz_add_u64);
ALX_ALIAS_DECLARATION(mpz_sub_u64,	alx_mpz_sub_u64);
ALX_ALIAS_DECLARATION(mpz_u64_sub,	alx_mpz_u64_sub);
ALX_ALIAS_DECLARATION(mpz_mul_u64,	alx_mpz_mul_u64);
ALX_ALIAS_DECLARATION(mpz_mul_s64,	alx_mpz_mul_s64);
ALX_ALIAS_DECLARATION(mpz_addmul_u64,	alx_mpz_addmul_u64);
ALX_ALIAS_DECLARATION(mpz_submul_u64,	alx_mpz_submul_u64);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
void	alx_mpz_add_u64		(mpz_t rop, const mpz_t op1, uint64_t op2)
{
	mpz_add_ui(rop, op1, op2);
}

inline
void	alx_mpz_sub_u64		(mpz_t rop, const mpz_t op1, uint64_t op2)
{
	mpz_sub_ui(rop, op1, op2);
}

inline
void	alx_mpz_u64_sub		(mpz_t rop, uint64_t op1, const mpz_t op2)
{
	mpz_ui_sub(rop, op1, op2);
}

inline
void	alx_mpz_mul_u64		(mpz_t rop, const mpz_t op1, uint64_t op2)
{
	mpz_mul_ui(rop, op1, op2);
}

inline
void	alx_mpz_mul_s64		(mpz_t rop, const mpz_t op1, int64_t op2)
{
	mpz_mul_si(rop, op1, op2);
}

inline
void	alx_mpz_addmul_u64	(mpz_t rop, const mpz_t op1, uint64_t op2)
{
	mpz_addmul_ui(rop, op1, op2);
}

inline
void	alx_mpz_submul_u64	(mpz_t rop, const mpz_t op1, uint64_t op2)
{
	mpz_submul_ui(rop, op1, op2);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
