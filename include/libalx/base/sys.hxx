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
#include <libalx/base/sys/socket/tcp/client.hpp>
#include <libalx/base/sys/socket/tcp/server.hpp>
#include <libalx/base/sys/socket/msghdr.hpp>
#include <libalx/base/sys/socket/timestamp.hpp>
#include <libalx/base/sys/types.hpp>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
