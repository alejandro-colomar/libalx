/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/string/strchr/strnrcasechrnul.h"

#include <ctype.h>
#include <stddef.h>
#include <string.h>


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
//#pragma GCC diagnostic push	/* Large arrays unsupported (UB) */
//#pragma GCC diagnostic ignored	"-Wsign-conversion"
//#pragma GCC diagnostic push	/* input is char */
//#pragma GCC diagnostic ignored	"-Wconversion"
ptrdiff_t alx_strnrcasechrnul	(ptrdiff_t size, const char str[restrict size],
				 char c)
{
	const ptrdiff_t	len	= strnlen(str, size);
	const char	c_lower	= tolower((unsigned char)c);
	char		s_lower;

	for (ptrdiff_t i = len - 1; i >= 0; i--) {
		s_lower	= tolower((unsigned char)str[i]);
		if (c_lower == s_lower)
			return	i;
		if (!s_lower)
			return	len;
	}

	return	len;
}
//#pragma GCC diagnostic pop
//#pragma GCC diagnostic pop


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(strnrcasechrnul, alx_strnrcasechrnul);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
