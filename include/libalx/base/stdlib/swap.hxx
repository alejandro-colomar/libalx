/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/swap.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/assert/type.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define ALX_SWAP(a_ptr, b_ptr)	do					\
{									\
	auto			a_ptr_ = (a_ptr);			\
	auto			b_ptr_ = (b_ptr);			\
	__typeof__(*a_ptr_)	tmp_;					\
									\
	alx_Static_assert_same_type(a_ptr_, b_ptr_);			\
									\
	tmp_	= *a_ptr_;						\
	*a_ptr_	= *b_ptr_;						\
	*b_ptr_	= tmp_;							\
} while (0)


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
#define SWAP(a_ptr, b_ptr)	ALX_SWAP(a_ptr, b_ptr)
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
