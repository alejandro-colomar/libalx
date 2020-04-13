/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/assert.h */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "libalx/base/errno/perror.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]]
 * void	alx_assert_msg(bool expr, const char *msg);
 */
#if !defined(NDEBUG)
#define alx_assert_msg(expr, msg)	do				\
{									\
	const bool	e_ = expr;					\
									\
	if (!e_) {							\
		fputs(msg, stderr);					\
		fputc('\n', stderr);					\
		assert(e_);						\
	}								\
} while (0)
#else
#define alx_assert_msg(expr, msg)	do				\
{									\
									\
	if (!(expr))							\
		alx_perrorx("%s", msg);					\
} while (0)
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
 ******* alias ****************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define assert_msg(expr, msg)		alx_assert_msg(expr, msg)
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
