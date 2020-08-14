/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdio.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <libalx/base/stdio/printf/b.hpp>
#include <libalx/base/stdio/printf/sbprintf.hpp>
#include <libalx/base/stdio/printf/snprintfs.hpp>
#include <libalx/base/stdio/escape_sequences.hpp>
#include <libalx/base/stdio/fgets.hpp>
#include <libalx/base/stdio/freads.hpp>
#include <libalx/base/stdio/get.hpp>
#include <libalx/base/stdio/seekc.hpp>
#include <libalx/base/stdio/sscan.hpp>
#include <libalx/base/stdio/tmpfname.hpp>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
