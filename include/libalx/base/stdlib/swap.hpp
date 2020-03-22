/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/swap.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/assert/type.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_SWAP(a_ptr, b_ptr)	do					\
{									\
	auto		a_ptr_ = (a_ptr);				\
	auto		b_ptr_ = (b_ptr);				\
	typeof(*a_ptr_)	tmp_;						\
									\
	alx_Static_assert_same_type(a_ptr_, b_ptr_);			\
									\
	tmp_	= *a_ptr_;						\
	*a_ptr_	= *b_ptr_;						\
	*b_ptr_	= tmp_;							\
} while (0)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define SWAP(a_ptr, b_ptr)	ALX_SWAP(a_ptr, b_ptr)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
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
