/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/llist.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Circular doubly-linked list
 *
 * A list pointer can be created with `struct Alx_LinkedList *list;`
 * To use the list, it has to be initialized with `alx_llist_init(&list)`.
 * It can be deinitialized with `alx_llist_deinit(list)`.
 *
 * Data is copied into `malloc`ed memory, and `free`d or `realloc`ed
 * automatically by the functions.
 *
 * Each node stores a pointer to a dynamic buffer, and pointers to the two
 * connecting nodes.  More info about the nodes can be found in
 *  <libalx/alx/data-structures/node.h>.
 *
 * If any of the list metadata is manually modified by the user, the list may
 * be corrupted, and the behavior is undefined.
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include <sys/types.h>

#include "libalx/alx/data-structures/dyn-array.h"
#include "libalx/alx/data-structures/types.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/*
 * Initializes list.
 * The alx_llist_init() function allocates a list and assigns a pointer to it
 * to `*list`.  On error, the function assigns NULL, which can later be
 * successfully passed to alx_llist_deinit().
 *
 * list:	Pointer to a pointer to a list.  A list will be allocated,
 *		and a pointer to it will be stored in *list.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the list.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_llist_init			(struct Alx_LinkedList **list);

/*
 * Deinitializes list.
 * The alx_llist_deinit() function frees all the memory space used by the list
 * and all of its remaining nodes.  The list must have been initialized by a
 * previous call to alx_llist_init().  Otherwise, or if alx_llist_deinit(list)
 * has already been called before, undefined behavior occurs.
 * If list is NULL, no operation is performed.
 *
 * list:	Pointer to a list.  It is invalid after the call.
 */
void	alx_llist_deinit		(struct Alx_LinkedList *list);

/*
 * Inserts a new node at the begining of the list.
 * Allocates memory for the node and for the data, copies the data passed by
 * the user to the newly allocated space, and updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
[[gnu::nonnull(1)]] [[gnu::warn_unused_result]]
int	alx_llist_prepend		(struct Alx_LinkedList *list,
					 const void *data, ssize_t size);

/*
 * Inserts an already existing node at the begining of the list.
 * Updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * node:	Pointer to the node to be prepended.
 */
[[gnu::nonnull]]
void	alx_llist_prepend_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node);

/*
 * Inserts a new node at the end of the list.
 * Allocates memory for the node and for the data, copies the data passed by
 * the user to the newly allocated space, and updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
[[gnu::nonnull(1)]] [[gnu::warn_unused_result]]
int	alx_llist_append		(struct Alx_LinkedList *list,
					 const void *data, ssize_t size);

/*
 * Inserts an already existing node at the end of the list.
 * Updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * node:	Pointer to the node to be appended.
 */
[[gnu::nonnull]]
void	alx_llist_append_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node);

/*
 * Inserts a new node just before the `ref` node.
 * Allocates memory for the node and for the data, copies the data passed by
 * the user to the newly allocated space, and updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
[[gnu::nonnull(1, 4)]] [[gnu::warn_unused_result]]
int	alx_llist_insert_before		(struct Alx_LinkedList *list,
					 const void *data, ssize_t size,
					 struct Alx_Node *ref);

/*
 * Inserts an already existing node just before the `ref` node.
 * Updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * node:	Pointer to the node to be inserted.
 */
[[gnu::nonnull]]
void	alx_llist_insert_node_before	(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 struct Alx_Node *ref);

/*
 * Inserts a new node just after the `ref` node.
 * Allocates memory for the node and for the data, copies the data passed by
 * the user to the newly allocated space, and updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
[[gnu::nonnull(1, 4)]] [[gnu::warn_unused_result]]
int	alx_llist_insert_after		(struct Alx_LinkedList *list,
					 const void *data, ssize_t size,
					 struct Alx_Node *ref);

/*
 * Inserts an already existing node just after the `ref` node.
 * Updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * node:	Pointer to the node to be inserted.
 */
[[gnu::nonnull]]
void	alx_llist_insert_node_after	(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 struct Alx_Node *ref);

/*
 * Inserts a new node at the desired position in the list.
 * Allocates memory for the node and for the data, copies the data passed by
 * the user to the newly allocated space, and updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 * pos:		Position where to insert a new node.
 *
 * `pos` can be too large or negative, which results in natural wrapping
 * around the list (a value of -1 would be the tail, and so on).
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
[[gnu::nonnull(1)]] [[gnu::warn_unused_result]]
int	alx_llist_insert_at		(struct Alx_LinkedList *list,
					 const void *data, ssize_t size,
					 ptrdiff_t pos);

/*
 * Inserts an already existing node at the desired position in the list.
 * Updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * node:	Pointer to the node to be inserted.
 * pos:		Position where to insert the node.  It can be too large or
 *		negative, which results in natural wrapping around the list
 *		(a value of -1 would be the tail, and so on).
 */
[[gnu::nonnull]]
void	alx_llist_insert_node_at	(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 ptrdiff_t pos);

