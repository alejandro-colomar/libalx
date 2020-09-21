/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdio/printf/sbprintf.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/compiler/size.hxx"
#include "libalx/base/stdio/printf/snprintfs.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull(1, 3)]][[gnu::format(printf, 3, 4)]]
 * [[gnu::warn_unused_result]]
 * int	alx_sbprintf	(char buff[restrict], ptrdiff_t *restrict written,
 *			 const char *restrict fmt, ...);
 */
#define alx_sbprintf(buff, written, fmt, ...)				\
	alx_snprintfs((buff), (written), ARRAY_SIZE(buff),		\
					(fmt)  __VA_OPT__(,)  __VA_ARGS__)

/*
 * [[gnu::nonnull(1, 3)]][[gnu::format(printf, 3, 0)]]
 * [[gnu::warn_unused_result]]
 * int	alx_vsbprintf	(char buff[restrict], ptrdiff_t *restrict written,
 *			 const char *restrict fmt, va_list ap);
 */
#define alx_vsbprintf(buff, written, fmt, ap)				\
	alx_vsnprintfs((buff), (written), ARRAY_SIZE(buff), (fmt), (ap))


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


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define sbprintf(buff, written, fmt, ...)				\
	alx_sbprintf((buff), (written), (fmt)  __VA_OPT__(,)  __VA_ARGS__)
#define vsbprintf(buff, written, fmt, ap)				\
	alx_vsbprintf((buff), (written), (fmt), (ap))
#endif


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