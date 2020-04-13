/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/signal/sigpipe.h */


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
extern	sig_atomic_t	alx_sigpipe;


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
int	alx_sigpipe_init(void);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS(sigpipe,	alx_sigpipe);
ALX_ALIAS(sigpipe_init,	alx_sigpipe_init);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

