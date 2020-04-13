/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdio/printf/snprintfs.h */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdarg.h>
#include <stddef.h>

#include "libalx/base/compiler/attribute.h"


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
__attribute__((nonnull(1, 4), format(printf, 4, 5), warn_unused_result))
int	alx_snprintfs	(char str[restrict /*nmemb*/],
			 ptrdiff_t *restrict written, ptrdiff_t nmemb,
			 const char *restrict format, ...);
__attribute__((nonnull(1, 4), format(printf, 4, 0), warn_unused_result))
int	alx_vsnprintfs	(char str[restrict /*nmemb*/],
			 ptrdiff_t *restrict written, ptrdiff_t nmemb,
			 const char *restrict format, va_list ap);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS(snprintfs,	alx_snprintfs);
ALX_ALIAS(vsnprintfs,	alx_vsnprintfs);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
