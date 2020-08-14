/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/shape/rect.hxx"

#include <cstdint>

#include <vector>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#include "libalx/base/compiler/restrict.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	alx::CV::bounding_rect	(class cv::Rect_ <int> *restrict rect,
				 const class std::vector <
					class cv::Point_ <
					int>>  *restrict contour)
{
	*rect	= cv::boundingRect(*contour);
}

void	alx_cv_bounding_rect	(void *restrict rect,
				 const void *restrict contour)
{
	alx::CV::bounding_rect((class cv::Rect_ <int> *)rect,
					(const class std::vector <
						class cv::Point_ <
						int>>  *)contour);
}

void	alx::CV::fit_ellipse	(class cv::RotatedRect *restrict rect_rot,
				 const class std::vector <
					class cv::Point_ <
					int>>  *restrict contour)
{
	*rect_rot	= cv::fitEllipse(*contour);
}

void	alx_cv_fit_ellipse	(void *restrict rect_rot,
				 const void *restrict contour)
{
	alx::CV::fit_ellipse((class cv::RotatedRect *)rect_rot,
					(const class std::vector <
						class cv::Point_ <
						int>>  *)contour);
}

void	alx::CV::min_area_rect	(class cv::RotatedRect *restrict rect_rot,
				 const class std::vector <
					class cv::Point_ <
					int>>  *restrict contour)
{
	*rect_rot	= cv::minAreaRect(*contour);
}

void	alx_cv_min_area_rect	(void *restrict rect_rot,
				 const void *restrict contour)
{
	alx::CV::min_area_rect((class cv::RotatedRect *)rect_rot,
					(const class std::vector <
						class cv::Point_ <
						int>>  *)contour);
}

void	alx::CV::draw_rect	(class cv::Mat *restrict img,
				 const class cv::Rect_ <int> *restrict rect)
{
	class cv::Point_ <float>	vertices[4];

	vertices[0].x	= rect->x;
	vertices[0].y	= rect->y;
	vertices[1].x	= rect->x + rect->width;
	vertices[1].y	= rect->y;
	vertices[2].x	= rect->x + rect->width;
	vertices[2].y	= rect->y + rect->height;
	vertices[3].x	= rect->x;
	vertices[3].y	= rect->y + rect->height;
	cv::line(*img, cv::Point(vertices[0].x, vertices[0].y),
				cv::Point(vertices[1].x, vertices[1].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[1].x, vertices[1].y),
				cv::Point(vertices[2].x, vertices[2].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[2].x, vertices[2].y),
				cv::Point(vertices[3].x, vertices[3].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[3].x, vertices[3].y),
				cv::Point(vertices[0].x, vertices[0].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
}

void	alx_cv_draw_rect	(void *restrict img,
				 const void *restrict rect)
{
	alx::CV::draw_rect((class cv::Mat *)img,
					(const class cv::Rect_<int> *)rect);
}

void	alx::CV::draw_rect_rot	(class cv::Mat *restrict img,
				 class cv::RotatedRect *restrict rect_rot)
{
	class cv::Point_ <float>	vertices[4];

	rect_rot->points(vertices);
	cv::line(*img, cv::Point(vertices[0].x, vertices[0].y),
				cv::Point(vertices[1].x, vertices[1].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[1].x, vertices[1].y),
				cv::Point(vertices[2].x, vertices[2].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[2].x, vertices[2].y),
				cv::Point(vertices[3].x, vertices[3].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[3].x, vertices[3].y),
				cv::Point(vertices[0].x, vertices[0].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
}

void	alx_cv_draw_rect_rot	(void *restrict img,
				 const void *restrict rect_rot)
{
	alx::CV::draw_rect_rot((class cv::Mat *)img,
					(class cv::RotatedRect *)rect_rot);
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
