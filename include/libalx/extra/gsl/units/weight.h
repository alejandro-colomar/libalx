/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/units/weight.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define ALX_GSL_UNITS_lb_TO_kg_LDBL	(0.45359237L)
#define ALX_GSL_UNITS_lb_TO_kg		(0.45359237)
#define ALX_GSL_UNITS_lb_TO_kg_FLT	(0.45359237f)


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
long double	alx_gsl_units_kg_to_lb_ldbl	(long double kg);
[[gnu::const]]
inline
double		alx_gsl_units_kg_to_lb		(double kg);
[[gnu::const]]
inline
float		alx_gsl_units_kg_to_lb_flt	(float kg);

[[gnu::const]]
inline
long double	alx_gsl_units_lb_to_kg_ldbl	(long double lb);
[[gnu::const]]
inline
double		alx_gsl_units_lb_to_kg		(double lb);
[[gnu::const]]
inline
float		alx_gsl_units_lb_to_kg_flt	(float lb);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double	alx_gsl_units_kg_to_lb_ldbl	(long double kg)
{
	return	kg / ALX_GSL_UNITS_lb_TO_kg_LDBL;
}

inline
double		alx_gsl_units_kg_to_lb		(double kg)
{
	return	kg / ALX_GSL_UNITS_lb_TO_kg;
}

inline
float		alx_gsl_units_kg_to_lb_flt	(float kg)
{
	return	kg / ALX_GSL_UNITS_lb_TO_kg_FLT;
}


inline
long double	alx_gsl_units_lb_to_kg_ldbl	(long double lb)
{
	return	lb * ALX_GSL_UNITS_lb_TO_kg_LDBL;
}

inline
double		alx_gsl_units_lb_to_kg		(double lb)
{
	return	lb * ALX_GSL_UNITS_lb_TO_kg;
}

inline
float		alx_gsl_units_lb_to_kg_flt	(float lb)
{
	return	lb * ALX_GSL_UNITS_lb_TO_kg_FLT;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
