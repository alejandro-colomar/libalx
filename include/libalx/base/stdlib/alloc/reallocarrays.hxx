/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/reallocarrays.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]] [[gnu::warn_unused_result]]
 * int	reallocarrays(type **ptr, ssize_t nmemb);
 *
 * Read  <libalx/base/stdlib/alloc/reallocarrays.h>  for documentation.
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstddef>

#include <sys/types.h>

#include "libalx/base/compiler/attribute.hxx"
#include "libalx/base/compiler/restrict.hxx"
#include "libalx/base/compiler/size.hxx"
#include "libalx/base/compiler/unused.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define alx_reallocarrays(ptr, nmemb)	__extension__(			\
{									\
	auto	ptr_	= (ptr);					\
	void	*vp_;							\
	int	err_;							\
									\
	vp_	= alx_reallocarrays__(*ptr_, nmemb, ssizeof(**ptr_), &err_); \
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
[[gnu::nonnull]] [[gnu::warn_unused_result]]
void	*alx_reallocarrays__	(void *restrict ptr, ptrdiff_t nmemb,
				 ssize_t size, int *restrict error);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(reallocarrays__,	alx_reallocarrays__);
#define reallocarrays(ptr, nmemb)	alx_reallocarrays(ptr, nmemb)
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
