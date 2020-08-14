/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/sys.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <libalx/base/sys/socket/tcp/client.h>
#include <libalx/base/sys/socket/tcp/server.h>
#include <libalx/base/sys/socket/msghdr.h>
#include <libalx/base/sys/socket/timestamp.h>
#include <libalx/base/sys/types.h>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
