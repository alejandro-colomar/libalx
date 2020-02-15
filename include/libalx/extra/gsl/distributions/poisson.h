/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distributions/poisson.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <math.h>


/******************************************************************************
 ******* macros ***************************************************************
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
__attribute__((const))
inline
long double	alx_gsl_dist_poisson_E_ldbl	(long double l);
__attribute__((const))
inline
double		alx_gsl_dist_poisson_E		(double l);
__attribute__((const))
inline
float		alx_gsl_dist_poisson_E_flt	(float l);

__attribute__((const))
inline
long double	alx_gsl_dist_poisson_Var_ldbl	(long double l);
__attribute__((const))
inline
double		alx_gsl_dist_poisson_Var	(double l);
__attribute__((const))
inline
float		alx_gsl_dist_poisson_Var_flt	(float l);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double	alx_gsl_dist_poisson_E_ldbl	(long double l)
{

	if (l <= 0.0L) {
		errno	= EDOM;
		return	nanl("");
	}

	return	l;
}

inline
double		alx_gsl_dist_poisson_E		(double l)
{

	if (l <= 0.0) {
		errno	= EDOM;
		return	nan("");
	}

	return	l;
}

inline
float		alx_gsl_dist_poisson_E_flt	(float l)
{

	if (l <= 0.0f) {
		errno	= EDOM;
		return	nanf("");
	}

	return	l;
}


inline
long double	alx_gsl_dist_poisson_Var_ldbl	(long double l)
{

	if (l <= 0.0L) {
		errno	= EDOM;
		return	nanl("");
	}

	return	l;
}

inline
double		alx_gsl_dist_poisson_Var	(double l)
{

	if (l <= 0.0) {
		errno	= EDOM;
		return	nan("");
	}

	return	l;
}

inline
float		alx_gsl_dist_poisson_Var_flt	(float l)
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
