/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/core/contours/extract.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>

#include <vector>

#include <opencv2/core/base.hpp>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull(1)]]
int	alx_cv_extract_conts	(const void *restrict conts,
				 const void **restrict cont,
				 ptrdiff_t *restrict size);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_cv_extract_conts_cont(const void **restrict cont,
				 const void *restrict conts, ptrdiff_t i);
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
[[gnu::nonnull(1)]]
int	extract_conts	(const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts,
			 const class std::vector<
					class cv::Point_<int>> **restrict cont,
			 ptrdiff_t *restrict size);
[[gnu::nonnull]]
int	extract_conts_cont(const class std::vector<
					class cv::Point_<int>> **restrict cont,
			 const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts,
			 ptrdiff_t i);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/