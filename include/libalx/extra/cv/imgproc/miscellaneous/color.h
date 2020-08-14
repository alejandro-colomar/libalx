/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/miscellaneous/color.h */

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
enum	Alx_Cv_ColorConversionCodes {
	ALX_CV_COLOR_BGR2BGRA     = 0, // add alpha channel to RGB or BGR image
	ALX_CV_COLOR_RGB2RGBA     = ALX_CV_COLOR_BGR2BGRA,

	ALX_CV_COLOR_BGRA2BGR     = 1, // remove alpha channel from RGB or BGR image
	ALX_CV_COLOR_RGBA2RGB     = ALX_CV_COLOR_BGRA2BGR,

	ALX_CV_COLOR_BGR2RGBA     = 2, // convert between RGB and BGR color spaces (with or without alpha channel)
	ALX_CV_COLOR_RGB2BGRA     = ALX_CV_COLOR_BGR2RGBA,

	ALX_CV_COLOR_RGBA2BGR     = 3,
	ALX_CV_COLOR_BGRA2RGB     = ALX_CV_COLOR_RGBA2BGR,

	ALX_CV_COLOR_BGR2RGB      = 4,
	ALX_CV_COLOR_RGB2BGR      = ALX_CV_COLOR_BGR2RGB,

	ALX_CV_COLOR_BGRA2RGBA    = 5,
	ALX_CV_COLOR_RGBA2BGRA    = ALX_CV_COLOR_BGRA2RGBA,

	ALX_CV_COLOR_BGR2GRAY     = 6, // convert between RGB/BGR and grayscale, @ref color_convert_rgb_gray "color conversions"
	ALX_CV_COLOR_RGB2GRAY     = 7,
	ALX_CV_COLOR_GRAY2BGR     = 8,
	ALX_CV_COLOR_GRAY2RGB     = ALX_CV_COLOR_GRAY2BGR,
	ALX_CV_COLOR_GRAY2BGRA    = 9,
	ALX_CV_COLOR_GRAY2RGBA    = ALX_CV_COLOR_GRAY2BGRA,
	ALX_CV_COLOR_BGRA2GRAY    = 10,
	ALX_CV_COLOR_RGBA2GRAY    = 11,

	ALX_CV_COLOR_BGR2BGR565   = 12, // convert between RGB/BGR and BGR565 (16-bit images)
	ALX_CV_COLOR_RGB2BGR565   = 13,
	ALX_CV_COLOR_BGR5652BGR   = 14,
	ALX_CV_COLOR_BGR5652RGB   = 15,
	ALX_CV_COLOR_BGRA2BGR565  = 16,
	ALX_CV_COLOR_RGBA2BGR565  = 17,
	ALX_CV_COLOR_BGR5652BGRA  = 18,
	ALX_CV_COLOR_BGR5652RGBA  = 19,

	ALX_CV_COLOR_GRAY2BGR565  = 20, // convert between grayscale to BGR565 (16-bit images)
	ALX_CV_COLOR_BGR5652GRAY  = 21,

	ALX_CV_COLOR_BGR2BGR555   = 22, // convert between RGB/BGR and BGR555 (16-bit images)
	ALX_CV_COLOR_RGB2BGR555   = 23,
	ALX_CV_COLOR_BGR5552BGR   = 24,
	ALX_CV_COLOR_BGR5552RGB   = 25,
	ALX_CV_COLOR_BGRA2BGR555  = 26,
	ALX_CV_COLOR_RGBA2BGR555  = 27,
	ALX_CV_COLOR_BGR5552BGRA  = 28,
	ALX_CV_COLOR_BGR5552RGBA  = 29,

	ALX_CV_COLOR_GRAY2BGR555  = 30, // convert between grayscale and BGR555 (16-bit images)
	ALX_CV_COLOR_BGR5552GRAY  = 31,

