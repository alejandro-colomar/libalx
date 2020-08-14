/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot/ur/pose/pose.hxx */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdbool>
#include <cstddef>

#include "libalx/base/compiler/attribute.hxx"
#include "libalx/base/compiler/restrict.hxx"

#include "libalx/alx/robot/ur/core/core.hxx"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define ALX_UR_POSE_INIT_XYZ(x_, y_, z_, rx_, ry_, rz_)			\
(struct Alx_UR_Pose){							\
	.type	= (ALX_UR_POSE_XYZ),					\
	.x	= (x_),							\
	.y	= (y_),							\
	.z	= (z_),							\
	.rx	= (rx_),						\
	.ry	= (ry_),						\
	.rz	= (rz_)							\
}

#define ALX_UR_POSE_INIT_JOINTS(b_, s_, e_, w1_, w2_, w3_)		\
(struct Alx_UR_Pose){							\
	.type		= (ALX_UR_POSE_JOINTS),				\
	.base		= (b_),						\
	.shoulder	= (s_),						\
	.elbow		= (e_),						\
	.wrist1		= (w1_),					\
	.wrist2		= (w2_),					\
	.wrist3		= (w3_)						\
}


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern "C" {


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
struct	Alx_UR_Pose {
	int	type;
	union {
		struct Alx_UR_Coord	xyz;
		union Alx_UR_Joints	j;
	};
};


/******************************************************************************
 ******* C prototypes *********************************************************
 ******************************************************************************/
[[gnu::nonnull]]
int	alx_ur_pose_diff	(struct Alx_UR_Pose *restrict diff,
				 const struct Alx_UR_Pose *restrict a,
				 const struct Alx_UR_Pose *restrict b);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
bool	alx_ur_is_at_pose	(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
bool	alx_ur_is_at_target	(const struct Alx_UR *ur);
[[gnu::nonnull]]
int	alx_ur_sprintf_pose	(ptrdiff_t nmemb,
				 char *restrict str/*[nmemb]*/,
				 const struct Alx_UR_Pose *restrict pose);
[[gnu::nonnull]]
int	alx_ur_sprintf_pose_rel	(ptrdiff_t nmemb,
				 char *restrict str/*[nmemb]*/,
				 const struct Alx_UR_Pose *restrict pose_rel);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define UR_POSE_INIT_XYZ(x, y, z, rx, ry, rz)				\
	ALX_UR_POSE_INIT_XYZ(x, y, z, rx, ry, rz)
#define UR_POSE_INIT_JOINTS(b, s, e, w1, w2, w3)			\
	ALX_UR_POSE_INIT_JOINTS(b, s, e, w1, w2, w3)
ALX_ALIAS_DECLARATION(ur_pose_diff,		alx_ur_pose_diff);
ALX_ALIAS_DECLARATION(ur_is_at_pose,		alx_ur_is_at_pose);
ALX_ALIAS_DECLARATION(ur_is_at_target,		alx_ur_is_at_target);
ALX_ALIAS_DECLARATION(ur_sprintf_pose,		alx_ur_sprintf_pose);
ALX_ALIAS_DECLARATION(ur_sprintf_pose_rel,	alx_ur_sprintf_pose_rel);
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
}	/* extern "C" */


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace UR {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Pose_Types {
	POSE_NONE,
	POSE_XYZ,
	POSE_JOINTS
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace UR */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
