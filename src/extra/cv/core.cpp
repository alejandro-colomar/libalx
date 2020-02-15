/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/core.hpp"

#include <cstdbool>
#include <cstddef>
#include <cstdint>

#include <memory>
#include <vector>

#include <opencv2/core.hpp>

#include "libalx/base/compiler/restrict.hpp"
#include "libalx/base/stdlib/alloc/mallocarrays.hpp"
#include "libalx/base/stdlib/swap.hpp"


/******************************************************************************
 ******* macros ***************************************************************
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
int	alx::CV::alloc_img	(class cv::Mat **restrict img)
{
	return	alx_mallocarrays(img, 1);
}

int	alx_cv_alloc_img	(void **restrict img)
{
	return	alx::CV::alloc_img((class cv::Mat **)img);
}

void	alx::CV::free_img	(class cv::Mat *restrict img)
{

	img->release();
	free(img);
}

void	alx_cv_free_img		(void *restrict img)
{
	alx::CV::free_img((class cv::Mat *)img);
}

int	alx::CV::alloc_rect	(class cv::Rect_<int> **restrict rect)
{
	return	alx_mallocarrays(rect, 1);
}

int	alx_cv_alloc_rect	(void **restrict rect)
{
	return	alx::CV::alloc_rect((class cv::Rect_<int> **)rect);
}

void	alx::CV::free_rect	(class cv::Rect_<int> *restrict rect)
{
	free(rect);
}

void	alx_cv_free_rect	(void *restrict rect)
{
	alx::CV::free_rect((class cv::Rect_<int> *)rect);
}

int	alx::CV::alloc_rect_rot	(class cv::RotatedRect **restrict rect_rot)
{
	return	alx_mallocarrays(rect_rot, 1);
}

int	alx_cv_alloc_rect_rot	(void **restrict rect_rot)
{
	return	alx::CV::alloc_rect_rot((class cv::RotatedRect **)rect_rot);
}

void	alx::CV::free_rect_rot	(class cv::RotatedRect *restrict rect_rot)
{
	free(rect_rot);
}

void	alx_cv_free_rect_rot	(void *restrict rect_rot)
{
	alx::CV::free_rect_rot((class cv::RotatedRect *)rect_rot);
}

int	alx::CV::alloc_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> **restrict contours)
{
	return	alx_mallocarrays(contours, 1);
}

int	alx_cv_alloc_conts	(void **restrict contours)
{
	return	alx::CV::alloc_conts((class std::vector<
					class std::vector<
					class cv::Point_<int>>> **)contours);
}

void	alx::CV::free_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> *restrict contours)
{
	free(contours);
}

void	alx_cv_free_conts	(void *restrict contours)
{
	alx::CV::free_conts((class std::vector<
					class std::vector<
					class cv::Point_<int>>> *)contours);
}

/* ----- init / deinit */
int	alx::CV::init_img	(class cv::Mat *restrict img,
				 ptrdiff_t w, ptrdiff_t h)
{

	if (w < 1 || h < 1)
		return	1;
	new (img)	cv::Mat(cv::Size(w, h), CV_8UC3, 0.0);

	return	0;
}

int	alx_cv_init_img		(void *restrict img, ptrdiff_t w, ptrdiff_t h)
{
	return	alx::CV::init_img((class cv::Mat *)img, w, h);
}

void	alx::CV::deinit_img	(class cv::Mat *restrict img)
{
	std::destroy_at(img);
}

void	alx_cv_deinit_img	(void *restrict img)
{
	alx::CV::deinit_img((class cv::Mat *)img);
}

void	alx::CV::init_conts	(class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts)
{
	new (conts)	std::vector<std::vector<cv::Point_<int>>>();
}

void	alx_cv_init_conts	(void *restrict conts)
{
	return	alx::CV::init_conts((class std::vector<
					class std::vector<
					class cv::Point_<int>>> *)conts);
}

void	alx::CV::deinit_conts	(class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts)
{
	std::destroy_at(conts);
}

void	alx_cv_deinit_conts	(void *restrict conts)
{
	alx::CV::deinit_conts((class std::vector<
					class std::vector<
					class cv::Point_<int>>> *)conts);
}

int	alx::CV::init_rect	(class cv::Rect_<int> *restrict rect,
				 ptrdiff_t x, ptrdiff_t y,
				 ptrdiff_t w, ptrdiff_t h)
{

	if (x < 0 || y < 0 || w < 1 || h < 1)
		return	1;
	rect->x		= x;
	rect->y		= y;
	rect->width	= w;
	rect->height	= h;

	return	0;
}

