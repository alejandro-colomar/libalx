/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gmp/mpz/theoretic.h */

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
void	alx_mpz_gcd_u64		(mpz_t rop, const mpz_t op1, uint64_t op2);
inline
void	alx_mpz_lcm_u64		(mpz_t rop, const mpz_t op1, uint64_t op2);

inline
int32_t	alx_mpz_kronecker_s64	(const mpz_t a, int64_t b);
inline
int32_t	alx_mpz_kronecker_u64	(const mpz_t a, uint64_t b);
inline
int32_t	alx_mpz_s64_kronecker	(int64_t a, const mpz_t b);
inline
int32_t	alx_mpz_u64_kronecker	(uint64_t a, const mpz_t b);

inline
void	alx_mpz_fac_u64		(mpz_t rop, uint64_t n);
inline
void	alx_mpz_2fac_u64	(mpz_t rop, uint64_t n);
inline
void	alx_mpz_mfac_u64	(mpz_t rop, uint64_t n, uint64_t m);

inline
void	alx_mpz_primorial_u64	(mpz_t rop, uint64_t n);

inline
void	alx_mpz_bin_u64		(mpz_t rop, const mpz_t n, uint64_t k);
inline
void	alx_mpz_bin_u64u64	(mpz_t rop, uint64_t n, uint64_t k);

inline
void	alx_mpz_fib_u64		(mpz_t fn, uint64_t n);
inline
void	alx_mpz_fib2_u64	(mpz_t fn, mpz_t fnsub1, uint64_t n);

inline
void	alx_mpz_lucnum_u64	(mpz_t ln, uint64_t n);
inline
void	alx_mpz_lucnum2_u64	(mpz_t ln, mpz_t lnsub1, uint64_t n);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(mpz_gcd_u64,		alx_mpz_gcd_u64);
ALX_ALIAS_DECLARATION(mpz_lcm_u64,		alx_mpz_lcm_u64);
ALX_ALIAS_DECLARATION(mpz_kronecker_s64,	alx_mpz_kronecker_s64);
ALX_ALIAS_DECLARATION(mpz_kronecker_u64,	alx_mpz_kronecker_u64);
ALX_ALIAS_DECLARATION(mpz_s64_kronecker,	alx_mpz_s64_kronecker);
ALX_ALIAS_DECLARATION(mpz_u64_kronecker,	alx_mpz_u64_kronecker);
ALX_ALIAS_DECLARATION(mpz_fac_u64,		alx_mpz_fac_u64);
ALX_ALIAS_DECLARATION(mpz_2fac_u64,		alx_mpz_2fac_u64);
ALX_ALIAS_DECLARATION(mpz_mfac_u64,		alx_mpz_mfac_u64);
ALX_ALIAS_DECLARATION(mpz_primorial_u64,	alx_mpz_primorial_u64);
ALX_ALIAS_DECLARATION(mpz_bin_u64,		alx_mpz_bin_u64);
ALX_ALIAS_DECLARATION(mpz_bin_u64u64,		alx_mpz_bin_u64u64);
ALX_ALIAS_DECLARATION(mpz_fib_u64,		alx_mpz_fib_u64);
ALX_ALIAS_DECLARATION(mpz_fib2_u64,		alx_mpz_fib2_u64);
ALX_ALIAS_DECLARATION(mpz_lucnum_u64,		alx_mpz_lucnum_u64);
ALX_ALIAS_DECLARATION(mpz_lucnum2_u64,		alx_mpz_lucnum2_u64);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
void	alx_mpz_gcd_u64		(mpz_t rop, const mpz_t op1, uint64_t op2)
{
	mpz_gcd_ui(rop, op1, op2);
}

inline
void	alx_mpz_lcm_u64		(mpz_t rop, const mpz_t op1, uint64_t op2)
{
	mpz_lcm_ui(rop, op1, op2);
}


inline
int32_t	alx_mpz_kronecker_s64	(const mpz_t a, int64_t b)
{
	return	mpz_kronecker_si(a, b);
}

inline
int32_t	alx_mpz_s64_kronecker	(int64_t a, const mpz_t b)
{
	return	mpz_si_kronecker(a, b);
}

inline
int32_t	alx_mpz_u64_kronecker	(uint64_t a, const mpz_t b)
{
	return	mpz_ui_kronecker(a, b);
}

inline
int32_t	alx_mpz_kronecker_u64	(const mpz_t a, uint64_t b)
{
	return	mpz_kronecker_ui(a, b);
}


inline
void	alx_mpz_fac_u64		(mpz_t rop, uint64_t n)
{
	mpz_fac_ui(rop, n);
}

inline
void	alx_mpz_2fac_u64	(mpz_t rop, uint64_t n)
{
	mpz_2fac_ui(rop, n);
}

inline
void	alx_mpz_mfac_u64	(mpz_t rop, uint64_t n, uint64_t m)
{
	mpz_mfac_uiui(rop, n, m);
}


inline
void	alx_mpz_primorial_u64	(mpz_t rop, uint64_t n)
{
	mpz_primorial_ui(rop, n);
}


inline
void	alx_mpz_bin_u64		(mpz_t rop, const mpz_t n, uint64_t k)
{
	mpz_bin_ui(rop, n, k);
}

inline
void	alx_mpz_bin_u64u64	(mpz_t rop, uint64_t n, uint64_t k)
{
	mpz_bin_uiui(rop, n, k);
}


inline
void	alx_mpz_fib_u64		(mpz_t fn, uint64_t n)
{
	mpz_fib_ui(fn, n);
}

inline
void	alx_mpz_fib2_u64	(mpz_t fn, mpz_t fnsub1, uint64_t n)
{
	mpz_fib2_ui(fn, fnsub1, n);
}


inline
void	alx_mpz_lucnum_u64	(mpz_t ln, uint64_t n)
{
	mpz_lucnum_ui(ln, n);
}

inline
void	alx_mpz_lucnum2_u64	(mpz_t ln, mpz_t lnsub1, uint64_t n)
{
	mpz_lucnum2_ui(ln, lnsub1, n);
}



/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
