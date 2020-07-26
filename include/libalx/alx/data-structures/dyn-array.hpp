/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/dyn-array.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Dynamic array
 *
 * Read  <libalx/alx/data-structures/dyn-array.h>  for documentation.
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstddef>

#include <sys/types.h>

#include "libalx/base/compiler/restrict.hpp"
#include "libalx/alx/data-structures/types.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern "C" {


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
struct	Alx_Dyn_Array {
	unsigned char	*data;
	ssize_t		elsize;
	ptrdiff_t	nmemb;
	ptrdiff_t	written;
};

/* Avoid circular include dependence */
struct	Alx_LinkedList;


/******************************************************************************
 ******* C prototypes *********************************************************
 ******************************************************************************/
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_init		(struct Alx_Dyn_Array **arr, ssize_t elsize);
void	alx_dynarr_deinit	(struct Alx_Dyn_Array *arr);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_write	(struct Alx_Dyn_Array *restrict arr,
				 ptrdiff_t cell, const void *restrict data);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_insert	(struct Alx_Dyn_Array *restrict arr,
				 ptrdiff_t cell, const void *restrict data);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_read		(void *restrict data,
				 const struct Alx_DynArr *restrict arr,
				 ptrdiff_t cell);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_remove	(struct Alx_Dyn_Array *arr,
				 ptrdiff_t cell);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_resize	(struct Alx_Dyn_Array *arr,
				 ptrdiff_t nmemb, ssize_t elsize);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_reset	(struct Alx_Dyn_Array *arr, ssize_t elsize);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_fit		(struct Alx_Dyn_Array *arr);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_to_llist	(struct Alx_Dyn_Array *arr,
				 struct Alx_LinkedList *list);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
}	/* extern "C" */


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
