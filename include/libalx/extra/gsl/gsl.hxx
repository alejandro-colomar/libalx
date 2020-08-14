/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/gsl.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <libalx/extra/gsl/cblas/lvl1/iXamax.hxx>
#include <libalx/extra/gsl/cblas/lvl1/iXamin.hxx>
#include <libalx/extra/gsl/distance/chebyshev.hxx>
#include <libalx/extra/gsl/distance/euclidean.hxx>
#include <libalx/extra/gsl/distance/manhattan.hxx>
#include <libalx/extra/gsl/distributions/binomial.hxx>
#include <libalx/extra/gsl/distributions/exp.hxx>
#include <libalx/extra/gsl/distributions/gauss.hxx>
#include <libalx/extra/gsl/distributions/geometric.hxx>
#include <libalx/extra/gsl/distributions/poisson.hxx>
#include <libalx/extra/gsl/distributions/uniform.hxx>
#include <libalx/extra/gsl/rstat/median.hxx>
#include <libalx/extra/gsl/statistics/mean.hxx>
#include <libalx/extra/gsl/units/len.hxx>
#include <libalx/extra/gsl/units/temp.hxx>
#include <libalx/extra/gsl/units/weight.hxx>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
