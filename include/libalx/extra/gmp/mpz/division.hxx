/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gmp/mpz/division.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdbool>
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
uint64_t alx_mpz_cdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d);
uint64_t alx_mpz_cdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d);
uint64_t alx_mpz_cdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d);
uint64_t alx_mpz_cdiv_u64	(const mpz_t n, uint64_t d);

uint64_t alx_mpz_fdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d);
uint64_t alx_mpz_fdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d);
uint64_t alx_mpz_fdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d);
uint64_t alx_mpz_fdiv_u64	(const mpz_t n, uint64_t d);

uint64_t alx_mpz_tdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d);
uint64_t alx_mpz_tdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d);
uint64_t alx_mpz_tdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d);
uint64_t alx_mpz_tdiv_u64	(const mpz_t n, uint64_t d);

uint64_t alx_mpz_mod_u64	(mpz_t r, const mpz_t n, uint64_t d);
void	alx_mpz_divexact_u64	(mpz_t q, const mpz_t n, uint64_t d);
bool	alx_mpz_divisible_u64_p	(const mpz_t n, uint64_t d);
bool	alx_mpz_congruent_u64_p	(const mpz_t n, uint64_t c, uint64_t d);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(mpz_cdiv_q_u64,		alx_mpz_cdiv_q_u64);
ALX_ALIAS_DECLARATION(mpz_cdiv_r_u64,		alx_mpz_cdiv_r_u64);
ALX_ALIAS_DECLARATION(mpz_cdiv_qr_u64,		alx_mpz_cdiv_qr_u64);
ALX_ALIAS_DECLARATION(mpz_cdiv_u64,		alx_mpz_cdiv_u64);
ALX_ALIAS_DECLARATION(mpz_fdiv_q_u64,		alx_mpz_fdiv_q_u64);
ALX_ALIAS_DECLARATION(mpz_fdiv_r_u64,		alx_mpz_fdiv_r_u64);
ALX_ALIAS_DECLARATION(mpz_fdiv_qr_u64,		alx_mpz_fdiv_qr_u64);
ALX_ALIAS_DECLARATION(mpz_fdiv_u64,		alx_mpz_fdiv_u64);
ALX_ALIAS_DECLARATION(mpz_tdiv_q_u64,		alx_mpz_tdiv_q_u64);
ALX_ALIAS_DECLARATION(mpz_tdiv_r_u64,		alx_mpz_tdiv_r_u64);
ALX_ALIAS_DECLARATION(mpz_tdiv_qr_u64,		alx_mpz_tdiv_qr_u64);
ALX_ALIAS_DECLARATION(mpz_tdiv_u64,		alx_mpz_tdiv_u64);
ALX_ALIAS_DECLARATION(mpz_mod_u64,		alx_mpz_mod_u64);
ALX_ALIAS_DECLARATION(mpz_divexact_u64,		alx_mpz_divexact_u64);
ALX_ALIAS_DECLARATION(mpz_divisible_u64_p,	alx_mpz_divisible_u64_p);
ALX_ALIAS_DECLARATION(mpz_congruent_u64_p,	alx_mpz_congruent_u64_p);
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
