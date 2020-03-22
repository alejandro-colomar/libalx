/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdio/freads.h"

#include <errno.h>
#include <stddef.h>
#include <stdio.h>

#include "libalx/base/assert/stddef.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/
alx_Static_assert_size_ptrdiff();


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
int	alx_freads	(ptrdiff_t bufsiz, char buf[static restrict bufsiz],
			 FILE *restrict stream, ptrdiff_t *restrict len)
{
	ptrdiff_t	bytes;

	if (bufsiz <= 0)
		return	ENOBUFS;

	bytes	= fread(buf, 1, bufsiz - 1, stream);

	if (len)
		*len	= bytes;
	buf[bytes]	= '\0';
	return	ferror(stream);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