/*
 * Removes the first node from the list and updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * node:	Pointer to a pointer to a node.  A pointer to the orphan node
 *		is passed through `node`.
 *
 * return:
 *	0:		OK.
 *	ENOENT:		Aborted; the list is already empty.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_llist_remove_head		(struct Alx_LinkedList *list,
					 struct Alx_Node **node);

/*
 * Deletes the first node from the list.
 * Deallocates memory from the node and from the data, and updates any
 * necessary metadata.
 *
 * list:	Pointer to a list.
 *
 * return:
 *	0:		OK.
 *	ENOENT:		Aborted; the list is already empty.
 */
[[gnu::nonnull]]
int	alx_llist_delete_head		(struct Alx_LinkedList *list);

/*
 * Removes the last node from the list and updates any necessary metadata.
 * A pointer to the orphan node is passed through `node`.
 *
 * list:	Pointer to a list.
 * node:	Pointer to a pointer to a node.  A pointer to the orphan node
 *		is passed through `node`.
 *
 * return:
 *	0:		OK.
 *	ENOENT:		Aborted; the list is already empty.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_llist_remove_tail		(struct Alx_LinkedList *list,
					 struct Alx_Node **node);

/*
 * Deletes the last node from the list.
 * Deallocates memory from the node and from the data, and updates any
 * necessary metadata.
 *
 * list:	Pointer to a list.
 *
 * return:
 *	0:		OK.
 *	ENOENT:		Aborted; the list is already empty.
 */
[[gnu::nonnull]]
int	alx_llist_delete_tail		(struct Alx_LinkedList *list);

/*
 * Removes the `node` from the list.
 * Updates any necessary metadata.
 *
 * NOTE:  If the list has only one node, and this function is called with a
 * pointer to a node which is not the same as the remaining node in the list,
 * no node is removed.
 *
 * list:	Pointer to a list.
 * node:	Pointer to a node.
 *
 * return:
 *	0:		OK.
 *	ENOENT:		Aborted; either the list is already empty, or
 *			it has only one node and is different from `node`.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_llist_remove_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node);

/*
 * Deletes `node` from the list.
 * Deallocates all memory from the node, and updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * node:	Pointer to a node.
 *
 * return:
 *	0:		OK.
 *	ENOENT:		Aborted; the list is already empty.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_llist_delete_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node);

/*
 * Removes all nodes from the list.
 * Deallocates all memory from the nodes, and updates any necessary metadata.
 *
 * list:	Pointer to a list.
 */
[[gnu::nonnull]]
void	alx_llist_delete_all		(struct Alx_LinkedList *list);

/*
 * Finds the `node` in the list.
 *
 * list:	Pointer to a list.
 * node:	Pointer to a node.
 *
 * return:
 *	>= 0:		Found at that position relative to the head.
 *	-ENOENT:	Not found.
 */
[[gnu::nonnull]] [[gnu::pure]] [[gnu::warn_unused_result]]
ptrdiff_t alx_llist_find		(const struct Alx_LinkedList *list,
					 const struct Alx_Node *node);

/*
 * Gets a pointer to the `node` in the position `pos` relative to the head.
 *
 * list:	Pointer to a list.
 * node:	Pointer to a pointer to a node.  A pointer to the found node
 *		is passed through `node`.
 * pos:		Position where to retrieve the node.  It can be too large or
 *		negative, which results in natural wrapping around the list
 *		(a value of -1 would be the tail, and so on).
 *
 * return:
 *	0:		OK.
 *	ENOENT:		List is empty.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_llist_get_node_at		(const struct Alx_LinkedList *list,
					 struct Alx_Node **node,
					 ptrdiff_t pos);

/*
 * Gets a pointer to the `node` in the position `pos` relative to `ref`.
 *
 * list:	Pointer to a list.
 * node:	Pointer to a pointer to a node.  A pointer to the found node
 *		is passed through `node`.
 * node:	Pointer to a node.  This node will be the reference for `pos`.
 * pos:		Position where to retrieve the node.  It can be too large or
 *		negative, which results in natural wrapping around the list
 *		(a value of -1 would be the previous one, and so on).
 *
 * return:
 *	0:		OK.
 *	ENOENT:		List is empty.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_llist_get_relative		(const struct Alx_LinkedList *list,
					 struct Alx_Node **node,
					 struct Alx_Node *ref,
					 ptrdiff_t pos);

/*
 * Moves the `node` in the list to the position `pos` in the list.
 * If `pos` is negative, it wraps around (-1 is the tail, and so on).
 * If the position is too large
 * (pos <= (-list->nmemb + 1)  ||  pos >= (list->nmemb - 1)), it doesn't
 * wrap around.  In that case, if `pos` is negative, the node is moved to the
 * head, and if `pos` is positive, the node is moved to the tail.
 *
 * list:	Pointer to a list.
 * node:	Pointer to the node to be moved.
 * pos:		Position where to put the node.
 */
[[gnu::nonnull]]
void	alx_llist_move_node_to		(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 ptrdiff_t pos);