	ALX_CV_COLOR_BGR2XYZ      = 32, // convert RGB/BGR to CIE XYZ, @ref color_convert_rgb_xyz "color conversions"
	ALX_CV_COLOR_RGB2XYZ      = 33,
	ALX_CV_COLOR_XYZ2BGR      = 34,
	ALX_CV_COLOR_XYZ2RGB      = 35,

	ALX_CV_COLOR_BGR2YCrCb    = 36, // convert RGB/BGR to luma-chroma (aka YCC), @ref color_convert_rgb_ycrcb "color conversions"
	ALX_CV_COLOR_RGB2YCrCb    = 37,
	ALX_CV_COLOR_YCrCb2BGR    = 38,
	ALX_CV_COLOR_YCrCb2RGB    = 39,

	ALX_CV_COLOR_BGR2HSV      = 40, // convert RGB/BGR to HSV (hue saturation value), @ref color_convert_rgb_hsv "color conversions"
	ALX_CV_COLOR_RGB2HSV      = 41,

	ALX_CV_COLOR_BGR2Lab      = 44, // convert RGB/BGR to CIE Lab, @ref color_convert_rgb_lab "color conversions"
	ALX_CV_COLOR_RGB2Lab      = 45,

	ALX_CV_COLOR_BGR2Luv      = 50, // convert RGB/BGR to CIE Luv, @ref color_convert_rgb_luv "color conversions"
	ALX_CV_COLOR_RGB2Luv      = 51,
	ALX_CV_COLOR_BGR2HLS      = 52, // convert RGB/BGR to HLS (hue lightness saturation), @ref color_convert_rgb_hls "color conversions"
	ALX_CV_COLOR_RGB2HLS      = 53,

	ALX_CV_COLOR_HSV2BGR      = 54, // backward conversions to RGB/BGR
	ALX_CV_COLOR_HSV2RGB      = 55,

	ALX_CV_COLOR_Lab2BGR      = 56,
	ALX_CV_COLOR_Lab2RGB      = 57,
	ALX_CV_COLOR_Luv2BGR      = 58,
	ALX_CV_COLOR_Luv2RGB      = 59,
	ALX_CV_COLOR_HLS2BGR      = 60,
	ALX_CV_COLOR_HLS2RGB      = 61,

	ALX_CV_COLOR_BGR2HSV_FULL = 66,
	ALX_CV_COLOR_RGB2HSV_FULL = 67,
	ALX_CV_COLOR_BGR2HLS_FULL = 68,
	ALX_CV_COLOR_RGB2HLS_FULL = 69,

	ALX_CV_COLOR_HSV2BGR_FULL = 70,
	ALX_CV_COLOR_HSV2RGB_FULL = 71,
	ALX_CV_COLOR_HLS2BGR_FULL = 72,
	ALX_CV_COLOR_HLS2RGB_FULL = 73,

	ALX_CV_COLOR_LBGR2Lab     = 74,
	ALX_CV_COLOR_LRGB2Lab     = 75,
	ALX_CV_COLOR_LBGR2Luv     = 76,
	ALX_CV_COLOR_LRGB2Luv     = 77,

	ALX_CV_COLOR_Lab2LBGR     = 78,
	ALX_CV_COLOR_Lab2LRGB     = 79,
	ALX_CV_COLOR_Luv2LBGR     = 80,
	ALX_CV_COLOR_Luv2LRGB     = 81,

	ALX_CV_COLOR_BGR2YUV      = 82, // convert between RGB/BGR and YUV
	ALX_CV_COLOR_RGB2YUV      = 83,
	ALX_CV_COLOR_YUV2BGR      = 84,
	ALX_CV_COLOR_YUV2RGB      = 85,

    // YUV 4:2:0 family to RGB
	ALX_CV_COLOR_YUV2RGB_NV12  = 90,
	ALX_CV_COLOR_YUV2BGR_NV12  = 91,
	ALX_CV_COLOR_YUV2RGB_NV21  = 92,
	ALX_CV_COLOR_YUV2BGR_NV21  = 93,
	ALX_CV_COLOR_YUV420sp2RGB  = ALX_CV_COLOR_YUV2RGB_NV21,
	ALX_CV_COLOR_YUV420sp2BGR  = ALX_CV_COLOR_YUV2BGR_NV21,

