/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/getenv/getenv_f.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/compiler/attribute.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_getenv_d		(double *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_getenv_f		(float *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_getenv_ld		(long double *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_secure_getenv_d	(double *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_secure_getenv_f	(float *restrict num,
				 const char *restrict name);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_secure_getenv_ld	(long double *restrict num,
				 const char *restrict name);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(getenv_d,		alx_getenv_d);
ALX_ALIAS_DECLARATION(getenv_f,		alx_getenv_f);
ALX_ALIAS_DECLARATION(getenv_ld,	alx_getenv_ld);
ALX_ALIAS_DECLARATION(secure_getenv_d,	alx_secure_getenv_d);
ALX_ALIAS_DECLARATION(secure_getenv_f,	alx_secure_getenv_f);
ALX_ALIAS_DECLARATION(secure_getenv_ld,	alx_secure_getenv_ld);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