/*
 * Moves the `node` in the list to the position `pos` relative to the `node`'s
 * position at the moment of the call.
 * If `pos` is negative, it wraps around (-1 is the left node, and so on).  If
 * `pos` is negative and sufficiently large, it wraps around to the tail.
 * If the position is too large
 * (pos <= (-list->nmemb + 1)  ||  pos >= (list->nmemb - 1)), it doesn't
 * wrap around any more.  In those cases, the node isn't moved at all.
 *
 * list:	Pointer to a list.
 * node:	Pointer to the node to be moved.
 * pos:		Position where to put the node.
 */
[[gnu::nonnull]]
void	alx_llist_move_relative		(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 ptrdiff_t pos);

/*
 * Sets the node in the position `pos` as the new head, and updates any
 * necessary metadata.
 *
 * list:	Pointer to a list.
 * pos:		Position.
 */
[[gnu::nonnull]]
void	alx_llist_set_head		(struct Alx_LinkedList *list,
					 ptrdiff_t pos);

/*
 * Sets `node` as the new head, and updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * node:	Pointer to a node.
 */
[[gnu::nonnull]]
void	alx_llist_set_node_as_head	(struct Alx_LinkedList *list,
					 struct Alx_Node *node);

/*
 * Apply function `*f` to each node in the list (starting at the head).
 * The order of the nodes is taken in the following way:
 * Just before applying `*f` to a node, the `right` node is stored in a
 * pointer, so that if `*f` modifies the position of the current node in the
 * list, the function still remembers which one was the `right` node before
 * applying `*f`.
 * The function passes to `*f` the iteration of the loop in which `*f` has
 * been called through `i`.
 * If no `*f` call fails, the loop iterates exactly `list->nmemb` times.
 *
 * list:	Pointer to a list.
 * f:		Pointer to the function to be applied.
 * state:	External data to be used within the function.
 *
 * return:
 *	0:		OK.
 *	else:		If `*f` fails (returns != 0), the loop breaks and
 *			the return value is passed to the caller.
 */
[[gnu::nonnull(1, 2)]]
int	alx_llist_apply			(struct Alx_LinkedList *restrict list,
					 int (*f)(struct Alx_LinkedList *list,
						  struct Alx_Node *node,
						  void *restrict state,
						  ptrdiff_t i),
					 void *restrict state);

/*
 * Apply function `f` to each node in the list (backwards; starting at the
 * tail).
 * The order of the nodes is taken in the following way:
 * Just before applying `*f` to a node, the `left` node is stored in a
 * pointer, so that if `*f` modifies the position of the current node in the
 * list, the function still remembers which one was the `left` node before
 * applying `*f`.
 * The function passes to `*f` the iteration of the loop in which `*f` has
 * been called through `i`.
 * If no `*f` call fails, the loop iterates exactly `list->nmemb` times.
 *
 * list:	Pointer to a list.
 * f:		Pointer to the function to be applied.
 * state:	External data to be used within the function.
 *
 * return:
 *	0:		OK.
 *	else:		If `*f` fails (returns != 0), the loop breaks and
 *			the return value is passed to the caller.
 */
[[gnu::nonnull(1, 2)]]
int	alx_llist_apply_bwd		(struct Alx_LinkedList *restrict list,
					 int (*f)(struct Alx_LinkedList *list,
						  struct Alx_Node *node,
						  void *restrict state,
						  ptrdiff_t i),
					 void *restrict state);

/*
 * Copy the linked list data into an empty dynamic array.  If the array is
 * not empty, all of its previous data is lost.  The array is resized to fit
 * the new data.  The linked list is unchanged.  If an error occurs, the array
 * may be reset.
 *
 * list:	Pointer to a list.
 * arr:		Pointer to an array.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to reallocate the array.
 *	ENOBUFS:	Aborted; nodes have different data sizes.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_llist_to_dynarr		(struct Alx_LinkedList *restrict list,
					 struct Alx_DynArr *restrict arr);

/*
 * Copy the linked list data into a new binary search tree.
 * The linked list is empty afterwards.  If the BST doesn't accept duplicate
 * members, the headmost (leftmost) one is kept, and the rest are safely
 * deinitialized.
 *
 * list:	Pointer to a list.
 * bst:		Pointer to a pointer to a BST (its root node).
 * cmp:		Comparison function pointer.  This function should return
 *			0:	The node data compares equal to the bst node.
 *			< 0:	The node data goes to the left of the bst node.
 *			> 0:	The node data goes to the right of the bst node.
 *
 * return:
 *	0:		OK.
 *	ENOENT:		Aborted; the list is empty.
 */
[[gnu::nonnull]]
void	alx_llist_to_bst		(struct Alx_BST *restrict bst,
					 struct Alx_LinkedList *restrict list);

/*
 * Sort the linked list using a binary search tree (treesort).
 *
 * list:	Pointer to a list.
 * cmp:		Comparison function pointer.  This function should return
 *			0:	The node data compares equal to the bst node.
 *			< 0:	The node data goes to the left of the bst node.
 *			> 0:	The node data goes to the right of the bst node.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_llist_treesort		(struct Alx_LinkedList *restrict list,
					 alx_bst_cmp_f *cmp);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
