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
#pragma once	/* libalx/extra/plot/setup.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/compiler/attribute.h"

#include "libalx/extra/plot/core.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Alx_Gnuplot_Styles {
	ALX_GNUPLOT_STYLE_BOXERRORBARS,
	ALX_GNUPLOT_STYLE_BOXES,
	ALX_GNUPLOT_STYLE_DOTS,
	ALX_GNUPLOT_STYLE_ERRORBARS,
	ALX_GNUPLOT_STYLE_IMPULSES,
	ALX_GNUPLOT_STYLE_LINES,
	ALX_GNUPLOT_STYLE_LINESPOINTS,
	ALX_GNUPLOT_STYLE_POINTS,
	ALX_GNUPLOT_STYLE_STEPS
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::nonnull(1)]]
int	alx_gnuplot_set_style	(struct Alx_Gnuplot *restrict gnuplot,
				 int style, const char *restrict opt);
[[gnu::nonnull]]
int	alx_gnuplot_set_xlabel	(struct Alx_Gnuplot *restrict gnuplot,
				 const char *restrict label);
[[gnu::nonnull]]
int	alx_gnuplot_set_ylabel	(struct Alx_Gnuplot *restrict gnuplot,
				 const char *restrict label);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(gnuplot_set_style,	alx_gnuplot_set_style);
ALX_ALIAS_DECLARATION(gnuplot_set_xlabel,	alx_gnuplot_set_xlabel);
ALX_ALIAS_DECLARATION(gnuplot_set_ylabel,	alx_gnuplot_set_ylabel);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
