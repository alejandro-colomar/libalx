/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/gsl.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <libalx/extra/gsl/cblas/lvl1/iXamax.h>
#include <libalx/extra/gsl/cblas/lvl1/iXamin.h>
#include <libalx/extra/gsl/distance/chebyshev.h>
#include <libalx/extra/gsl/distance/euclidean.h>
#include <libalx/extra/gsl/distance/manhattan.h>
#include <libalx/extra/gsl/distributions/binomial.h>
#include <libalx/extra/gsl/distributions/exp.h>
#include <libalx/extra/gsl/distributions/gauss.h>
#include <libalx/extra/gsl/distributions/geometric.h>
#include <libalx/extra/gsl/distributions/poisson.h>
#include <libalx/extra/gsl/distributions/uniform.h>
#include <libalx/extra/gsl/rstat/median.h>
#include <libalx/extra/gsl/statistics/mean.h>
#include <libalx/extra/gsl/units/len.h>
#include <libalx/extra/gsl/units/temp.h>
#include <libalx/extra/gsl/units/weight.h>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
