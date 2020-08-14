/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distance/euclidean.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <math.h>
#include <stdint.h>

#include "libalx/base/compiler/attribute.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/


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
long double alx_gsl_dist2D_euclidean_ldbl	(long double dx, long double dy);
[[gnu::const]]
inline
double	alx_gsl_dist2D_euclidean		(double dx, double dy);
[[gnu::const]]
inline
float	alx_gsl_dist2D_euclidean_flt		(float dx, float dy);
[[gnu::const]]
inline
float	alx_gsl_dist2D_euclidean_8b		(int8_t dx, int8_t dy);
[[gnu::const]]
inline
float	alx_gsl_dist2D_euclidean_16b		(int16_t dx, int16_t dy);
[[gnu::const]]
inline
double	alx_gsl_dist2D_euclidean_32b		(int32_t dx, int32_t dy);
[[gnu::const]]
inline
long double alx_gsl_dist2D_euclidean_64b	(int64_t dx, int64_t dy);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(gsl_dist2D_euclidean_ldbl,alx_gsl_dist2D_euclidean_ldbl);
ALX_ALIAS_DECLARATION(gsl_dist2D_euclidean,	alx_gsl_dist2D_euclidean);
ALX_ALIAS_DECLARATION(gsl_dist2D_euclidean_flt,	alx_gsl_dist2D_euclidean_flt);
ALX_ALIAS_DECLARATION(gsl_dist2D_euclidean_8b,	alx_gsl_dist2D_euclidean_8b);
ALX_ALIAS_DECLARATION(gsl_dist2D_euclidean_16b,	alx_gsl_dist2D_euclidean_16b);
ALX_ALIAS_DECLARATION(gsl_dist2D_euclidean_32b,	alx_gsl_dist2D_euclidean_32b);
ALX_ALIAS_DECLARATION(gsl_dist2D_euclidean_64b,	alx_gsl_dist2D_euclidean_64b);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double alx_gsl_dist2D_euclidean_ldbl	(long double dx, long double dy)
{
	const long double	dx2	= dx * dx;
	const long double	dy2	= dy * dy;

	return	sqrtl(dx2 + dy2);
}

inline
double	alx_gsl_dist2D_euclidean		(double dx, double dy)
{
	const double_t	dx_	= dx;
	const double_t	dy_	= dy;
	const double_t	dx2	= dx_ * dx_;
	const double_t	dy2	= dy_ * dy_;

	return	sqrt(dx2 + dy2);
}

inline
float	alx_gsl_dist2D_euclidean_flt		(float dx, float dy)
{
	const float_t	dx_	= dx;
	const float_t	dy_	= dy;
	const float_t	dx2	= dx_ * dx_;
	const float_t	dy2	= dy_ * dy_;

	return	sqrtf(dx2 + dy2);
}

inline
float	alx_gsl_dist2D_euclidean_8b		(int8_t dx, int8_t dy)
{
	const float_t	dx_	= dx;
	const float_t	dy_	= dy;
	const float_t	dx2	= dx_ * dx_;
	const float_t	dy2	= dy_ * dy_;

	return	sqrtf(dx2 + dy2);
}

inline
float	alx_gsl_dist2D_euclidean_16b		(int16_t dx, int16_t dy)
{
	const float_t	dx_	= dx;
	const float_t	dy_	= dy;
	const float_t	dx2	= dx_ * dx_;
	const float_t	dy2	= dy_ * dy_;

	return	sqrtf(dx2 + dy2);
}

inline
double	alx_gsl_dist2D_euclidean_32b		(int32_t dx, int32_t dy)
{
	const double_t	dx_	= dx;
	const double_t	dy_	= dy;
	const double_t	dx2	= dx_ * dx_;
	const double_t	dy2	= dy_ * dy_;

	return	sqrt(dx2 + dy2);
}

inline
long double alx_gsl_dist2D_euclidean_64b	(int64_t dx, int64_t dy)
{
	const long double	dx_	= dx;
	const long double	dy_	= dy;
	const long double	dx2	= dx_ * dx_;
	const long double	dy2	= dy_ * dy_;

	return	sqrtl(dx2 + dy2);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
