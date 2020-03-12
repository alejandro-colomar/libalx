/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/errno/error.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <stdnoreturn.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/*
 * [[gnu::format(printf, 2, 3)]]
 * noreturn
 * void	alx_errorx(int status, const char *restrict fmt, ...);
 */
#define alx_errorx(status, fmt, ...)	do				\
{									\
	alx__errorx__(status, __FILE__, __LINE__, __func__, errno,	\
						fmt, ##__VA_ARGS__);	\
} while (0)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define errorx(status, fmt, ...)	alx_errorx(status, fmt, ##__VA_ARGS__)
#endif


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull(2, 4), format(printf, 6, 7)))
noreturn
void	alx__errorx__	(int status, const char *restrict file, int line,
			 const char *restrict func, int errno_val,
			 const char *restrict format, ...);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
