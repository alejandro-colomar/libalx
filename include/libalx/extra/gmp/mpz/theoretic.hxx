/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gmp/mpz/theoretic.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdint>

#include <gmp.h>

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
void	alx_mpz_gcd_u64		(mpz_t rop, const mpz_t op1, uint64_t op2);
void	alx_mpz_lcm_u64		(mpz_t rop, const mpz_t op1, uint64_t op2);

int32_t	alx_mpz_kronecker_s64	(const mpz_t a, int64_t b);
int32_t	alx_mpz_kronecker_u64	(const mpz_t a, uint64_t b);
int32_t	alx_mpz_s64_kronecker	(int64_t a, const mpz_t b);
int32_t	alx_mpz_u64_kronecker	(uint64_t a, const mpz_t b);

void	alx_mpz_fac_u64		(mpz_t rop, uint64_t n);
void	alx_mpz_2fac_u64	(mpz_t rop, uint64_t n);
void	alx_mpz_mfac_u64	(mpz_t rop, uint64_t n, uint64_t m);

void	alx_mpz_primorial_u64	(mpz_t rop, uint64_t n);

void	alx_mpz_bin_u64		(mpz_t rop, const mpz_t n, uint64_t k);
void	alx_mpz_bin_u64u64	(mpz_t rop, uint64_t n, uint64_t k);

void	alx_mpz_fib_u64		(mpz_t fn, uint64_t n);
void	alx_mpz_fib2_u64	(mpz_t fn, mpz_t fnsub1, uint64_t n);

void	alx_mpz_lucnum_u64	(mpz_t ln, uint64_t n);
void	alx_mpz_lucnum2_u64	(mpz_t ln, mpz_t lnsub1, uint64_t n);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define mpz_gcd_u64(rop, op1, op2)	alx_mpz_gcd_u64(rop, op1, op2)
#define mpz_lcm_u64(rop, op1, op2)	alx_mpz_lcm_u64(rop, op1, op2)
#define mpz_kronecker_s64(a, b)		alx_mpz_kronecker_s64(a, b)
#define mpz_kronecker_u64(a, b)		alx_mpz_kronecker_u64(a, b)
#define mpz_s64_kronecker(a, b)		alx_mpz_s64_kronecker(a, b)
#define mpz_u64_kronecker(a, b)		alx_mpz_u64_kronecker(a, b)
#define mpz_fac_u64(rop, n)		alx_mpz_fac_u64(rop, n)
#define mpz_2fac_u64(rop, n)		alx_mpz_2fac_u64(rop, n)
#define mpz_mfac_u64(rop, n, m)		alx_mpz_mfac_u64(rop, n, m)
#define mpz_primorial_u64(rop, n)	alx_mpz_primorial_u64(rop, n)
#define mpz_bin_u64(rop, n, k)		alx_mpz_bin_u64(rop, n, k)
#define mpz_bin_u64u64(rop, n, k)	alx_mpz_bin_u64u64(rop, n, k)
#define mpz_fib_u64(fn, n)		alx_mpz_fib_u64(fn, n)
#define mpz_fib2_u64(fn, fnsub1, n)	alx_mpz_fib2_u64(fn, fnsub1, n)
#define mpz_lucnum_u64(ln, n)		alx_mpz_lucnum_u64(ln, n)
#define mpz_lucnum2_u64(ln, lnsub1, n)	alx_mpz_lucnum2_u64(ln, lnsub1, n)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
}	/* extern "C" */


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace gmp {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace gmp */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
