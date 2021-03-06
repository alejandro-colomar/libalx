/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gmp/mpz/cmp.h */

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
int	alx_mpz_cmp_s64		(const mpz_t op1, int64_t op2);
inline
int	alx_mpz_cmp_u64		(const mpz_t op1, uint64_t op2);
inline
int	alx_mpz_cmpabs_u64	(const mpz_t op1, uint64_t op2);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(mpz_cmp_s64,	alx_mpz_cmp_s64);
ALX_ALIAS_DECLARATION(mpz_cmp_u64,	alx_mpz_cmp_u64);
ALX_ALIAS_DECLARATION(mpz_cmpabs_u64,	alx_mpz_cmpabs_u64);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
int	alx_mpz_cmp_s64		(const mpz_t op1, int64_t op2)
{
	return	mpz_cmp_si(op1, op2);
}

inline
int	alx_mpz_cmp_u64		(const mpz_t op1, uint64_t op2)
{
	return	mpz_cmp_ui(op1, op2);
}

inline
int	alx_mpz_cmpabs_u64	(const mpz_t op1, uint64_t op2)
{
	return	mpz_cmpabs_ui(op1, op2);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
