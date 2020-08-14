/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/node.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Node
 *
 * A node pointer can be created with `struct Alx_Node *node;`
 * To use the node, it has to be initialized with
 * `alx_node_init(&node, data, size)` or `alx_node_init_empty(&node)`.
 * It can be deinitialized with `alx_node_deinit(node)`.
 *
 * Data is copied into `malloc`ed memory, and `free`d or `realloc`ed
 * automatically by the functions.
 *
 * A node stores a pointer to a dynamic buffer, and pointers to its connecting
 * nodes.
 *
 * If any of the node metadata is manually modified by the user, the node may
 * be corrupted, and the behavior is undefined.  Functions in
 *  <libalx/alx/data-structures/dyn-buffer.h>  may be called with
 * `node->buf` for lower level management.
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>

#include <sys/types.h>

#include "libalx/alx/data-structures/types.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* typedef **************************************************************
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
 * Initializes node.
 * Allocates memory for the node and for the buffer, copies the data passed by
 * the user to the newly allocated space, and updates any necessary metadata.
 * If data is NULL, no buffer is allocated.
 *
 * node:	Pointer to a pointer to a node.  A node will be allocated,
 *		and a pointer to it will be stored in *node.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node or the buffer.
 */
[[gnu::nonnull(1)]] [[gnu::warn_unused_result]]
int	alx_node_init		(struct Alx_Node **restrict node,
				 const void *restrict data, ssize_t size);

/*
 * Initializes empty node.
 * Allocates memory for the node (not for the buffer), and updates any
 * necessary metadata.
 *
 * node:	Pointer to a pointer to a node.  A node will be allocated,
 *		and a pointer to it will be stored in *node.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_node_init_empty	(struct Alx_Node **node);

/*
 * Allocates memory for the node, and clones the ref node into it.
 *
 * clone:	Pointer to a pointer to a node.  A node will be allocated,
 *		and a pointer to it will be stored in *clone.
 * ref:		Pointer to a node to clone from.
 *
 * return:
 *	0:		OK.
 *	ENOANO:		Aborted; ref was NULL.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
[[gnu::nonnull(1)]] [[gnu::warn_unused_result]]
int	alx_node_init_clone	(struct Alx_Node **restrict clone,
				 const struct Alx_Node *restrict ref);

/*
 * Deinitializes node.
 * Deallocates memory from the node and from the data.
 * If node is NULL, no operation is performed.
 *
 * node:	Pointer to a node.  It is invalid after the call.
 */
void	alx_node_deinit		(struct Alx_Node *node);

/*
 * Writes into the buffer.
 * Reallocates memory for the data if necessary, copies the data passed by the
 * user to the reallocated space, and updates any necessary metadata.
 *
 * node:	Pointer to a node.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to reallocate the data.  Previous
 *			data is left untouched.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_node_write		(struct Alx_Node *node,
				 const void *data, ssize_t size);

/*
 * Reads from the buffer.
 *
 * node:	Pointer to a node.
 * data:	Copy the read data here.  Should be at least `size` bytes.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOBUFS:	OK. data was truncated.
 */
[[gnu::nonnull]]
ssize_t	alx_node_read		(void *data, ssize_t size,
				 const struct Alx_Node *node);

/*
 * Get data pointer from the node.
 *
 * data:	Store the data pointer here.
 * node:	Pointer to a node.
 *
 * return:
 *	0:		OK.
 *	ENOANO:	No data pointer in the node.
 */
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_node_get_data	(void **restrict data,
				 struct Alx_Node *node);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
