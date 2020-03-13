/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/errno/perror.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cerrno>
#include <cstdarg>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/*
 * [[gnu::format(printf, 1, 2)]]
 * void	alx_perrorx(const char *restrict fmt, ...);
 */
#define alx_perrorx(fmt, ...)		do				\
{									\
	alx__perrorx__(__FILE__, __LINE__, __func__, errno,		\
					fmt, ##__VA_ARGS__);		\
} while (0)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define perrorx(fmt, ...)	alx_perrorx(fmt, ##__VA_ARGS__)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull(1, 3)]] [[gnu::format(printf, 5, 6)]]
void	alx__perrorx__	(const char *restrict file, int line,
			 const char *restrict func, int errno_val,
			 const char *restrict format, ...);
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