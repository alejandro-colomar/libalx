/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/mallocs.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]]  [[gnu::warn_unused_result]]
 * int	mallocs(void **ptr, size_t size);
 *
 * Read  <libalx/base/stdlib/alloc/mallocs.h>  for documentation.
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <sys/types.h>

#include "libalx/base/compiler/unused.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define alx_mallocs(ptr, size)	__extension__(				\
{									\
	auto	ptr_	= (ptr);					\
	void	*vp_;							\
	int	err_;							\
									\
	vp_	= alx_mallocs__(size, &err_);				\
	*ptr_	= static_cast<__typeof__(*ptr_)>(vp_);			\
	alx_warn_unused_int(err_);					\
}									\
)


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
[[gnu::malloc]] [[gnu::nonnull]] [[gnu::warn_unused_result]]
void	*alx_mallocs__	(ssize_t size, int *error);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define mallocs(ptr, size)	alx_mallocs(ptr, size)
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
