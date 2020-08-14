/******************************************************************************
 *	The code given here is all public domain			      *
 ******************************************************************************/


/******************************************************************************
 * Original file:	gnuplot_i.h					      *
 * Original author:	N. Devillard					      *
 * Date:		Sep 1998					      *
 * Site:		< http://ndevilla.free.fr/gnuplot/ >		      *
 * Brief:		C interface to gnuplot				      *
 *									      *
 * gnuplot  is a freely available, command-driven graphical display tool      *
 * for Unix.  It compiles and works quite well on a number of Unix	      *
 * flavours as well as other operating systems.  The following module	      *
 * enables sending display requests to gnuplot through simple C calls.	      *
 ******************************************************************************
 * Modified by:		pingplug					      *
 * Site:		< https://github.com/pingplug/gnuplot_i >	      *
 ******************************************************************************
 * Modified by:		Alejandro Colomar Andrés			      *
 * Date:		2020						      *
 * Site:		< https://github.com/alejandro-colomar/libalx >	      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/plot/multi.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include "libalx/base/compiler/attribute.h"

#include "libalx/extra/plot/core.h"


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
[[gnu::nonnull(1)]]
int	alx_gnuplot_set_multiplot	(struct Alx_Gnuplot *restrict gnuplot,
					 const char *restrict opt);
[[gnu::nonnull]]
int	alx_gnuplot_unset_multiplot	(struct Alx_Gnuplot *gnuplot);

[[gnu::nonnull(1, 4)]]
int	alx_gnuplot_plot_multi_y	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double y[static restrict n][size],
					 const char *title[static restrict n]);
[[gnu::nonnull(1, 4, 5)]]
int	alx_gnuplot_plot_x_multi_y	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double x[static restrict size],
					 const double y[static restrict n][size],
					 const char *title[static restrict n]);
[[gnu::nonnull(1, 4, 5)]]
int	alx_gnuplot_plot_multi_xy	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double x[static restrict n][size],
					 const double y[static restrict n][size],
					 const char *title[static restrict n]);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(gnuplot_set_multiplot,	alx_gnuplot_set_multiplot);
ALX_ALIAS_DECLARATION(gnuplot_unset_multiplot,	alx_gnuplot_unset_multiplot);
ALX_ALIAS_DECLARATION(gnuplot_plot_multi_y,	alx_gnuplot_plot_multi_y);
ALX_ALIAS_DECLARATION(gnuplot_plot_x_multi_y,	alx_gnuplot_plot_x_multi_y);
ALX_ALIAS_DECLARATION(gnuplot_plot_multi_xy,	alx_gnuplot_plot_multi_xy);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
