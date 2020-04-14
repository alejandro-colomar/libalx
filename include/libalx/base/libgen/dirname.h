/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/libgen/dirname.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdio.h>

#include "libalx/base/compiler/attribute.h"


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
__attribute__((nonnull, warn_unused_result))
int	alx_dirname_s	(char dest[static restrict FILENAME_MAX],
			 const char *restrict path);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
# if !defined(ALX_SRC__)
ALX_ALIAS_DECLARATION(dirname_s, alx_dirname_s);
# endif
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
