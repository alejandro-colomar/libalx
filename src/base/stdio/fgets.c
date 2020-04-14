/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#define ALX_SRC__
#include "libalx/base/stdio/fgets.h"
#undef ALX_SRC__

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>


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
int	alx_fgets_nonl	(char buf[restrict /*bufsiz*/], int bufsiz,
			 FILE *restrict stream, ptrdiff_t *restrict len)
{
	ptrdiff_t	l;
	int		status;

	status	= 0;
	if (!fgets(buf, bufsiz, stream))
		goto err;

	l	= strnlen(buf, bufsiz);
	if (!l) {
		status	= ECANCELED;
		goto out;
	}
	if (buf[l-1] != '\n') {
		status	= ENOBUFS;
		goto out;
	}
	buf[--l] = '\0';

out:
	if (len)
		*len	= l;

	return	status;
err:
	if (len)
		*len	= 0;
	return	-errno;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_DEFINITION(fgets_nonl, alx_fgets_nonl);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