int	alx_cv_init_rect	(void *restrict rect,
				 ptrdiff_t x, ptrdiff_t y,
				 ptrdiff_t w, ptrdiff_t h)
{
	return	alx::CV::init_rect((class cv::Rect_<int> *)rect, x, y, w, h);
}

/* ----- Extract */
void	alx::CV::extract_imgdata(const class cv::Mat *restrict img, void **data,
				 ptrdiff_t *restrict rows,
				 ptrdiff_t *restrict cols,
				 ptrdiff_t *restrict width,
				 ptrdiff_t *restrict height,
				 ptrdiff_t *restrict B_per_pix,
				 ptrdiff_t *restrict B_per_line,
				 int *restrict type)
{

	if (data)
		*data		= img->data;
	if (rows)
		*rows		= img->rows;
	if (cols)
		*cols		= img->cols;
	if (width)
		*width		= img->size().width;
	if (height)
		*height		= img->size().height;
	if (B_per_pix)
		*B_per_pix	= img->channels();
	if (B_per_line)
		*B_per_line	= img->step1();
	if (type)
		*type		= img->type();
}

void	alx_cv_extract_imgdata	(const void *restrict img, void **data,
				 ptrdiff_t *restrict rows,
				 ptrdiff_t *restrict cols,
				 ptrdiff_t *restrict width,
				 ptrdiff_t *restrict height,
				 ptrdiff_t *restrict B_per_pix,
				 ptrdiff_t *restrict B_per_line,
				 int *restrict type)
{
	alx::CV::extract_imgdata((const class cv::Mat *)img, data,
						rows, cols, width, height,
						B_per_pix, B_per_line, type);
}

void	alx::CV::extract_rect	(const class cv::Rect_<int> *restrict rect,
				 ptrdiff_t *restrict x, ptrdiff_t *restrict y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h)
{

	if (x)
		*x = rect->x;
	if (y)
		*y = rect->y;
	if (w)
		*w = rect->width;
	if (h)
		*h = rect->height;
}

void	alx_cv_extract_rect	(const void *restrict rect,
				 ptrdiff_t *restrict x, ptrdiff_t *restrict y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h)
{
	alx::CV::extract_rect((const class cv::Rect_<int> *)rect, x, y, w, h);
}

void	alx::CV::extract_rect_rot(const class cv::RotatedRect *restrict rect_rot,
				 ptrdiff_t *restrict ctr_x,
				 ptrdiff_t *restrict ctr_y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h,
				 double *restrict angle)
{

	if (ctr_x)
		*ctr_x	= rect_rot->center.x;
	if (ctr_y)
		*ctr_y	= rect_rot->center.y;
	if (w)
		*w	= rect_rot->size.width;
	if (h)
		*h	= rect_rot->size.height;
	if (angle) {
		*angle	= rect_rot->angle;
		/* If angle < -45º, it is taking the incorrect side */
		if (*angle < -45.0) {
			*angle += 90.0;
			ALX_SWAP(w, h);
		}
	}
}

void	alx_cv_extract_rect_rot	(const void *restrict rect_rot,
				 ptrdiff_t *restrict ctr_x,
				 ptrdiff_t *restrict ctr_y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h,
				 double *restrict angle)
{
	alx::CV::extract_rect_rot((const class cv::RotatedRect *)rect_rot,
						ctr_x, ctr_y, w, h, angle);
}

void	alx::CV::extract_conts	(const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts,
				 const class std::vector<
					class cv::Point_<int>> **restrict cont,
				 ptrdiff_t *restrict size)
{

	if (cont)
		*cont	= &(*conts)[0];
	*size	= conts->size();
}

void	alx_cv_extract_conts	(const void *restrict conts,
				 const void **restrict cont,
				 ptrdiff_t *restrict size)
{
	alx::CV::extract_conts((const class std::vector<
						class std::vector<
						class cv::Point_<int>>> *)conts,
					(const class std::vector<
						class cv::Point_<int>> **)cont,
					size);
}

int	alx::CV::extract_conts_cont(const class std::vector<
					class cv::Point_<int>> **restrict cont,
				 const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts,
				 ptrdiff_t i)
{

	if (i < 0 || (size_t)i >= conts->size())
		return	-1;
	*cont	= &(*conts)[i];

	return	0;
}

int	alx_cv_extract_conts_cont(const void **restrict cont,
				 const void *restrict conts, ptrdiff_t i)
{
	return	alx::CV::extract_conts_cont((const class std::vector<
						class cv::Point_<int>> **)cont,
					 (const class std::vector<
						class std::vector<
						class cv::Point_<int>>> *)conts,
					 i);
}

