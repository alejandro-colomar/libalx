/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/compiler/unused.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define ALX_UNUSED(e)	do						\
{									\
									\
	if (e) {							\
		;							\
	}								\
} while (0)

#define ALX_RETURN_0(e)	do						\
{									\
									\
	if (e) {							\
		__builtin_unreachable();				\
	}								\
} while (0)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::always_inline]] [[gnu::warn_unused_result]]
inline
int	alx_warn_unused_int(int e);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define UNUSED(e)	ALX_UNUSED(e)
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
int	alx_warn_unused_int(int e)
{
	return	e;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
