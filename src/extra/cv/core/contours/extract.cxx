/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/core/contours/extract.hxx"

#include <cstddef>

#include <vector>

#include <opencv2/core/types.hpp>

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
int	alx::CV::extract_conts	(const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts,
				 const class std::vector<
					class cv::Point_<int>> **restrict cont,
				 ptrdiff_t *restrict size)
{
	ptrdiff_t	sz;

	sz	= conts->size();
	if (sz <= 0)
		return	-1;
	if (cont)
		*cont	= &(*conts)[0];
	if (size)
		*size	= sz;
	return	0;
}

int	alx_cv_extract_conts	(const void *restrict conts,
				 const void **restrict cont,
				 ptrdiff_t *restrict size)
{
	return	alx::CV::extract_conts((const class std::vector<
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


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
