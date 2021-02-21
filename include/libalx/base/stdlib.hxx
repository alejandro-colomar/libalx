/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <libalx/base/stdlib/alloc/callocs.hxx>
#include <libalx/base/stdlib/alloc/frees.hxx>
#include <libalx/base/stdlib/alloc/mallocarray.hxx>
#include <libalx/base/stdlib/alloc/mallocarrays.hxx>
#include <libalx/base/stdlib/alloc/mallocs.hxx>
#include <libalx/base/stdlib/alloc/reallocarrayf.hxx>
#include <libalx/base/stdlib/alloc/reallocarrayfs.hxx>
#include <libalx/base/stdlib/alloc/reallocarrays.hxx>
#include <libalx/base/stdlib/alloc/reallocfs.hxx>
#include <libalx/base/stdlib/alloc/reallocs.hxx>
#include <libalx/base/stdlib/getenv/getenv_f.hxx>
#include <libalx/base/stdlib/getenv/getenv_i.hxx>
#include <libalx/base/stdlib/getenv/getenv_u.hxx>
#include <libalx/base/stdlib/strto/strtof_s.hxx>
#include <libalx/base/stdlib/strto/strtoi_s.hxx>
#include <libalx/base/stdlib/strto/strtou_s.hxx>
#include <libalx/base/stdlib/array_split_pos_neg.hxx>
#include <libalx/base/stdlib/avg.hxx>
#include <libalx/base/stdlib/bsearch.hxx>
#include <libalx/base/stdlib/clz.hxx>
#include <libalx/base/stdlib/cmp.hxx>
#include <libalx/base/stdlib/ctz.hxx>
#include <libalx/base/stdlib/lmax.hxx>
#include <libalx/base/stdlib/popcnt.hxx>
#include <libalx/base/stdlib/pow.hxx>
#include <libalx/base/stdlib/search.hxx>
#include <libalx/base/stdlib/swap.hxx>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
