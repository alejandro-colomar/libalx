/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc/shape/contour/contours.hxx"

#include <cmath>
#include <cstdint>

#include <vector>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#include "libalx/base/compiler/restrict.hxx"
#include "libalx/extra/gsl/distance/euclidean.hxx"


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
int	alx::CV::contours	(const class cv::Mat *restrict img,
				 class std::vector<
					class std::vector<
					class cv::Point_<
					int>>>  *restrict conts)
{
	class cv::Mat	tmp;
	class cv::Mat	hierarchy;

	if (img->channels() != 1)
		return	-1;
	img->copyTo(tmp);
	cv::findContours(tmp, *conts, hierarchy, cv::RETR_EXTERNAL,
						cv::CHAIN_APPROX_SIMPLE);

	hierarchy.release();
	tmp.release();
	return	0;
}

int	alx_cv_contours		(const void *restrict img, void *restrict conts)
{
	return	alx::CV::contours((const class cv::Mat *)img,
				  (class std::vector<
					class std::vector<
					class cv::Point_<int>>>  *)conts);
}

void	alx::CV::contour_dimensions(const class std::vector <
					class cv::Point_ <
					int>>  *restrict contour,
				 double *restrict area,
				 double *restrict perimeter,
				 ptrdiff_t *restrict ctr_x,
				 ptrdiff_t *restrict ctr_y)
{
	class cv::Moments	mom;

	if (area)
		*area		= cv::contourArea(*contour, false);
	if (perimeter)
		*perimeter	= cv::arcLength(*contour, true);
	if (ctr_x || ctr_y) {
		mom	= cv::moments(*contour);
		if (ctr_x)
			*ctr_x	= roundf(mom.m10 / mom.m00);
		if (ctr_y)
			*ctr_y	= roundf(mom.m01 / mom.m00);
	}
}

void	alx_cv_contour_dimensions(const void *restrict contour,
				 double *restrict area,
				 double *restrict perimeter,
				 ptrdiff_t *restrict ctr_x,
				 ptrdiff_t *restrict ctr_y)
{
	alx::CV::contour_dimensions((const class std::vector <
						class cv::Point_ <
						int>>  *)contour,
					area, perimeter, ctr_x, ctr_y);
}

int	alx::CV::conts_largest_a(const class std::vector<
					class cv::Point_<int>> **restrict cont,
				 ptrdiff_t *restrict i,
				 const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts)
{
	double		area, a;
	ptrdiff_t	n;

	area	= -1;
	n	= conts->size();
	if (!n)
		return	-1;

	for (ptrdiff_t j = 0; j < n; j++) {
		a	= cv::contourArea((*conts)[j]);
		if (a > area) {
			area	= a;
			if (cont)
				*cont	= &(*conts)[j];
			if (i)
				*i	= j;
		}
	}

	return	0;
}

int	alx_cv_conts_largest_a	(const void **restrict cont,
				 ptrdiff_t *restrict i,
				 const void *restrict conts)
{
	return	alx::CV::conts_largest_a((const class std::vector<
						class cv::Point_<int>> **)cont,
					i,
					(const class std::vector<
						class std::vector<
						class cv::Point_<
						int>>> *)conts);
}

int	alx::CV::conts_largest_p(const class std::vector<
					class cv::Point_<int>> **restrict cont,
				 ptrdiff_t *restrict i,
				 const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts)
{
	double		perimeter, p;
	ptrdiff_t	n;

	perimeter	= -1;
	n		= conts->size();
	if (!n)
		return	-1;

	for (ptrdiff_t j = 0; j < n; j++) {
		p	= cv::arcLength((*conts)[j], true);
		if (p > perimeter) {
			perimeter	= p;
			if (cont)
				*cont	= &(*conts)[j];
			if (i)
				*i	= j;
		}
	}

	return	0;
}

int	alx_cv_conts_largest_p	(const void **restrict cont,
				 ptrdiff_t *restrict i,
				 const void *restrict conts)
{
	return	alx::CV::conts_largest_p((const class std::vector<
						class cv::Point_<int>> **)cont,
					i,
					(const class std::vector<
						class std::vector<
						class cv::Point_<
						int>>> *)conts);
}

int	alx::CV::conts_closest	(const class std::vector<
					class cv::Point_<int>> **restrict cont,
				 ptrdiff_t *restrict i,
				 const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts,
				 ptrdiff_t x, ptrdiff_t y,
				 double (*fdist)(int32_t dx, int32_t dy))
{
	ptrdiff_t	ctr_x, ctr_y;
	int32_t		dx, dy;
	double		dist, d;
	ptrdiff_t	n;
	const class std::vector<class cv::Point_<int>>	*c;

	dist	= INFINITY;
	n	= conts->size();
	if (!n)
		return	-1;
	if (!fdist)
		fdist	= &alx_gsl_dist2D_euclidean_32b;

	for (ptrdiff_t j = 0; j < n; j++) {
		c	= &(*conts)[j];
		alx::CV::contour_dimensions(c, NULL, NULL, &ctr_x, &ctr_y);
		dx	= abs(ctr_x - x);
		dy	= abs(ctr_y - y);
		d	= fdist(dx, dy);
		if (d < dist) {
			dist	= d;
			if (cont)
				*cont	= c;
			if (i)
				*i	= j;
		}
	}

	return	0;
}

int	alx_cv_conts_closest	(const void **restrict cont,
				 ptrdiff_t *restrict i,
				 const void *restrict conts,
				 ptrdiff_t x, ptrdiff_t y,
				 double (*fdist)(int32_t dx, int32_t dy))
{
	return	alx::CV::conts_closest((const class std::vector<
						class cv::Point_<int>> **)cont,
					i,
					(const class std::vector<
						class std::vector<
						class cv::Point_<
						int>>> *)conts,
					x, y, fdist);
}

int	alx::CV::contour_mask	(class cv::Mat *restrict img,
				 const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts,
				 ptrdiff_t i)
{

	if (img->channels() != 1)
		return	-1;
	if (i >= (ptrdiff_t)conts->size())
		return	-2;
	img->setTo(cv::Scalar(0));
	cv::drawContours(*img, *conts, i, cv::Scalar(UINT8_MAX), -1);
	return	0;
}

int	alx_cv_contour_mask	(const void **restrict img,
				 const void *restrict conts, ptrdiff_t i)
{
	return	alx::CV::contour_mask((class cv::Mat *)img,
				  	(const class std::vector<
						class std::vector<
						class cv::Point_<
						int>>> *)conts,
					i);
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
