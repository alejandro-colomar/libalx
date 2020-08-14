/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdio/escape_sequences.h */

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
#define SGR_RESET		"\033[0m"
#define SGR_BOLD		"\033[1m"
#define SGR_FAINT		"\033[2m"
#define SGR_ITALIC		"\033[3m"
#define SGR_UNDERLINE		"\033[4m"
#define SGR_BLINK_SLOW		"\033[5m"
#define SGR_BLINK_FAST		"\033[6m"
#define SGR_REVERSE		"\033[7m"
#define SGR_CONCEAL		"\033[8m"
#define SGR_CROSSED		"\033[9m"
#define SGR_FONT_0		"\033[10m"
#define SGR_FONT_1		"\033[11m"
#define SGR_FONT_2		"\033[12m"
#define SGR_FONT_3		"\033[13m"
#define SGR_FONT_4		"\033[14m"
#define SGR_FONT_5		"\033[15m"
#define SGR_FONT_6		"\033[16m"
#define SGR_FONT_7		"\033[17m"
#define SGR_FONT_8		"\033[18m"
#define SGR_FONT_9		"\033[19m"
#define SGR_FRAKTUR		"\033[20m"
#define SGR_UNDERLINE_DOUBLE	"\033[21m"
#define SGR_COLOR_OFF		"\033[22m"
#define SGR_ITALIC_OFF		"\033[23m"
#define SGR_UNDERLINE_OFF	"\033[24m"
#define SGR_BLINK_OFF		"\033[25m"

#define SGR_REVERSE_OFF		"\033[27m"
#define SGR_CONCEAL_OFF		"\033[28m"
#define SGR_CROSSED_OFF		"\033[29m"
#define SGR_FGND_BLACK		"\033[30m"
#define SGR_FGND_RED		"\033[31m"
#define SGR_FGND_GREEN		"\033[32m"
#define SGR_FGND_YELLOW		"\033[33m"
#define SGR_FGND_BLUE		"\033[34m"
#define SGR_FGND_MAGENTA	"\033[35m"
#define SGR_FGND_CYAN		"\033[36m"
#define SGR_FGND_WHITE		"\033[37m"
//#define SGR_FGND_8_BIT		"\033[38m"
#define SGR_FGND_DEFAULT	"\033[39m"
#define SGR_BKGD_BLACK		"\033[40m"
#define SGR_BKGD_RED		"\033[41m"
#define SGR_BKGD_GREEN		"\033[42m"
#define SGR_BKGD_YELLOW		"\033[43m"
#define SGR_BKGD_BLUE		"\033[44m"
#define SGR_BKGD_MAGENTA	"\033[45m"
#define SGR_BKGD_CYAN		"\033[46m"
#define SGR_BKGD_WHITE		"\033[47m"
//#define SGR_BKGD_8_BIT		"\033[48m"
#define SGR_BKGD_DEFAULT	"\033[49m"

#define SGR_FGND_BRGH_BLACK	"\033[90m"
#define SGR_FGND_BRGH_RED	"\033[91m"
#define SGR_FGND_BRGH_GREEN	"\033[92m"
#define SGR_FGND_BRGH_YELLOW	"\033[93m"
#define SGR_FGND_BRGH_BLUE	"\033[94m"
#define SGR_FGND_BRGH_MAGENTA	"\033[95m"
#define SGR_FGND_BRGH_CYAN	"\033[96m"
#define SGR_FGND_BRGH_WHITE	"\033[97m"

#define SGR_BKGD_BRGH_BLACK	"\033[100m"
#define SGR_BKGD_BRGH_RED	"\033[101m"
#define SGR_BKGD_BRGH_GREEN	"\033[102m"
#define SGR_BKGD_BRGH_YELLOW	"\033[103m"
#define SGR_BKGD_BRGH_BLUE	"\033[104m"
#define SGR_BKGD_BRGH_MAGENTA	"\033[105m"
#define SGR_BKGD_BRGH_CYAN	"\033[106m"
#define SGR_BKGD_BRGH_WHITE	"\033[107m"


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
