/******************************************************************************
 *	Copyright (C) 2012	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/npcomplete/solver_lut.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/stdlib/popcnt.h"


/******************************************************************************
 ******* typedef **************************************************************
 ******************************************************************************/
typedef	uint64_t	uint256_a[4];


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define LUTBIT_SZ	(lut_sz / 64 + (lut_sz % 64 != 0))


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
	/*
	 * Trick for using
	 *	ARRAY_SSIZE(foovar__256b)	or
	 *	ARRAY_BYTES(foovar__256b)
	 */
extern	uint256_a	foovar__256b;


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::nonnull]]
int	alx_npcomplete_solver_lut(ptrdiff_t dim,
			 const bool prb_mat[static restrict dim][dim],
			 int64_t sol[static restrict 3][dim],
			 uint256_a mat[static restrict dim][dim][dim],
			 ptrdiff_t tab[static restrict dim],
			 int64_t cmp[static restrict dim][dim][dim],
			 int64_t alt[static restrict dim][dim],
			 int64_t num[static restrict dim][2],
			 ptrdiff_t pos[static restrict dim][2],
			 uint256_a rws[static restrict dim],
			 ptrdiff_t *restrict len,
			 ptrdiff_t lut_sz,
			 uint256_a lut_nrws[static restrict lut_sz],
			 int64_t lut_num[static restrict lut_sz],
			 int64_t lut_lvl[static restrict lut_sz],
			 bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t *restrict lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ],
			 int64_t *restrict count, double *restrict tim);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
[[gnu::always_inline]] [[gnu::nonnull]]
inline
void	mask_256b	(uint256_a mask, uint8_t pos)
{

	memset(mask, 0, ARRAY_BYTES(foovar__256b));

	if (pos < 64)
		mask[0]	= UINT64_C(1) << pos;
	else if (pos < (64 * 2))
		mask[1]	= UINT64_C(1) << (pos - 64);
	else if (pos < (64 * 3))
		mask[2]	= UINT64_C(1) << (pos - 64 * 2);
	else
		mask[3]	= UINT64_C(1) << (pos - 64 * 3);
}

[[gnu::always_inline]] [[gnu::nonnull]]
inline
void	nmask_256b	(uint256_a mask, uint8_t pos)
{

	memset(mask, UCHAR_MAX, ARRAY_BYTES(foovar__256b));

	if (pos < 64)
		mask[0]	= ~(UINT64_C(1) << pos);
	else if (pos < (64 * 2))
		mask[1]	= ~(UINT64_C(1) << (pos - 64));
	else if (pos < (64 * 3))
		mask[2]	= ~(UINT64_C(1) << (pos - 64 * 2));
	else
		mask[3]	= ~(UINT64_C(1) << (pos - 64 * 3));
}

[[gnu::always_inline]] [[gnu::nonnull]]
inline
void	not_256b	(uint256_a dest, const uint256_a x)
{

	#pragma omp simd
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(foovar__256b); i++)
		dest[i] = ~x[i];
}

[[gnu::always_inline]] [[gnu::nonnull]]
inline
void	and_256b	(uint256_a dest, const uint256_a a, const uint256_a b)
{

	#pragma omp simd
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(foovar__256b); i++)
		dest[i] = a[i] & b[i];
}

[[gnu::always_inline]] [[gnu::nonnull]]
inline
void	or_256b		(uint256_a dest, const uint256_a a, const uint256_a b)
{

	#pragma omp simd
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(foovar__256b); i++)
		dest[i] = a[i] | b[i];
}

[[gnu::always_inline]] [[gnu::nonnull]]
inline
void	andassign_256b	(uint256_a x, const uint256_a mask)
{

	#pragma omp simd
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(foovar__256b); i++)
		x[i] &= mask[i];
}

[[gnu::always_inline]] [[gnu::nonnull]]
inline
void	orassign_256b	(uint256_a x, const uint256_a mask)
{

	#pragma omp simd
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(foovar__256b); i++)
		x[i] |= mask[i];
}

[[gnu::always_inline]] [[gnu::nonnull]]
inline
void	reset_256b	(uint256_a x)
{

	#pragma omp simd
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(foovar__256b); i++)
		x[i] = 0;
}

[[gnu::always_inline]] [[gnu::nonnull]] [[gnu::pure]]
inline
int64_t popcnt_256b	(const uint256_a x)
{
	ptrdiff_t	cnt;

	cnt = 0;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(foovar__256b); i++)
		cnt += alx_popcnt_u64(x[i]);
	return	cnt;
}

[[gnu::always_inline]] [[gnu::nonnull]]
inline
bool	bool_256b	(const uint256_a x)
{

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(foovar__256b); i++) {
		if (x[i])
			return	true;
	}
	return	false;
}

[[gnu::always_inline]] [[gnu::nonnull]]
inline
void	assign_256b	(uint256_a dest, const uint256_a src)
{

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(foovar__256b); i++)
		dest[i]	= src[i];
}

[[gnu::always_inline]] [[gnu::nonnull]]
inline
void	shlassign_256b	(uint256_a x, uint8_t shift)
{

	for (ptrdiff_t i = (ARRAY_SSIZE(foovar__256b) - 1); i > 0; i--)
		x[i]	= (x[i] << shift) | (x[i - 1] >> (64 - shift));
	x[0] <<= shift;
}


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

