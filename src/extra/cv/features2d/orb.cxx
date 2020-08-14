/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/features2d/orb.hxx"

#include <cstddef>

#include <vector>

#include <opencv2/calib3d.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>

#include "libalx/base/compiler/restrict.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define MAX_FEATURES	(50000)
#define GOOD_MATCH_P	(0.25)


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	alx::CV::orb_align	(const class cv::Mat *restrict ref,
				 class cv::Mat *restrict img,
				 class cv::Mat *restrict img_matches)
{
	class std::vector <class cv::KeyPoint>		keypoints_0;
	class std::vector <class cv::KeyPoint>		keypoints_1;
	class cv::Mat					descriptors_0;
	class cv::Mat					descriptors_1;
	class cv::Ptr <class cv::Feature2D>		orb;
	class std::vector <struct cv::DMatch>		matches;
	class cv::Ptr <class cv::DescriptorMatcher>	matcher;
	ptrdiff_t					good_matches;
	class std::vector <class cv::Point_ <float>>	points_0;
	class std::vector <class cv::Point_ <float>>	points_1;
	ptrdiff_t					size;
	class cv::Mat					img_hg;
	class cv::Mat					img_align;

	/* Detect ORB features & compute descriptors */
	orb	= cv::ORB::create(MAX_FEATURES);
	orb->detectAndCompute(*ref, cv::Mat(), keypoints_0, descriptors_0);
	orb->detectAndCompute(*img, cv::Mat(), keypoints_1, descriptors_1);

	/* Match structures */
	matcher	= cv::DescriptorMatcher::create("BruteForce-Hamming");
	matcher->match(descriptors_1, descriptors_0, matches, cv::Mat());

	/* Sort matches by score */
	std::sort(matches.begin(), matches.end());

	/* Remove not so good matches */
	good_matches	= GOOD_MATCH_P * matches.size();
	matches.erase(matches.begin() + good_matches, matches.end());

	/* Draw top matches */
	if (img_matches)
		cv::drawMatches(*img, keypoints_1, *ref, keypoints_0, matches,
								*img_matches);

	/* Extract location of good matches */
	size	= matches.size();
	for (ptrdiff_t i = 0; i < size; i++) {
		points_1.push_back(keypoints_1[matches[i].queryIdx].pt);
		points_0.push_back(keypoints_0[matches[i].trainIdx].pt);
	}

	/* Find homography */
	img_hg	= cv::findHomography(points_1, points_0, cv::RANSAC);

	/* Use homography to warp image */
	cv::warpPerspective(*img, img_align, img_hg, ref->size());

	/* Write img_align into img */
	*img	= img_align;
	img_align.release();
}

void	alx_cv_orb_align	(const void *restrict ref,
				 void *restrict img,
				 void *restrict img_matches)
{
	return	alx::CV::orb_align((const class cv::Mat *)ref,
					(class cv::Mat *)img,
					(class cv::Mat *)img_matches);
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
