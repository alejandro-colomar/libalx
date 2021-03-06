/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/must_be.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define alx_must_be(e, ...)	(					\
	0 * (int)sizeof(						\
		struct {						\
			_Static_assert((e)  __VA_OPT__(,)  __VA_ARGS__); \
			char ISO_C_forbids_a_struct_with_no_members__;	\
		}							\
	)								\
)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define must_be(e, ...)		alx_must_be((e)  __VA_OPT__(,)  __VA_ARGS__)
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