	ALX_CV_COLOR_YUV2RGBA_NV12 = 94,
	ALX_CV_COLOR_YUV2BGRA_NV12 = 95,
	ALX_CV_COLOR_YUV2RGBA_NV21 = 96,
	ALX_CV_COLOR_YUV2BGRA_NV21 = 97,
	ALX_CV_COLOR_YUV420sp2RGBA = ALX_CV_COLOR_YUV2RGBA_NV21,
	ALX_CV_COLOR_YUV420sp2BGRA = ALX_CV_COLOR_YUV2BGRA_NV21,

	ALX_CV_COLOR_YUV2RGB_YV12  = 98,
	ALX_CV_COLOR_YUV2BGR_YV12  = 99,
	ALX_CV_COLOR_YUV2RGB_IYUV  = 100,
	ALX_CV_COLOR_YUV2BGR_IYUV  = 101,
	ALX_CV_COLOR_YUV2RGB_I420  = ALX_CV_COLOR_YUV2RGB_IYUV,
	ALX_CV_COLOR_YUV2BGR_I420  = ALX_CV_COLOR_YUV2BGR_IYUV,
	ALX_CV_COLOR_YUV420p2RGB   = ALX_CV_COLOR_YUV2RGB_YV12,
	ALX_CV_COLOR_YUV420p2BGR   = ALX_CV_COLOR_YUV2BGR_YV12,

	ALX_CV_COLOR_YUV2RGBA_YV12 = 102,
	ALX_CV_COLOR_YUV2BGRA_YV12 = 103,
	ALX_CV_COLOR_YUV2RGBA_IYUV = 104,
	ALX_CV_COLOR_YUV2BGRA_IYUV = 105,
	ALX_CV_COLOR_YUV2RGBA_I420 = ALX_CV_COLOR_YUV2RGBA_IYUV,
	ALX_CV_COLOR_YUV2BGRA_I420 = ALX_CV_COLOR_YUV2BGRA_IYUV,
	ALX_CV_COLOR_YUV420p2RGBA  = ALX_CV_COLOR_YUV2RGBA_YV12,
	ALX_CV_COLOR_YUV420p2BGRA  = ALX_CV_COLOR_YUV2BGRA_YV12,

	ALX_CV_COLOR_YUV2GRAY_420  = 106,
	ALX_CV_COLOR_YUV2GRAY_NV21 = ALX_CV_COLOR_YUV2GRAY_420,
	ALX_CV_COLOR_YUV2GRAY_NV12 = ALX_CV_COLOR_YUV2GRAY_420,
	ALX_CV_COLOR_YUV2GRAY_YV12 = ALX_CV_COLOR_YUV2GRAY_420,
	ALX_CV_COLOR_YUV2GRAY_IYUV = ALX_CV_COLOR_YUV2GRAY_420,
	ALX_CV_COLOR_YUV2GRAY_I420 = ALX_CV_COLOR_YUV2GRAY_420,
	ALX_CV_COLOR_YUV420sp2GRAY = ALX_CV_COLOR_YUV2GRAY_420,
	ALX_CV_COLOR_YUV420p2GRAY  = ALX_CV_COLOR_YUV2GRAY_420,

    // YUV 4:2:2 family to RGB
	ALX_CV_COLOR_YUV2RGB_UYVY = 107,
	ALX_CV_COLOR_YUV2BGR_UYVY = 108,
    //COLOR_YUV2RGB_VYUY = 109,
    //COLOR_YUV2BGR_VYUY = 110,
	ALX_CV_COLOR_YUV2RGB_Y422 = ALX_CV_COLOR_YUV2RGB_UYVY,
	ALX_CV_COLOR_YUV2BGR_Y422 = ALX_CV_COLOR_YUV2BGR_UYVY,
	ALX_CV_COLOR_YUV2RGB_UYNV = ALX_CV_COLOR_YUV2RGB_UYVY,
	ALX_CV_COLOR_YUV2BGR_UYNV = ALX_CV_COLOR_YUV2BGR_UYVY,

