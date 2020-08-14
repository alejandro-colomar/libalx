/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distributions/binomial.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <math.h>
#include <stdint.h>


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
[[gnu::const]]
inline
long double	alx_gsl_distr_binomial_E_ldbl	(uint64_t n, long double p);
[[gnu::const]]
inline
double		alx_gsl_distr_binomial_E	(uint32_t n, double p);
[[gnu::const]]
inline
float		alx_gsl_distr_binomial_E_flt	(uint16_t n, float p);

[[gnu::const]]
inline
long double	alx_gsl_distr_binomial_Var_ldbl	(uint64_t n, long double p);
[[gnu::const]]
inline
double		alx_gsl_distr_binomial_Var	(uint32_t n, double p);
[[gnu::const]]
inline
float		alx_gsl_distr_binomial_Var_flt	(uint16_t n, float p);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double	alx_gsl_distr_binomial_E_ldbl	(uint64_t n, long double p)
{

	if ((p < 0.0L) || (p > 1.0L)) {
		errno	= EDOM;
		return	nanl("");
	}

	return	n * p;
}

inline
double		alx_gsl_distr_binomial_E	(uint32_t n, double p)
{

	if ((p < 0.0) || (p > 1.0)) {
		errno	= EDOM;
		return	nan("");
	}

	return	n * p;
}

inline
float		alx_gsl_distr_binomial_E_flt	(uint16_t n, float p)
{

	if ((p < 0.0f) || (p > 1.0f)) {
		errno	= EDOM;
		return	nanf("");
	}

	return	n * p;
}


inline
long double	alx_gsl_distr_binomial_Var_ldbl	(uint64_t n, long double p)
{

	if ((p < 0.0L) || (p > 1.0L)) {
		errno	= EDOM;
		return	nanl("");
	}


	return	n * p * (1.0L - p);
}

inline
double		alx_gsl_distr_binomial_Var	(uint32_t n, double p)
{

	if ((p < 0.0) || (p > 1.0)) {
		errno	= EDOM;
		return	nan("");
	}


	return	n * p * (1.0 - p);
}

inline
float		alx_gsl_distr_binomial_Var_flt	(uint16_t n, float p)
{

	if ((p < 0.0f) || (p > 1.0f)) {
		errno	= EDOM;
		return	nanf("");
	}


	return	n * p * (1.0f - p);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