/* ----- Copy */
void	alx::CV::clone		(class cv::Mat *restrict clone,
				 const class cv::Mat *restrict img)
{
	img->copyTo(*clone);
}

void	alx_cv_clone		(void *restrict clone, const void *restrict img)
{
	alx::CV::clone((class cv::Mat *)clone, (const class cv::Mat *)img);
}

/* ----- Pixel */
int	alx::CV::pixel_get_u8	(const class cv::Mat *restrict img,
				 unsigned char *restrict val,
				 ptrdiff_t x, ptrdiff_t y)
{

	/* TODO: multichannel images */
	if (img->channels() != 1)
		return	-1;
	if (x < 0 || y < 0)
		return	-1;
	*val	= img->at<unsigned char>(y, x);

	return	0;
}

int	alx_cv_pixel_get_u8	(const void *restrict img,
				 unsigned char *restrict val,
				 ptrdiff_t x, ptrdiff_t y)
{
	return	alx::CV::pixel_get_u8((const class cv::Mat *)img, val, x, y);
}

int	alx::CV::pixel_set_u8	(class cv::Mat *restrict img,
				 unsigned char val, ptrdiff_t x, ptrdiff_t y)
{

	/* TODO: multichannel images */
	if (img->channels() != 1)
		return	1;
	if (x < 0 || y < 0)
		return	1;
	img->at<unsigned char>(y, x)	= val;

	return	0;
}

int	alx_cv_pixel_set_u8	(void *restrict img,
				 unsigned char val, ptrdiff_t x, ptrdiff_t y)
{
	return	alx::CV::pixel_set_u8((class cv::Mat *)img, val, x, y);
}

int	alx::CV::pixel_get_flt	(const class cv::Mat *restrict img,
				 float *restrict val, ptrdiff_t x, ptrdiff_t y)
{

	/* TODO: multichannel images */
	if (img->channels() != 1)
		return	-1;
	if (x < 0 || y < 0)
		return	-1;
	*val	= img->at<float>(y, x);

	return	0;
}

int	alx_cv_pixel_get_flt	(const void *restrict img,
				 float *restrict val, ptrdiff_t x, ptrdiff_t y)
{
	return	alx::CV::pixel_get_flt((const class cv::Mat *)img, val, x, y);
}

/* ----- ROI */
void	alx::CV::roi_set	(class cv::Mat *restrict img,
				 const class cv::Rect_<int> *restrict rect)
{
	class cv::Mat	tmp;

	(*img)(*rect).copyTo(tmp);
	img->release();
	tmp.copyTo(*img);

	tmp.release();
}

void	alx_cv_roi_set		(void *restrict img, const void *restrict rect)
{
	alx::CV::roi_set((class cv::Mat *)img,
					(const class cv::Rect_<int> *)rect);
}

/* ----- Operations on arrays */
int	alx::CV::and_2ref	(class cv::Mat *restrict img,
				 const class cv::Mat *restrict ref)
{

	if (img->channels() != ref->channels())
		return	1;
	cv::bitwise_and(*img, *ref, *img);

	return	0;
}

int	alx_cv_and_2ref		(void *restrict img, const void *restrict ref)
{
	return	alx::CV::and_2ref((class cv::Mat *)img,
						(const class cv::Mat *)ref);
}

void	alx::CV::invert		(class cv::Mat *restrict img)
{
	cv::bitwise_not(*img, *img);
}

void	alx_cv_invert		(void *restrict img)
{
	alx::CV::invert((class cv::Mat *)img);
}

int	alx::CV::or_2ref	(class cv::Mat *restrict img,
				 const class cv::Mat *restrict ref)
{

	if (img->channels() != ref->channels())
		return	1;
	cv::bitwise_or(*img, *ref, *img);

	return	0;
}

int	alx_cv_or_2ref		(void *restrict img, const void *restrict ref)
{
	return	alx::CV::or_2ref((class cv::Mat *)img,
						(const class cv::Mat *)ref);
}

int	alx::CV::component	(class cv::Mat *restrict img, ptrdiff_t cmp)
{
	const ptrdiff_t	chans	= img->channels();
	class cv::Mat	cmp_img[chans];

	if (chans < 2)
		return	1;
	if (cmp < 0 || cmp >= chans)
		return	1;

	cv::split(*img, cmp_img);
	img->release();
	cmp_img[cmp].copyTo(*img);

	for (ptrdiff_t i = 0; i < chans; i++)
		cmp_img[i].release();
	return	0;
}

int	alx_cv_component	(void *restrict img, ptrdiff_t cmp)
{
	return	alx::CV::component((class cv::Mat *)img, cmp);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
