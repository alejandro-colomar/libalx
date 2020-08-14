/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/videoio/cam.hxx"

#include <memory>

#include <opencv2/core/base.hpp>
#include <opencv2/videoio.hpp>

#include "libalx/base/compiler/restrict.hxx"
#include "libalx/base/stdlib/alloc/mallocarrays.hxx"


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
/* ----- alloc / free */
int	alx::CV::alloc_cam	(class cv::VideoCapture **cam)
{
	return	alx_mallocarrays(cam, 1);
}

int	alx_cv_alloc_cam	(void **cam)
{
	return	alx::CV::alloc_cam((class cv::VideoCapture **)cam);
}

void	alx::CV::free_cam	(class cv::VideoCapture *cam)
{

	cam->release();
	free(cam);
}

void	alx_cv_free_cam		(void *cam)
{
	alx::CV::free_cam((class cv::VideoCapture *)cam);
}

/* ----- init / deinit */
void	alx::CV::init_cam	(class cv::VideoCapture *cam,
				 const char *restrict dev, int index, int api)
{

	if (dev) {
		new (cam)	cv::VideoCapture(dev, api);
	} else {
		new (cam)	cv::VideoCapture(index, api);
	}
}

void	alx_cv_init_cam		(void *restrict cam,
				 const char *restrict dev, int index, int api)
{
	alx::CV::init_cam((class cv::VideoCapture *)cam, dev, index, api);
}

void	alx::CV::deinit_cam	(class cv::VideoCapture *cam)
{
	std::destroy_at(cam);
}

void	alx_cv_deinit_cam	(void *cam)
{
	alx::CV::deinit_cam((class cv::VideoCapture *)cam);
}

/* ----- read */
int	alx::CV::cam_read	(class cv::Mat *restrict img,
				 class cv::VideoCapture *restrict cam)
{
	return	!cam->read(*img);
}

int	alx_cv_cam_read		(void *restrict img,
				 void *restrict cam)
{
	return	alx::CV::cam_read((class cv::Mat *)img,
						(class cv::VideoCapture *)cam);
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
