/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/geometric/rotate.hxx"

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#include "libalx/base/compiler/restrict.hxx"
#include "libalx/base/stdlib/swap.hxx"


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
int	alx::CV::rotate_orto	(class cv::Mat *img, int n)
{

	switch (n) {
	case 1:
		/* Rotate: transpose and flip around horizontal axis: flip_mode=0 */
		cv::transpose(*img, *img);
		cv::flip(*img, *img, 0);
		break;
	case 2:
		/* Rotate: Flip both axises: flip_mode=-1 */
		cv::flip(*img, *img, -1);
		break;
	case 3:
		/* Rotate: transpose and flip around vertical axis: flip_mode=1 */
		cv::transpose(*img, *img);
		cv::flip(*img, *img, 1);
		break;
	default:
		return	1;
	}

	return	0;
}

int	alx_cv_rotate_orto	(void *img, int n)
{
	return	alx::CV::rotate_orto((class cv::Mat *)img, n);
}

int	alx::CV::rotate		(class cv::Mat *img,
				 double x, double y, double angle)
{
	class cv::Point_<float>	center;
	class cv::Mat		map_matrix;

	if (x < 0 || y < 0 || (x >= img->cols) || (y >= img->rows))
		return	1;
	if (angle < -360 || angle > 360)
		return	1;
	center.x	= x;
	center.y	= y;

	map_matrix	= cv::getRotationMatrix2D(center, angle, 1);
	cv::warpAffine(*img, *img, map_matrix, img->size(), cv::INTER_LINEAR,
				cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
	map_matrix.release();

	return	0;
}

int	alx_cv_rotate		(void *img, double x, double y, double angle)
{
	return	alx::CV::rotate((class cv::Mat *)img, x, y, angle);
}

int	alx::CV::rotate_2rect	(class cv::Mat *restrict img,
				 const class cv::RotatedRect *restrict rect_rot,
				 class cv::Rect_<int> *rect)
{
	ptrdiff_t	x, y;
	ptrdiff_t	w, h;
	double		angle;

	x	= rect_rot->center.x;
	y	= rect_rot->center.y;
	angle	= rect_rot->angle;
	/* If angle is < -45º, it is taking into acount the incorrect side */
	if (angle < -45.0)
		angle += 90.0;
	if (angle > 45.0)
		angle -= 90.0;

	if (rect) {
		w	= rect_rot->size.width;
		h	= rect_rot->size.height;
		if ((rect_rot->angle < -45.0)  ||  (rect_rot->angle > 45.0))
			ALX_SWAP(&w, &h);
		rect->x		= x - w / 2;
		rect->y		= y - h / 2;
		rect->width	= w;
		rect->height	= h;
	}

	return	alx::CV::rotate(img, x, y, angle);
}

int	alx_cv_rotate_2rect	(void *restrict img,
				 const void *restrict rect_rot,
				 void *restrict rect)
{
	return	alx::CV::rotate_2rect((class cv::Mat *)img,
				(const class cv::RotatedRect *)rect_rot,
				(class cv::Rect_<int> *)rect);
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
