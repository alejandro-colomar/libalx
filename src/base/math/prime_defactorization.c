/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/math/prime_defactorization.h"

#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "libalx/base/math/prime.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
long double	alx_ldbl_prime_defactorization_8b(
			const int8_t pf[static restrict PRIME_NUMS_QTY_8b])
{
	long double	n;
	long double	tmp;
	int_fast8_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < PRIME_NUMS_QTY_8b; i++) {
		exp	= abs(pf[i]);
		tmp	= powl(alx_prime_8b[i], exp);
		if (pf[i] > 0)
			n *= tmp;
		else if (pf[i] < 0)
			n /= tmp;
	}

	return	n;
}

long double	alx_ldbl_prime_defactorization_16b(
			const int16_t pf[static restrict PRIME_NUMS_QTY_16b])
{
	long double	n;
	long double	tmp;
	int_fast16_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < PRIME_NUMS_QTY_16b; i++) {
		exp	= abs(pf[i]);
		tmp	= powl(alx_prime_16b[i], exp);
		if (pf[i] > 0)
			n *= tmp;
		else if (pf[i] < 0)
			n /= tmp;
	}

	return	n;
}


double	alx_prime_defactorization_8b(
			const int8_t pf[static restrict PRIME_NUMS_QTY_8b])
{
	double_t	n;
	double_t	tmp;
	int_fast8_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < PRIME_NUMS_QTY_8b; i++) {
		exp	= abs(pf[i]);
		tmp	= pow(alx_prime_8b[i], exp);
		if (pf[i] > 0)
			n *= tmp;
		else if (pf[i] < 0)
			n /= tmp;
	}

	return	n;
}

double	alx_prime_defactorization_16b(
			const int16_t pf[static restrict PRIME_NUMS_QTY_16b])
{
	double_t	n;
	double_t	tmp;
	int_fast16_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < PRIME_NUMS_QTY_16b; i++) {
		exp	= abs(pf[i]);
		tmp	= pow(alx_prime_16b[i], exp);
		if (pf[i] > 0)
			n *= tmp;
		else if (pf[i] < 0)
			n /= tmp;
	}

	return	n;
}


float	alx_flt_prime_defactorization_8b(
			const int8_t pf[static restrict PRIME_NUMS_QTY_8b])
{
	float_t		n;
	float_t		tmp;
	int_fast8_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < PRIME_NUMS_QTY_8b; i++) {
		exp	= abs(pf[i]);
		tmp	= powf(alx_prime_8b[i], exp);
		if (pf[i] > 0)
			n *= tmp;
		else if (pf[i] < 0)
			n /= tmp;
	}

	return	n;
}

float	alx_flt_prime_defactorization_16b(
			const int16_t pf[static restrict PRIME_NUMS_QTY_16b])
{
	float_t		n;
	float_t		tmp;
	int_fast16_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < PRIME_NUMS_QTY_16b; i++) {
		exp	= abs(pf[i]);
		tmp	= powf(alx_prime_16b[i], exp);
		if (pf[i] > 0)
			n *= tmp;
		else if (pf[i] < 0)
			n /= tmp;
	}

	return	n;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
