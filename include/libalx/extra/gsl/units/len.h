/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/units/len.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define ALX_GSL_UNITS_ft_TO_m_LDBL	(0.3048L)
#define ALX_GSL_UNITS_ft_TO_m		(0.3048)
#define ALX_GSL_UNITS_ft_TO_m_FLT	(0.3048f)


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
long double	alx_gsl_units_m_to_ft_ldbl	(long double m);
__attribute__((const))
inline
double		alx_gsl_units_m_to_ft		(double m);
__attribute__((const))
inline
float		alx_gsl_units_m_to_ft_flt	(float m);

__attribute__((const))
inline
long double	alx_gsl_units_ft_to_m_ldbl	(long double ft);
__attribute__((const))
inline
double		alx_gsl_units_ft_to_m		(double ft);
__attribute__((const))
inline
float		alx_gsl_units_ft_to_m_flt	(float ft);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double	alx_gsl_units_m_to_ft_ldbl	(long double m)
{
	return	m / ALX_GSL_UNITS_ft_TO_m_LDBL;
}

inline
double		alx_gsl_units_m_to_ft		(double m)
{
	return	m / ALX_GSL_UNITS_ft_TO_m;
}

inline
float		alx_gsl_units_m_to_ft_flt	(float m)
{
	return	m / ALX_GSL_UNITS_ft_TO_m_FLT;
}


inline
long double	alx_gsl_units_ft_to_m_ldbl	(long double ft)
{
	return	ft * ALX_GSL_UNITS_ft_TO_m_LDBL;
}

inline
double		alx_gsl_units_ft_to_m		(double ft)
{
	return	ft * ALX_GSL_UNITS_ft_TO_m;
}

inline
float		alx_gsl_units_ft_to_m_flt	(float ft)
{
	return	ft * ALX_GSL_UNITS_ft_TO_m_FLT;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
