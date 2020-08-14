/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/sys.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <libalx/base/sys/socket/tcp/client.hxx>
#include <libalx/base/sys/socket/tcp/server.hxx>
#include <libalx/base/sys/socket/msghdr.hxx>
#include <libalx/base/sys/socket/timestamp.hxx>
#include <libalx/base/sys/types.hxx>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
