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
#include <libalx/base/stdlib/alloc/callocs.hpp>
#include <libalx/base/stdlib/alloc/frees.hpp>
#include <libalx/base/stdlib/alloc/mallocarray.hpp>
#include <libalx/base/stdlib/alloc/mallocarrays.hpp>
#include <libalx/base/stdlib/alloc/mallocs.hpp>
#include <libalx/base/stdlib/alloc/reallocarrayf.hpp>
#include <libalx/base/stdlib/alloc/reallocarrayfs.hpp>
#include <libalx/base/stdlib/alloc/reallocarrays.hpp>
#include <libalx/base/stdlib/alloc/reallocfs.hpp>
#include <libalx/base/stdlib/alloc/reallocs.hpp>
#include <libalx/base/stdlib/getenv/getenv_f.hpp>
#include <libalx/base/stdlib/getenv/getenv_i.hpp>
#include <libalx/base/stdlib/getenv/getenv_s.hpp>
#include <libalx/base/stdlib/getenv/getenv_u.hpp>
#include <libalx/base/stdlib/strto/strtof_s.hpp>
#include <libalx/base/stdlib/strto/strtoi_s.hpp>
#include <libalx/base/stdlib/strto/strtou_s.hpp>
#include <libalx/base/stdlib/array_split_pos_neg.hpp>
#include <libalx/base/stdlib/avg.hpp>
#include <libalx/base/stdlib/bsearch.hpp>
#include <libalx/base/stdlib/clz.hpp>
#include <libalx/base/stdlib/cmp.hpp>
#include <libalx/base/stdlib/ctz.hpp>
#include <libalx/base/stdlib/lmax.hpp>
#include <libalx/base/stdlib/popcnt.hpp>
#include <libalx/base/stdlib/pow.hpp>
#include <libalx/base/stdlib/search.hpp>
#include <libalx/base/stdlib/seed.hpp>
#include <libalx/base/stdlib/swap.hpp>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
