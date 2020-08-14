/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot/ur/ur.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <libalx/alx/robot/ur/core/core.h>
#include <libalx/alx/robot/ur/core/msg/msg.h>
#include <libalx/alx/robot/ur/core/msg/robot_state.h>
#include <libalx/alx/robot/ur/io/io.h>
#include <libalx/alx/robot/ur/miscellaneous/miscellaneous.h>
#include <libalx/alx/robot/ur/move/move.h>
#include <libalx/alx/robot/ur/pose/pose.h>
#include <libalx/alx/robot/ur/setup/setup.h>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
