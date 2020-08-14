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
#include <libalx/extra/gsl/cblas/lvl1/iXamax.hpp>
#include <libalx/extra/gsl/cblas/lvl1/iXamin.hpp>
#include <libalx/extra/gsl/distance/chebyshev.hpp>
#include <libalx/extra/gsl/distance/euclidean.hpp>
#include <libalx/extra/gsl/distance/manhattan.hpp>
#include <libalx/extra/gsl/distributions/binomial.hpp>
#include <libalx/extra/gsl/distributions/exp.hpp>
#include <libalx/extra/gsl/distributions/gauss.hpp>
#include <libalx/extra/gsl/distributions/geometric.hpp>
#include <libalx/extra/gsl/distributions/poisson.hpp>
#include <libalx/extra/gsl/distributions/uniform.hpp>
#include <libalx/extra/gsl/rstat/median.hpp>
#include <libalx/extra/gsl/statistics/mean.hpp>
#include <libalx/extra/gsl/units/len.hpp>
#include <libalx/extra/gsl/units/temp.hpp>
#include <libalx/extra/gsl/units/weight.hpp>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