	ALX_CV_COLOR_YUV2RGBA_UYVY = 111,
	ALX_CV_COLOR_YUV2BGRA_UYVY = 112,
    //COLOR_YUV2RGBA_VYUY = 113,
    //COLOR_YUV2BGRA_VYUY = 114,
	ALX_CV_COLOR_YUV2RGBA_Y422 = ALX_CV_COLOR_YUV2RGBA_UYVY,
	ALX_CV_COLOR_YUV2BGRA_Y422 = ALX_CV_COLOR_YUV2BGRA_UYVY,
	ALX_CV_COLOR_YUV2RGBA_UYNV = ALX_CV_COLOR_YUV2RGBA_UYVY,
	ALX_CV_COLOR_YUV2BGRA_UYNV = ALX_CV_COLOR_YUV2BGRA_UYVY,

	ALX_CV_COLOR_YUV2RGB_YUY2 = 115,
	ALX_CV_COLOR_YUV2BGR_YUY2 = 116,
	ALX_CV_COLOR_YUV2RGB_YVYU = 117,
	ALX_CV_COLOR_YUV2BGR_YVYU = 118,
	ALX_CV_COLOR_YUV2RGB_YUYV = ALX_CV_COLOR_YUV2RGB_YUY2,
	ALX_CV_COLOR_YUV2BGR_YUYV = ALX_CV_COLOR_YUV2BGR_YUY2,
	ALX_CV_COLOR_YUV2RGB_YUNV = ALX_CV_COLOR_YUV2RGB_YUY2,
	ALX_CV_COLOR_YUV2BGR_YUNV = ALX_CV_COLOR_YUV2BGR_YUY2,

	ALX_CV_COLOR_YUV2RGBA_YUY2 = 119,
	ALX_CV_COLOR_YUV2BGRA_YUY2 = 120,
	ALX_CV_COLOR_YUV2RGBA_YVYU = 121,
	ALX_CV_COLOR_YUV2BGRA_YVYU = 122,
	ALX_CV_COLOR_YUV2RGBA_YUYV = ALX_CV_COLOR_YUV2RGBA_YUY2,
	ALX_CV_COLOR_YUV2BGRA_YUYV = ALX_CV_COLOR_YUV2BGRA_YUY2,
	ALX_CV_COLOR_YUV2RGBA_YUNV = ALX_CV_COLOR_YUV2RGBA_YUY2,
	ALX_CV_COLOR_YUV2BGRA_YUNV = ALX_CV_COLOR_YUV2BGRA_YUY2,

	ALX_CV_COLOR_YUV2GRAY_UYVY = 123,
	ALX_CV_COLOR_YUV2GRAY_YUY2 = 124,
    //CV_YUV2GRAY_VYUY    = CV_YUV2GRAY_UYVY,
	ALX_CV_COLOR_YUV2GRAY_Y422 = ALX_CV_COLOR_YUV2GRAY_UYVY,
	ALX_CV_COLOR_YUV2GRAY_UYNV = ALX_CV_COLOR_YUV2GRAY_UYVY,
	ALX_CV_COLOR_YUV2GRAY_YVYU = ALX_CV_COLOR_YUV2GRAY_YUY2,
	ALX_CV_COLOR_YUV2GRAY_YUYV = ALX_CV_COLOR_YUV2GRAY_YUY2,
	ALX_CV_COLOR_YUV2GRAY_YUNV = ALX_CV_COLOR_YUV2GRAY_YUY2,

    // alpha premultiplication
	ALX_CV_COLOR_RGBA2mRGBA    = 125,
	ALX_CV_COLOR_mRGBA2RGBA    = 126,

