/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/llist.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Circular doubly-linked list
 *
 * Read  <libalx/alx/data-structures/llist.h>  for documentation.
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstddef>

#include "libalx/base/compiler/restrict.hxx"
#include "libalx/alx/data-structures/dyn-array.hxx"
#include "libalx/alx/data-structures/node.hxx"


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
struct	Alx_LinkedList {
	struct Alx_Node	*head;
	struct Alx_Node	*tail;
	ptrdiff_t	nmemb;
}

/* Avoid circular dependence */
struct	Alx_Dyn_Array;


/******************************************************************************
 ******* C prototypes *********************************************************
 ******************************************************************************/
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_init			(struct Alx_LinkedList **list);
void	alx_llist_deinit		(struct Alx_LinkedList *list);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_prepend		(struct Alx_LinkedList *list,
					 const void *data, ssize_t size);
[[gnu::nonnull]]
void	alx_llist_prepend_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_append		(struct Alx_LinkedList *list,
					 const void *data, ssize_t size);
[[gnu::nonnull]]
void	alx_llist_append_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_insert_before		(struct Alx_LinkedList *list,
					 const void *data, ssize_t size,
					 struct Alx_Node *ref);
[[gnu::nonnull]]
int	alx_llist_insert_node_before	(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 struct Alx_Node *ref);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_insert_after		(struct Alx_LinkedList *list,
					 const void *data, ssize_t size,
					 struct Alx_Node *ref);
[[gnu::nonnull]]
int	alx_llist_insert_node_after	(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 struct Alx_Node *ref);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_insert_at		(struct Alx_LinkedList *list,
					 const void *data, ssize_t size,
					 ptrdiff_t pos);
[[gnu::nonnull]]
void	alx_llist_insert_node_at	(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 ptrdiff_t pos);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_remove_head		(struct Alx_LinkedList *list,
					 struct Alx_Node **node);
[[gnu::nonnull]]
int	alx_llist_delete_head		(struct Alx_LinkedList *list);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_remove_tail		(struct Alx_LinkedList *list,
					 struct Alx_Node **node);
[[gnu::nonnull]]
int	alx_llist_delete_tail		(struct Alx_LinkedList *list);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_remove_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_delete_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node);
[[gnu::nonnull]]
void	alx_llist_delete_all		(struct Alx_LinkedList *list);
[[gnu::nonnull]][[gnu::pure]][[gnu::warn_unused_result]]
ptrdiff_t alx_llist_find		(const struct Alx_LinkedList *list,
					 const struct Alx_Node *node);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_get_node_at		(const struct Alx_LinkedList *list,
					 struct Alx_Node **node,
					 ptrdiff_t pos);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_get_relative		(const struct Alx_LinkedList *list,
					 struct Alx_Node **node,
					 struct Alx_Node *ref,
					 ptrdiff_t pos);
[[gnu::nonnull]]
void	alx_llist_move_node_to		(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 ptrdiff_t pos);
[[gnu::nonnull]]
void	alx_llist_move_relative		(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 ptrdiff_t pos);
[[gnu::nonnull]]
void	alx_llist_set_head		(struct Alx_LinkedList *list,
					 ptrdiff_t pos);
[[gnu::nonnull]]
void	alx_llist_set_node_as_head	(struct Alx_LinkedList *list,
					 struct Alx_Node *node);
[[gnu::nonnull(1, 2)]]
int	alx_llist_apply			(struct Alx_LinkedList *restrict list,
					 int (*f)(struct Alx_LinkedList *list,
						  struct Alx_Node *node,
						  void *restrict state,
						  ptrdiff_t i),
					 void *restrict state);
[[gnu::nonnull(1, 2)]]
int	alx_llist_apply_bwd		(struct Alx_LinkedList *restrict list,
					 int (*f)(struct Alx_LinkedList *list,
						  struct Alx_Node *node,
						  void *restrict state,
						  ptrdiff_t i),
					 void *restrict state);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_to_dynarr		(struct Alx_LinkedList *restrict list,
					 struct Alx_Dyn_Array *restrict arr);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_to_bst		(struct Alx_LinkedList *restrict list,
					 struct Alx_Node **restrict bst,
					 int (*cmp)(const void *bst_data,
						    const void *node_data));
[[gnu::nonnull]]
void	alx_llist_treesort		(struct Alx_LinkedList *restrict list,
					 int (*cmp)(const void *bst_data,
						    const void *node_data));


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
