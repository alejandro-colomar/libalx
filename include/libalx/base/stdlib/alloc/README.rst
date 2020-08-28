
:Author:	Alejandro Colomar Andrés
________________________________________________________________________________


<libalx/base/stdlib/alloc/*>
============================


These functions and macros provide a simpler and safer interface that allows
the user to allocate memory in a single short statement without having to add
checks for all the different possible errors.


::

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	callocs(type **ptr, ptrdiff_t nmemb);

	[[gnu::malloc]] [[gnu::warn_unused_result]]
	void	*mallocarray(ptrdiff_t nmemb, ssize_t size);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	mallocarrays(type **ptr, ptrdiff_t nmemb);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	mallocs(type **ptr, ssize_t size);

	[[gnu::warn_unused_result]]
	void	*reallocarrayf(void *ptr, ptrdiff_t nmemb, ssize_t size);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	reallocarrayfs(type **ptr, ptrdiff_t nmemb);

	[[gnu::nonnull]][[gnu::warn_unused_result]]
	int	reallocarrays(type **ptr, ptrdiff_t nmemb);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	reallocfs(type **ptr, ssize_t size);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	reallocs(type **ptr, ssize_t size);

	[[gnu::nonnull]]
	void	frees(type **ptr);

The functions have a prefix by default: ``alx_``; to use them without the
prefix, ``ALX_NO_PREFIX`` should be defined before including the header:

::

	#define ALX_NO_PREFIX
	#include <libalx/base/stdlib.h>


Functions ending in ``s`` should always be preferred.  These are implemented
as macros.  These macros use ``sizeof()`` internally and safely assign to
the pointer as needed, avoiding unsafe usage of memory allocation functions.
An error code is returned to the user; this error code shall be used.

Reallocation functions ending in ``f`` (or ``fs``) free the memory upon
failure to ease error handling.

Functions containing ``array`` (and ``callocs()``) should be used when
allocating arrays, or single elements (arrays of size 1).  The other funtions
should be used when and only when dealing with buffers of bytes.

``frees()`` stores ``NULL`` in the pointer so that it can be freed more than
once safely.