    // RGB to YUV 4:2:0 family
	ALX_CV_COLOR_RGB2YUV_I420  = 127,
	ALX_CV_COLOR_BGR2YUV_I420  = 128,
	ALX_CV_COLOR_RGB2YUV_IYUV  = ALX_CV_COLOR_RGB2YUV_I420,
	ALX_CV_COLOR_BGR2YUV_IYUV  = ALX_CV_COLOR_BGR2YUV_I420,

	ALX_CV_COLOR_RGBA2YUV_I420 = 129,
	ALX_CV_COLOR_BGRA2YUV_I420 = 130,
	ALX_CV_COLOR_RGBA2YUV_IYUV = ALX_CV_COLOR_RGBA2YUV_I420,
	ALX_CV_COLOR_BGRA2YUV_IYUV = ALX_CV_COLOR_BGRA2YUV_I420,
	ALX_CV_COLOR_RGB2YUV_YV12  = 131,
	ALX_CV_COLOR_BGR2YUV_YV12  = 132,
	ALX_CV_COLOR_RGBA2YUV_YV12 = 133,
	ALX_CV_COLOR_BGRA2YUV_YV12 = 134,

    // Demosaicing
	ALX_CV_COLOR_BayerBG2BGR = 46,
	ALX_CV_COLOR_BayerGB2BGR = 47,
	ALX_CV_COLOR_BayerRG2BGR = 48,
	ALX_CV_COLOR_BayerGR2BGR = 49,

	ALX_CV_COLOR_BayerBG2RGB = ALX_CV_COLOR_BayerRG2BGR,
	ALX_CV_COLOR_BayerGB2RGB = ALX_CV_COLOR_BayerGR2BGR,
	ALX_CV_COLOR_BayerRG2RGB = ALX_CV_COLOR_BayerBG2BGR,
	ALX_CV_COLOR_BayerGR2RGB = ALX_CV_COLOR_BayerGB2BGR,

	ALX_CV_COLOR_BayerBG2GRAY = 86,
	ALX_CV_COLOR_BayerGB2GRAY = 87,
	ALX_CV_COLOR_BayerRG2GRAY = 88,
	ALX_CV_COLOR_BayerGR2GRAY = 89,

    // Demosaicing using Variable Number of Gradients
	ALX_CV_COLOR_BayerBG2BGR_VNG = 62,
	ALX_CV_COLOR_BayerGB2BGR_VNG = 63,
	ALX_CV_COLOR_BayerRG2BGR_VNG = 64,
	ALX_CV_COLOR_BayerGR2BGR_VNG = 65,

	ALX_CV_COLOR_BayerBG2RGB_VNG = ALX_CV_COLOR_BayerRG2BGR_VNG,
	ALX_CV_COLOR_BayerGB2RGB_VNG = ALX_CV_COLOR_BayerGR2BGR_VNG,
	ALX_CV_COLOR_BayerRG2RGB_VNG = ALX_CV_COLOR_BayerBG2BGR_VNG,
	ALX_CV_COLOR_BayerGR2RGB_VNG = ALX_CV_COLOR_BayerGB2BGR_VNG,

    // Edge-Aware Demosaicing
	ALX_CV_COLOR_BayerBG2BGR_EA  = 135,
	ALX_CV_COLOR_BayerGB2BGR_EA  = 136,
	ALX_CV_COLOR_BayerRG2BGR_EA  = 137,
	ALX_CV_COLOR_BayerGR2BGR_EA  = 138,

	ALX_CV_COLOR_BayerBG2RGB_EA  = ALX_CV_COLOR_BayerRG2BGR_EA,
	ALX_CV_COLOR_BayerGB2RGB_EA  = ALX_CV_COLOR_BayerGR2BGR_EA,
	ALX_CV_COLOR_BayerRG2RGB_EA  = ALX_CV_COLOR_BayerBG2BGR_EA,
	ALX_CV_COLOR_BayerGR2RGB_EA  = ALX_CV_COLOR_BayerGB2BGR_EA,


	ALX_CV_COLOR_COLORCVT_MAX  = 139
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::nonnull]]
int	alx_cv_cvt_color		(img_s *img, int method);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
