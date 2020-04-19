/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/bst.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Binary search tree
 *
 * Read  <libalx/alx/data-structures/bst.h>  for documentation.
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>

#include "libalx/base/compiler/restrict.hpp"
#include "libalx/alx/data-structures/llist.hpp"
#include "libalx/alx/data-structures/node.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
/* Avoid circular dependence */
struct	Alx_LinkedList;

extern	"C"
{
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_bst_insert			(struct Alx_Node *bst,
					 const void *data, size_t size,
					 int (*cmp)(const void *bst_data,
						    const void *node_data));
[[gnu::nonnull]]
void	alx_bst_insert_node		(struct Alx_Node *restrict bst,
					 struct Alx_Node *restrict node,
					 int (*cmp)(const void *bst_data,
						    const void *node_data));
[[gnu::nonnull]][[gnu::warn_unused_result]]
struct Alx_Node	*alx_bst_leftmost_node	(struct Alx_Node *restrict bst);
[[gnu::nonnull]][[gnu::warn_unused_result]]
struct Alx_Node	*alx_bst_rightmost_node	(struct Alx_Node *restrict bst);
[[gnu::nonnull]][[gnu::warn_unused_result]]
struct Alx_Node	*alx_bst_parentmost_node(struct Alx_Node *restrict bst);
[[gnu::nonnull]]
struct Alx_Node	*alx_bst_join_L_R	(struct Alx_Node *restrict node);
[[gnu::nonnull]][[gnu::warn_unused_result]]
struct Alx_Node	*alx_bst_remove_node	(struct Alx_Node *restrict node);
void	alx_bst_to_llist		(struct Alx_Node *restrict bst,
					 struct Alx_LinkedList *restrict list);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


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
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
