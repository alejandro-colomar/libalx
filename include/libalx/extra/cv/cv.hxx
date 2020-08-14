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
#include <libalx/extra/cv/alx/compare.hpp>
#include <libalx/extra/cv/alx/gray.hpp>
#include <libalx/extra/cv/alx/lines.hpp>
#include <libalx/extra/cv/alx/max.hpp>
#include <libalx/extra/cv/alx/mean.hpp>
#include <libalx/extra/cv/alx/median.hpp>
#include <libalx/extra/cv/alx/skeleton.hpp>
#include <libalx/extra/cv/core/array/bitwise.hpp>
#include <libalx/extra/cv/core/array/component.hpp>
#include <libalx/extra/cv/core/array/minmax.hpp>
#include <libalx/extra/cv/core/array/normalize.hpp>
#include <libalx/extra/cv/core/contours/extract.hpp>
#include <libalx/extra/cv/core/contours/init.hpp>
#include <libalx/extra/cv/core/img/img.hpp>
#include <libalx/extra/cv/core/pixel/pixel.hpp>
#include <libalx/extra/cv/core/rect/rect.hpp>
#include <libalx/extra/cv/core/roi/roi.hpp>
#include <libalx/extra/cv/features2d/orb.hpp>
#include <libalx/extra/cv/highgui/file.hpp>
#include <libalx/extra/cv/highgui/window.hpp>
#include <libalx/extra/cv/imgproc/features/edges.hpp>
#include <libalx/extra/cv/imgproc/features/features.hpp>
#include <libalx/extra/cv/imgproc/filter/border.hpp>
#include <libalx/extra/cv/imgproc/filter/dilate_erode.hpp>
#include <libalx/extra/cv/imgproc/filter/edges.hpp>
#include <libalx/extra/cv/imgproc/filter/smooth.hpp>
#include <libalx/extra/cv/imgproc/geometric/mirror.hpp>
#include <libalx/extra/cv/imgproc/geometric/resize.hpp>
#include <libalx/extra/cv/imgproc/geometric/rotate.hpp>
#include <libalx/extra/cv/imgproc/histogram/hist.hpp>
#include <libalx/extra/cv/imgproc/miscellaneous/color.hpp>
#include <libalx/extra/cv/imgproc/miscellaneous/distance.hpp>
#include <libalx/extra/cv/imgproc/miscellaneous/fill.hpp>
#include <libalx/extra/cv/imgproc/miscellaneous/resolution.hpp>
#include <libalx/extra/cv/imgproc/miscellaneous/threshold.hpp>
#include <libalx/extra/cv/imgproc/shape/contour/contours.hpp>
#include <libalx/extra/cv/imgproc/shape/contour/draw.hpp>
#include <libalx/extra/cv/imgproc/shape/contour/sort.hpp>
#include <libalx/extra/cv/imgproc/shape/rect.hpp>
#include <libalx/extra/cv/videoio/cam.hpp>
#include <libalx/extra/cv/ximgproc/thinning.hpp>


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
