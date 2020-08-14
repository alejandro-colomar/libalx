/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdio/sscan.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>

#include "libalx/base/compiler/restrict.hxx"


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
[[gnu::nonnull]]
int	alx_sscan_ldbl	(long double *restrict dest,
			long double m, long double def, long double M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_dbl	(double *restrict dest,
			double m, double def, double M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_flt	(float *restrict dest,
			float m, float def, float M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_uint	(unsigned *restrict dest,
			unsigned m, unsigned def, unsigned M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_int	(int *restrict dest,
			int m, int def, int M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_u8	(uint8_t *restrict dest,
			uint8_t m, uint8_t def, uint8_t M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_s8	(int8_t *restrict dest,
			int8_t m, int8_t def, int8_t M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_u16	(uint16_t *restrict dest,
			uint16_t m, uint16_t def, uint16_t M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_s16	(int16_t *restrict dest,
			int16_t m, int16_t def, int16_t M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_u32	(uint32_t *restrict dest,
			uint32_t m, uint32_t def, uint32_t M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_s32	(int32_t *restrict dest,
			int32_t m, int32_t def, int32_t M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_u64	(uint64_t *restrict dest,
			uint64_t m, uint64_t def, uint64_t M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_s64	(int64_t *restrict dest,
			int64_t m, int64_t def, int64_t M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_pdif	(ptrdiff_t *restrict dest,
			ptrdiff_t m, ptrdiff_t def, ptrdiff_t M,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_ch	(char *restrict dest,
			const char *restrict valid,
			bool skip_space, bool ignore_case,
			const char *restrict str);
[[gnu::nonnull]]
int	alx_sscan_fname	(const char *restrict path,
			char fname[FILENAME_MAX],
			bool exist,
			const char *restrict str);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


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
