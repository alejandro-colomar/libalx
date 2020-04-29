/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/dyn-buffer.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Dynamic buffer
 *
 * Read  <libalx/alx/data-structures/dyn-buffer.h>  for documentation.
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <sys/types.h>

#include "libalx/base/compiler/restrict.hpp"


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


/******************************************************************************
 ******* C prototypes *********************************************************
 ******************************************************************************/
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_dynbuf_init		(struct Alx_DynBuf **buf);
void	alx_dynbuf_deinit	(struct Alx_DynBuf *buf);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_dynbuf_write	(struct Alx_DynBuf *restrict buf,
				 ssize_t offset,
				 const void *restrict data, ssize_t size);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_dynbuf_insert	(struct Alx_DynBuf *restrict buf,
				 ssize_t offset,
				 const void *restrict data, ssize_t size);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
ssize_t	alx_dynbuf_read		(void *restrict data, ssize_t size,
				 const struct Alx_DynBuf *restrict buf,
				 ssize_t offset);
[[gnu::nonnull]]
void	alx_dynbuf_consume	(struct Alx_DynBuf *buf, ssize_t size);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_dynbuf_resize	(struct Alx_DynBuf *buf, ssize_t size);


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
