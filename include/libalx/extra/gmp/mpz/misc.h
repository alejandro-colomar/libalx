/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gmp/mpz/misc.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdbool.h>

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
bool	alx_mpz_fits_u64	(const mpz_t op);
inline
bool	alx_mpz_fits_s64	(const mpz_t op);
inline
bool	alx_mpz_fits_u32	(const mpz_t op);
inline
bool	alx_mpz_fits_s32	(const mpz_t op);
inline
bool	alx_mpz_fits_u16	(const mpz_t op);
inline
bool	alx_mpz_fits_s16	(const mpz_t op);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(mpz_fits_u64, alx_mpz_fits_u64);
ALX_ALIAS_DECLARATION(mpz_fits_s64, alx_mpz_fits_s64);
ALX_ALIAS_DECLARATION(mpz_fits_u32, alx_mpz_fits_u32);
ALX_ALIAS_DECLARATION(mpz_fits_s32, alx_mpz_fits_s32);
ALX_ALIAS_DECLARATION(mpz_fits_u16, alx_mpz_fits_u16);
ALX_ALIAS_DECLARATION(mpz_fits_s16, alx_mpz_fits_s16);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
bool	alx_mpz_fits_u64	(const mpz_t op)
{
	return	mpz_fits_ulong_p(op);
}

inline
bool	alx_mpz_fits_s64	(const mpz_t op)
{
	return	mpz_fits_slong_p(op);
}

inline
bool	alx_mpz_fits_u32	(const mpz_t op)
{
	return	mpz_fits_uint_p(op);
}

inline
bool	alx_mpz_fits_s32	(const mpz_t op)
{
	return	mpz_fits_sint_p(op);
}

inline
bool	alx_mpz_fits_u16	(const mpz_t op)
{
	return	mpz_fits_ushort_p(op);
}

inline
bool	alx_mpz_fits_s16	(const mpz_t op)
{
	return	mpz_fits_sshort_p(op);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
