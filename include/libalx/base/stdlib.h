/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <libalx/base/stdlib/alloc/callocs.h>
#include <libalx/base/stdlib/alloc/frees.h>
#include <libalx/base/stdlib/alloc/mallocarray.h>
#include <libalx/base/stdlib/alloc/mallocarrays.h>
#include <libalx/base/stdlib/alloc/mallocs.h>
#include <libalx/base/stdlib/alloc/reallocarrayf.h>
#include <libalx/base/stdlib/alloc/reallocarrayfs.h>
#include <libalx/base/stdlib/alloc/reallocarrays.h>
#include <libalx/base/stdlib/alloc/reallocfs.h>
#include <libalx/base/stdlib/alloc/reallocs.h>
#include <libalx/base/stdlib/getenv/getenv_f.h>
#include <libalx/base/stdlib/getenv/getenv_i.h>
#include <libalx/base/stdlib/getenv/getenv_u.h>
#include <libalx/base/stdlib/strto/strtof_s.h>
#include <libalx/base/stdlib/strto/strtoi_s.h>
#include <libalx/base/stdlib/strto/strtou_s.h>
#include <libalx/base/stdlib/array_split_pos_neg.h>
#include <libalx/base/stdlib/avg.h>
#include <libalx/base/stdlib/bsearch.h>
#include <libalx/base/stdlib/clz.h>
#include <libalx/base/stdlib/cmp.h>
#include <libalx/base/stdlib/ctz.h>
#include <libalx/base/stdlib/lmax.h>
#include <libalx/base/stdlib/popcnt.h>
#include <libalx/base/stdlib/pow.h>
#include <libalx/base/stdlib/search.h>
#include <libalx/base/stdlib/seed.h>
#include <libalx/base/stdlib/swap.h>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
