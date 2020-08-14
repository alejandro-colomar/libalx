/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/types.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <sys/types.h>


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* typedef **************************************************************
 ******************************************************************************/
/*
 * Comparison function.  Return value logic should work as in strcmp().
 */
typedef int	alx_bst_cmp_f	(const void *user_data, const void *ds_data)
[[gnu::nonnull]] [[gnu::warn_unused_result]];


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Alx_DF_Generic_Type {
	ALX_DF_TYPE_NONE,

	ALX_DF_TYPE_S64,
	ALX_DF_TYPE_DBL,
	ALX_DF_TYPE_STR,

	ALX_DF_TYPES
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
/*
 * Dynamic buffer
 *
 * data:	Pointer to the first byte in the buffer.
 * size:	Size of the data buffer (in bytes).
 * written:	Data used (in bytes).
 */
struct	Alx_DynBuf {
	void	*data;
	ssize_t	size;
	ssize_t	written;
};

/*
 * Dynamic array
 *
 * data:	Pointer to the first element in the array.
 * elsize:	Size of each cell (in bytes).
 * nmemb:	Number of cells in the array.
 * written:	Number of used cells in the array.
 */
struct	Alx_DynArr {
	void		*data;
	ssize_t		elsize;
	ptrdiff_t	nmemb;
	ptrdiff_t	written;
};

/*
 * Node
 *
 * buf:		Pointer to a dynamic buffer containing useful data.
 * left:	Pointer to the left node.
 * right:	Pointer to the right node.
 * parent:	Pointer to the parent node (in a tree).
 * count:	Count (for repeated nodes in trees that don't accept duplicates).
 */
struct	Alx_Node {
	struct Alx_DynBuf	*buf;
	struct Alx_Node		*left;
	struct Alx_Node		*right;
	struct Alx_Node		*parent;
	ptrdiff_t		dup;
};

/*
 * Doubly-linked list
 *
 * head:	Pointer to the first node.
 * tail:	Pointer to the last node.
 * nmemb:	Number of nodes in the list.
 */
struct	Alx_LinkedList {
	struct Alx_Node	*head;
	struct Alx_Node	*tail;
	ptrdiff_t	nmemb;
};

/*
 * Binary search tree
 */
struct	Alx_BST {
	struct Alx_Node	*root;
	ptrdiff_t	nmemb;
	alx_bst_cmp_f	*cmp;		/* comparison function pointer */
	bool		dup;		/* Allow for duplicate members? */
};

struct	Alx_DF_Cell {
	union {
		int64_t		i;
		double		f;
		const char	*s;
	};
	int	type;
	int	err;
};

struct	Alx_DF_Row {
	struct Alx_DynArr	*cells; /* array of `struct Alx_DF_Cell_Key` */
	int			err;
};

struct	Alx_DF_Desc_Txt {
	int	uniq;
	int	top;
	int	freq;
};

struct	Alx_DF_Desc_Num {
	double	mean;
	double	std;
	double	min;
	double	q_25;
	double	q_50;
	double	q_75;
	double	max;
};

union	Alx_DF_Desc {
	struct Alx_DF_Desc_Txt	txt;
	struct Alx_DF_Desc_Num	num;
};

struct	Alx_DF_Col {
	int			type;
	struct Alx_DynBuf	*hdr; /* contains a string */
	bool			ltd_values;
	struct Alx_BST		*values; /* nodes contain struct Alx_DynBuf
					  * which contain a string inside */
	union Alx_DF_Desc	desc;
	int			err;
};

struct	Alx_DataFrame {
	ptrdiff_t		*ncols;
	ptrdiff_t		*nrows;
	struct Alx_DynArr	*cols; /* array of `struct Alx_DF_Col` */
	struct Alx_LinkedList	*rows; /* nodes contain `struct Alx_DF_Row` */
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
