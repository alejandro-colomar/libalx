/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distributions/poisson.h */

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
long double	alx_gsl_distr_poisson_E_ldbl	(long double l);
[[gnu::const]]
inline
double		alx_gsl_distr_poisson_E		(double l);
[[gnu::const]]
inline
float		alx_gsl_distr_poisson_E_flt	(float l);

[[gnu::const]]
inline
long double	alx_gsl_distr_poisson_Var_ldbl	(long double l);
[[gnu::const]]
inline
double		alx_gsl_distr_poisson_Var	(double l);
[[gnu::const]]
inline
float		alx_gsl_distr_poisson_Var_flt	(float l);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double	alx_gsl_distr_poisson_E_ldbl	(long double l)
{

	if (l <= 0.0L) {
		errno	= EDOM;
		return	nanl("");
	}

	return	l;
}

inline
double		alx_gsl_distr_poisson_E		(double l)
{

	if (l <= 0.0) {
		errno	= EDOM;
		return	nan("");
	}

	return	l;
}

inline
float		alx_gsl_distr_poisson_E_flt	(float l)
{

	if (l <= 0.0f) {
		errno	= EDOM;
		return	nanf("");
	}

	return	l;
}


inline
long double	alx_gsl_distr_poisson_Var_ldbl	(long double l)
{

	if (l <= 0.0L) {
		errno	= EDOM;
		return	nanl("");
	}

	return	l;
}

inline
double		alx_gsl_distr_poisson_Var	(double l)
{

	if (l <= 0.0) {
		errno	= EDOM;
		return	nan("");
	}

	return	l;
}

inline
float		alx_gsl_distr_poisson_Var_flt	(float l)
{

	if (l <= 0.0f) {
		errno	= EDOM;
		return	nanf("");
	}

	return	l;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
