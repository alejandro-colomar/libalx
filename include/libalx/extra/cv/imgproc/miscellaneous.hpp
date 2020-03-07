/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc/miscellaneous.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdint>

#include <opencv2/core/base.hpp>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_CV_THR_OTSU	(-1)


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]]
int	alx_cv_adaptive_thr		(void *img,
					 int method, int thr_typ, int ksize);
[[gnu::nonnull]]
int	alx_cv_cvt_color		(void *img, int method);
[[gnu::nonnull]]
void	alx_cv_cvt_res_8b		(void *img);
[[gnu::nonnull]]
int	alx_cv_distance_transform	(void *img);
[[gnu::nonnull]]
int	alx_cv_distance_transform_8b	(void *img);
[[gnu::nonnull]]
int	alx_cv_threshold		(void *img, int thr_typ, int thr_val);
[[gnu::nonnull]]
void	alx_cv_bkgd_mask		(void *img);
[[gnu::nonnull]]
void	alx_cv_bkgd_fill		(void *img);
[[gnu::nonnull]]
void	alx_cv_holes_mask		(void *img);
[[gnu::nonnull]]
void	alx_cv_holes_fill		(void *img);
[[gnu::nonnull]]
int	alx_cv_color_white_mask		(void *img, uint8_t tolerance);
[[gnu::nonnull]]
int	alx_cv_color_black_mask		(void *img, uint8_t tolerance);
[[gnu::nonnull]]
int	alx_cv_color_gray_mask		(void *img, uint8_t tolerance);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::nonnull]]
int	adaptive_thr		(class cv::Mat *img,
				 int method, int thr_typ, int ksize);
[[gnu::nonnull]]
int	cvt_color		(class cv::Mat *img, int method);
[[gnu::nonnull]]
void	cvt_res_8b		(class cv::Mat *img);
[[gnu::nonnull]]
int	distance_transform	(class cv::Mat *img);
[[gnu::nonnull]]
int	distance_transform_8b	(class cv::Mat *img);
[[gnu::nonnull]]
int	threshold		(class cv::Mat *img, int thr_typ, int thr_val);
[[gnu::nonnull]]
void	bkgd_mask		(class cv::Mat *img);
[[gnu::nonnull]]
void	bkgd_fill		(class cv::Mat *img);
[[gnu::nonnull]]
void	holes_mask		(class cv::Mat *img);
[[gnu::nonnull]]
void	holes_fill		(class cv::Mat *img);
[[gnu::nonnull]]
int	color_white_mask	(class cv::Mat *img, uint8_t tolerance);
[[gnu::nonnull]]
int	color_black_mask	(class cv::Mat *img, uint8_t tolerance);
[[gnu::nonnull]]
int	color_gray_mask		(class cv::Mat *img, uint8_t tolerance);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
