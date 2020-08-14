/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdio.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <libalx/base/stdio/printf/b.h>
#include <libalx/base/stdio/printf/sbprintf.h>
#include <libalx/base/stdio/printf/snprintfs.h>
#include <libalx/base/stdio/escape_sequences.h>
#include <libalx/base/stdio/fgets.h>
#include <libalx/base/stdio/freads.h>
#include <libalx/base/stdio/get.h>
#include <libalx/base/stdio/seekc.h>
#include <libalx/base/stdio/sscan.h>
#include <libalx/base/stdio/tmpfname.h>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
