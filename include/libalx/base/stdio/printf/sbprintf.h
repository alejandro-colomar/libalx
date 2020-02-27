/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdio/printf/sbprintf.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/compiler/size.h"
#include "libalx/base/stdio/printf/snprintfs.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull(1, 3)]][[gnu::format(printf, 3, 4)]]
 * [[gnu::warn_unused_result]]
 * int	alx_sbprintf	(char buff[restrict], ptrdiff_t *restrict written,
 *			 const char *restrict fmt, ...);
 */
#define alx_sbprintf(buff, written, fmt, ...)				\
	alx_snprintfs(buff, written, ARRAY_SIZE(buff), fmt, ##__VA_ARGS__)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define sbprintf(buff, written, fmt, ...)				\
	alx_sbprintf(buff, written, fmt, ##__VA_ARGS__)
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


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
