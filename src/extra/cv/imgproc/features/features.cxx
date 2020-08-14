/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/features/features.hxx"

//#include <cstddef>
//#include <cstdint>

//#include <vector>

//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>

//#include "libalx/base/compiler/restrict.hxx"


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
/* ----- Feature detection */
#if 0
/* TODO: Tune parameters */
void	img_cv_hough_circles	(class cv::Mat *imgptr, const void *data)
{
	const	struct Img_Iface_Data_Hough_Circles	*data_cast;
	class std::vector <class cv::Vec <float, 3>>	*circles;
	class cv::Point_ <int>	center;
	int			radius;
	double			dist_min;
	double			param_1;
	double			param_2;
	int			radius_min;
	int			radius_max;
	ptrdiff_t		size;

	data_cast	= (const struct Img_Iface_Data_Hough_Circles *)data;
	circles		= data_cast->circles;
	dist_min	= data_cast->dist_min;
	param_1		= data_cast->param_1;
	param_2		= data_cast->param_2;
	radius_min	= data_cast->radius_min;
	radius_max	= data_cast->radius_max;

	/* Get circles */
	cv::HoughCircles(*imgptr, *circles, CV_HOUGH_GRADIENT, 1, dist_min,
				param_1, param_2, radius_min, radius_max);

	/* Set image to black */
	imgptr->setTo(cv::Scalar(0));

	/* Draw circles */
	size	= circles->size();
	for (ptrdiff_t i = 0; i < size; i++) {
		center.x	= cvRound((*circles)[i][0]);
		center.y	= cvRound((*circles)[i][1]);
		radius		= cvRound((*circles)[i][2]);

		/* Draw the circle center */
/*		cv::circle(*imgptr, center, 3, cv::Scalar(0, 255, 0), -1, 8, 0);*/

		/* Draw the circle outline */
		cv::circle(*imgptr, center, radius, cv::Scalar(250), 1, 8, 0);
	}
}
#endif


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
