/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/signal/sigterm.h */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <signal.h>

#include "libalx/base/compiler/attribute.h"


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
 ******* static variables *****************************************************
 ******************************************************************************/
extern	sig_atomic_t	alx_sigterm;


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
int	alx_sigterm_init(void);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS(sigterm,	alx_sigterm);
ALX_ALIAS(sigterm_init,	alx_sigterm_init);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

