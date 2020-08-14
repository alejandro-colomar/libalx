/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/highgui/window.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/types.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
// ---------  YV ---------
enum	Alx_Cv_Win {
	//These 3 flags are used by cvSet/GetWindowProperty
	ALX_CV_WND_PROP_FULLSCREEN	= 0, //to change/get window's fullscreen property
	ALX_CV_WND_PROP_AUTOSIZE	= 1, //to change/get window's autosize property
	ALX_CV_WND_PROP_ASPECTRATIO	= 2, //to change/get window's aspectratio property
	ALX_CV_WND_PROP_OPENGL		= 3, //to change/get window's opengl support
	ALX_CV_WND_PROP_VISIBLE		= 4,

	//These 2 flags are used by cvNamedWindow and cvSet/GetWindowProperty
	ALX_CV_WINDOW_NORMAL		= 0x00000000, //the user can resize the window (no constraint)  / also use to switch a fullscreen window to a normal size
	ALX_CV_WINDOW_AUTOSIZE		= 0x00000001, //the user cannot resize the window, the size is constrainted by the image displayed
	ALX_CV_WINDOW_OPENGL		= 0x00001000, //window with opengl support

	//Those flags are only for Qt
	ALX_CV_GUI_EXPANDED		= 0x00000000, //status bar and tool bar
	ALX_CV_GUI_NORMAL		= 0x00000010, //old fashious way

	//These 3 flags are used by cvNamedWindow and cvSet/GetWindowProperty
	ALX_CV_WINDOW_FULLSCREEN	= 1,//change the window to fullscreen
	ALX_CV_WINDOW_FREERATIO		= 0x00000100,//the image expends as much as it can (no ratio constraint)
	ALX_CV_WINDOW_KEEPRATIO		= 0x00000000//the ration image is respected.
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::nonnull]]
void	alx_cv_named_window		(const char *restrict win, int flags);
void	alx_cv_destroy_all_windows	(void);
[[gnu::nonnull]]
void	alx_cv_imshow			(const img_s *restrict img,
					 const char *restrict win, int delay);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
