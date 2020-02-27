/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdio/printf/snprintfs.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdarg>
#include <cstddef>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define snprintfs(str, written, nmemb, fmt, ...)			\
	alx_snprintfs(str, written, nmemb, fmt, ##__VA_ARGS__)
#define vsnprintfs(str, written, nmemb, fmt, ap)			\
	alx_vsnprintfs(str, written, nmemb, fmt, ap)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull(1, 4)]] [[gnu::format(printf, 4, 5)]] [[gnu::warn_unused_result]]
int	alx_snprintfs	(char *restrict str,
			 ptrdiff_t *restrict written, ptrdiff_t nmemb,
			 const char *restrict format, ...);
[[gnu::nonnull(1, 4)]] [[gnu::format(printf, 4, 0)]] [[gnu::warn_unused_result]]
int	alx_vsnprintfs	(char *restrict str,
			 ptrdiff_t *restrict written, ptrdiff_t nmemb,
			 const char *restrict format, va_list ap);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
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
