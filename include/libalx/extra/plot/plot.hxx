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
#pragma once	/* libalx/extra/plot/plot.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstddef>

#include "libalx/base/compiler/attribute.hxx"
#include "libalx/base/compiler/restrict.hxx"

#include "libalx/extra/plot/core.hxx"


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
[[gnu::nonnull]]
void	alx_gnuplot_reset_plot		(struct Alx_Gnuplot *gnuplot);
[[gnu::nonnull(1, 3)]]
int	alx_gnuplot_plot_y		(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t size,
					 const double *restrict y/*[size]*/,
					 const char *restrict title);
[[gnu::nonnull(1, 3, 4)]]
int	alx_gnuplot_plot_xy		(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t size,
					 const double *restrict x/*[size]*/,
					 const double *restrict y/*[size]*/,
					 const char *restrict title);
[[gnu::nonnull(1)]]
int	alx_gnuplot_plot_slope		(struct Alx_Gnuplot *restrict gnuplot,
					 double a, double b,
					 const char *restrict title);
[[gnu::nonnull(1)]]
int	alx_gnuplot_plot_equation	(struct Alx_Gnuplot *restrict gnuplot,
					 const char *equation,
					 const char *title);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(gnuplot_reset_plot,	alx_gnuplot_reset_plot);
ALX_ALIAS_DECLARATION(gnuplot_plot_y,		alx_gnuplot_plot_y);
ALX_ALIAS_DECLARATION(gnuplot_plot_xy,		alx_gnuplot_plot_xy);
ALX_ALIAS_DECLARATION(gnuplot_plot_slope,	alx_gnuplot_plot_slope);
ALX_ALIAS_DECLARATION(gnuplot_plot_equation,	alx_gnuplot_plot_equation);
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
}	/* extern "C" */


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace plot {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace plot */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
