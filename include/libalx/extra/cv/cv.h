/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/cv.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <libalx/extra/cv/alx/compare.h>
#include <libalx/extra/cv/alx/gray.h>
#include <libalx/extra/cv/alx/lines.h>
#include <libalx/extra/cv/alx/max.h>
#include <libalx/extra/cv/alx/mean.h>
#include <libalx/extra/cv/alx/median.h>
#include <libalx/extra/cv/alx/skeleton.h>
#include <libalx/extra/cv/core/array/bitwise.h>
#include <libalx/extra/cv/core/array/component.h>
#include <libalx/extra/cv/core/array/minmax.h>
#include <libalx/extra/cv/core/array/normalize.h>
#include <libalx/extra/cv/core/contours/extract.h>
#include <libalx/extra/cv/core/contours/init.h>
#include <libalx/extra/cv/core/img/img.h>
#include <libalx/extra/cv/core/pixel/pixel.h>
#include <libalx/extra/cv/core/rect/rect.h>
#include <libalx/extra/cv/core/roi/roi.h>
#include <libalx/extra/cv/features2d/orb.h>
#include <libalx/extra/cv/highgui/file.h>
#include <libalx/extra/cv/highgui/window.h>
#include <libalx/extra/cv/imgproc/features/edges.h>
#include <libalx/extra/cv/imgproc/features/features.h>
#include <libalx/extra/cv/imgproc/filter/border.h>
#include <libalx/extra/cv/imgproc/filter/dilate_erode.h>
#include <libalx/extra/cv/imgproc/filter/edges.h>
#include <libalx/extra/cv/imgproc/filter/smooth.h>
#include <libalx/extra/cv/imgproc/geometric/mirror.h>
#include <libalx/extra/cv/imgproc/geometric/resize.h>
#include <libalx/extra/cv/imgproc/geometric/rotate.h>
#include <libalx/extra/cv/imgproc/histogram/hist.h>
#include <libalx/extra/cv/imgproc/miscellaneous/color.h>
#include <libalx/extra/cv/imgproc/miscellaneous/distance.h>
#include <libalx/extra/cv/imgproc/miscellaneous/fill.h>
#include <libalx/extra/cv/imgproc/miscellaneous/resolution.h>
#include <libalx/extra/cv/imgproc/miscellaneous/threshold.h>
#include <libalx/extra/cv/imgproc/shape/contour/contours.h>
#include <libalx/extra/cv/imgproc/shape/contour/draw.h>
#include <libalx/extra/cv/imgproc/shape/contour/sort.h>
#include <libalx/extra/cv/imgproc/shape/rect.h>
#include <libalx/extra/cv/types.h>
#include <libalx/extra/cv/videoio/cam.h>
#include <libalx/extra/cv/ximgproc/thinning.h>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
