/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/getenv/getenv_f.h"

#include <stdlib.h>

#include <libalx/base/stdlib/strto/strtof_s.h>


/******************************************************************************
 ******* macros ***************************************************************
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
int	alx_getenv_d		(double *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtod_s(num, env, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_d	(double *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtod_s(num, env, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/