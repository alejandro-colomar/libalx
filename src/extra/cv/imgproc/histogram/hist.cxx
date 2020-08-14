/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/histogram/hist.hxx"

#include <cmath>
#include <cstddef>
#include <cstdint>

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
int	alx::CV::histogram1D	(ptrdiff_t *restrict hist/*[static 256]*/,
				 const class cv::Mat *restrict img)
{
	const	int	h_size		= 256;
	const	float	h_range_arr[]	= {0.0, 256.0};
	const	float	*h_range	= {h_range_arr};
	class cv::Mat	h;

	if (img->channels() != 1)
		return	-1;
	cv::calcHist(img, 1, 0, cv::Mat(), h, 1, &h_size, &h_range);
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < h_size; i++)
		hist[i]	= roundf(h.at<float>(i));

	h.release();
	return	0;
}

int	alx_cv_histogram1D	(ptrdiff_t *restrict hist,
				 const void *restrict img)
{
	return	alx::CV::histogram1D(hist, (const class cv::Mat *)img);
}

int	alx::CV::draw_hist1D	(class cv::Mat *restrict hist,
				 const class cv::Mat *restrict img)
{
	const	int	h_size		= 256;
	const	int	h_height	= 100;
	const	float	h_range_arr[]	= {0.0, 256.0};
	const	float	*h_range	= {h_range_arr};
	class cv::Mat	tmp;

	if (img->channels() != 1)
		return	-1;
	*hist	= cv::Mat::zeros(cv::Size(h_size, h_height), CV_8UC3);

	cv::calcHist(img, 1, 0, cv::Mat(), tmp, 1, &h_size, &h_range);
	/* Normalize the result to [0, rows - 1] */
	cv::normalize(tmp, tmp, 0, hist->rows - 1, cv::NORM_MINMAX, -1,
								 cv::Mat());
	/* Draw hist into tmp */
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < h_size; i++) {
		cv::line(*hist, cv::Point(i, hist->rows - 0),
				cv::Point(i, hist->rows - tmp.at<float>(i)),
				cv::Scalar(UINT8_MAX, 0, 0), 1, 8, 0);
	}

	tmp.release();
	return	0;
}

int	alx_cv_draw_hist1D	(void *restrict hist, const void *restrict img)
{
	return	alx::CV::draw_hist1D((class cv::Mat *)hist,
						(const class cv::Mat *)img);
}

int	alx::CV::draw_hist3D	(class cv::Mat *restrict hist,
				 const class cv::Mat *restrict img)
{
	const	int	h_size		= 256;
	const	int	h_height	= 100;
	const	float	h_range_arr[]	= {0.0, 256.0};
	const	float	*h_range	= {h_range_arr};
	class cv::Mat	cmp[3];
	class cv::Mat	tmp0;
	class cv::Mat	tmp1;
	class cv::Mat	tmp2;

	if (img->channels() != 3)
		return	-1;
	*hist	= cv::Mat::zeros(cv::Size(h_size * 3, h_height), CV_8UC3);

	/* Write components into cmp[] */
	cv::split(*img, cmp);
	/* Write components into cmp[] */
	cv::calcHist(&cmp[0], 1, 0, cv::Mat(), tmp0, 1, &h_size, &h_range,
								true, false);
	cv::calcHist(&cmp[1], 1, 0, cv::Mat(), tmp1, 1, &h_size, &h_range,
								true, false);
	cv::calcHist(&cmp[2], 1, 0, cv::Mat(), tmp2, 1, &h_size, &h_range,
								true, false);
	/* Normalize the result to [0, rows - 1] */
	cv::normalize(tmp0, tmp0, 0, hist->rows - 1, cv::NORM_MINMAX, -1,
								cv::Mat());
	cv::normalize(tmp1, tmp1, 0, hist->rows - 1, cv::NORM_MINMAX, -1,
								cv::Mat());
	cv::normalize(tmp2, tmp2, 0, hist->rows - 1, cv::NORM_MINMAX, -1,
								cv::Mat());
	/* Draw hist into hist_img */
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < h_size; i++) {
		cv::line(*hist, cv::Point(3 * i, hist->rows - 0),
				cv::Point(3 * i,
					hist->rows - tmp0.at<float>(i)),
				cv::Scalar(UINT8_MAX, 0, 0), 1, 8, 0);
	}
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < h_size; i++) {
		cv::line(*hist, cv::Point(3 * i + 1, hist->rows - 0),
				cv::Point(3 * i + 1,
					hist->rows - tmp1.at<float>(i)),
				cv::Scalar(0, UINT8_MAX, 0), 1, 8, 0);
	}
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < h_size; i++) {
		cv::line(*hist, cv::Point(3 * i + 2, hist->rows - 0),
				cv::Point(3 * i + 2,
					hist->rows - tmp2.at<float>(i)),
				cv::Scalar(0, 0, UINT8_MAX), 1, 8, 0);
	}

	cmp[0].release();
	cmp[1].release();
	cmp[2].release();
	tmp0.release();
	tmp1.release();
	tmp2.release();
	return	0;
}

int	alx_cv_draw_hist3D	(void *restrict hist, const void *restrict img)
{
	return	alx::CV::draw_hist3D((class cv::Mat *)hist,
						(const class cv::Mat *)img);
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
