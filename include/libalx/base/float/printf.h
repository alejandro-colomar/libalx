/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/float/printf.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <float.h>


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#if	(FLT_EVAL_METHOD == 0)
#define PRIaFLTT	"a"
#define PRIAFLTT	"A"
#define PRIeFLTT	"e"
#define PRIEFLTT	"E"
#define PRIfFLTT	"f"
#define PRIFFLTT	"F"
#define PRIgFLTT	"g"
#define PRIGFLTT	"G"

#define PRIaDBLT	"la"
#define PRIADBLT	"lA"
#define PRIeDBLT	"le"
#define PRIEDBLT	"lE"
#define PRIfDBLT	"lf"
#define PRIFDBLT	"lF"
#define PRIgDBLT	"lg"
#define PRIGDBLT	"lG"

#elif	(FLT_EVAL_METHOD == 1)
#define PRIaFLTT	"la"
#define PRIAFLTT	"lA"
#define PRIeFLTT	"le"
#define PRIEFLTT	"lE"
#define PRIfFLTT	"lf"
#define PRIFFLTT	"lF"
#define PRIgFLTT	"lg"
#define PRIGFLTT	"lG"

#define PRIaDBLT	"la"
#define PRIADBLT	"lA"
#define PRIeDBLT	"le"
#define PRIEDBLT	"lE"
#define PRIfDBLT	"lf"
#define PRIFDBLT	"lF"
#define PRIgDBLT	"lg"
#define PRIGDBLT	"lG"

#elif	(FLT_EVAL_METHOD == 2)
#define PRIaFLTT	"La"
#define PRIAFLTT	"LA"
#define PRIeFLTT	"Le"
#define PRIEFLTT	"LE"
#define PRIfFLTT	"Lf"
#define PRIFFLTT	"LF"
#define PRIgFLTT	"Lg"
#define PRIGFLTT	"LG"

#define PRIaDBLT	"La"
#define PRIADBLT	"LA"
#define PRIeDBLT	"Le"
#define PRIEDBLT	"LE"
#define PRIfDBLT	"Lf"
#define PRIFDBLT	"LF"
#define PRIgDBLT	"Lg"
#define PRIGDBLT	"LG"
#endif


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


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
