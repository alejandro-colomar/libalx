/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/cv.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <libalx/extra/cv/alx/compare.hxx>
#include <libalx/extra/cv/alx/gray.hxx>
#include <libalx/extra/cv/alx/lines.hxx>
#include <libalx/extra/cv/alx/max.hxx>
#include <libalx/extra/cv/alx/mean.hxx>
#include <libalx/extra/cv/alx/median.hxx>
#include <libalx/extra/cv/alx/skeleton.hxx>
#include <libalx/extra/cv/core/array/bitwise.hxx>
#include <libalx/extra/cv/core/array/component.hxx>
#include <libalx/extra/cv/core/array/minmax.hxx>
#include <libalx/extra/cv/core/array/normalize.hxx>
#include <libalx/extra/cv/core/contours/extract.hxx>
#include <libalx/extra/cv/core/contours/init.hxx>
#include <libalx/extra/cv/core/img/img.hxx>
#include <libalx/extra/cv/core/pixel/pixel.hxx>
#include <libalx/extra/cv/core/rect/rect.hxx>
#include <libalx/extra/cv/core/roi/roi.hxx>
#include <libalx/extra/cv/features2d/orb.hxx>
#include <libalx/extra/cv/highgui/file.hxx>
#include <libalx/extra/cv/highgui/window.hxx>
#include <libalx/extra/cv/imgproc/features/edges.hxx>
#include <libalx/extra/cv/imgproc/features/features.hxx>
#include <libalx/extra/cv/imgproc/filter/border.hxx>
#include <libalx/extra/cv/imgproc/filter/dilate_erode.hxx>
#include <libalx/extra/cv/imgproc/filter/edges.hxx>
#include <libalx/extra/cv/imgproc/filter/smooth.hxx>
#include <libalx/extra/cv/imgproc/geometric/mirror.hxx>
#include <libalx/extra/cv/imgproc/geometric/resize.hxx>
#include <libalx/extra/cv/imgproc/geometric/rotate.hxx>
#include <libalx/extra/cv/imgproc/histogram/hist.hxx>
#include <libalx/extra/cv/imgproc/miscellaneous/color.hxx>
#include <libalx/extra/cv/imgproc/miscellaneous/distance.hxx>
#include <libalx/extra/cv/imgproc/miscellaneous/fill.hxx>
#include <libalx/extra/cv/imgproc/miscellaneous/resolution.hxx>
#include <libalx/extra/cv/imgproc/miscellaneous/threshold.hxx>
#include <libalx/extra/cv/imgproc/shape/contour/contours.hxx>
#include <libalx/extra/cv/imgproc/shape/contour/draw.hxx>
#include <libalx/extra/cv/imgproc/shape/contour/sort.hxx>
#include <libalx/extra/cv/imgproc/shape/rect.hxx>
#include <libalx/extra/cv/videoio/cam.hxx>
#include <libalx/extra/cv/ximgproc/thinning.hxx>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
