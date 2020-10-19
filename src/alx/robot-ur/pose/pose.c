/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot-ur/pose/pose.h"

#include <stddef.h>
#include <stdio.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/stdio/printf/snprintfs.h"

#include "libalx/alx/robot-ur/core/core.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define THRESHOLD	(0.001)


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_ur_pose_diff	(struct Alx_UR_Pose *restrict diff,
				 const struct Alx_UR_Pose *restrict a,
				 const struct Alx_UR_Pose *restrict b)
{

	if (a->type != b->type)
		return	-1;

	diff->type	= a->type;

	if (diff->type == ALX_UR_POSE_XYZ) {
		diff->xyz.x	= b->xyz.x - a->xyz.x;
		diff->xyz.y	= b->xyz.y - a->xyz.y;
		diff->xyz.z	= b->xyz.z - a->xyz.z;
		diff->xyz.rx	= b->xyz.rx - a->xyz.rx;
		diff->xyz.ry	= b->xyz.ry - a->xyz.ry;
		diff->xyz.rz	= b->xyz.rz - a->xyz.rz;
	} else { /* ALX_UR_POSE_JOINTS */
		for (ptrdiff_t i= 0; i < ARRAY_SSIZE(diff->j.j); i++)
			diff->j.j[i]	= b->j.j[i] - a->j.j[i];
	}

	return	0;
}

bool	alx_ur_is_at_pose	(const struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose)
{
	struct Alx_UR_Pose	here;
	struct Alx_UR_Pose	diff;

	here.type	= pose->type;

	if (pose->type == ALX_UR_POSE_XYZ) {
		here.xyz	= ur->state.cartesian.pos;
		alx_ur_pose_diff(&diff, pose, &here);
		return	(here.xyz.x < THRESHOLD  &&
				here.xyz.y < THRESHOLD  &&
				here.xyz.z < THRESHOLD  &&
				here.xyz.rx < THRESHOLD  &&
				here.xyz.ry < THRESHOLD  &&
				here.xyz.rz < THRESHOLD);
	} else { /* ALX_UR_POSE_JOINTS */
		here.j	= ur->state.joint.q_actual;
		alx_ur_pose_diff(&diff, pose, &here);
		for (ptrdiff_t i= 0; i < ARRAY_SSIZE(here.j.j); i++) {
			if (here.j.j[i] > THRESHOLD)
				return	false;
		}
		return	true;
	}
}

bool	alx_ur_is_at_target	(const struct Alx_UR *ur)
{
	struct Alx_UR_Pose	target;
	struct Alx_UR_Pose	actual;
	struct Alx_UR_Pose	diff;

	target.type	= ALX_UR_POSE_JOINTS;
	target.j	= ur->state.joint.q_target;
	actual.type	= ALX_UR_POSE_JOINTS;
	actual.j	= ur->state.joint.q_actual;

	alx_ur_pose_diff(&diff, &target, &actual);
	for (ptrdiff_t i= 0; i < ARRAY_SSIZE(diff.j.j); i++) {
		if (diff.j.j[i] > THRESHOLD)
			return	false;
	}
	return	true;
}

int	alx_ur_sprintf_pose	(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const struct Alx_UR_Pose *restrict pose)
{

	switch (pose->type) {
	case ALX_UR_POSE_XYZ:
		return	alx_snprintfs(str, NULL, nmemb,
				"p[%.4f, %.4f, %.4f, %.4f, %.4f, %.4f]",
				pose->xyz.x, pose->xyz.y, pose->xyz.z,
				pose->xyz.rx, pose->xyz.ry, pose->xyz.rz);
	case ALX_UR_POSE_JOINTS:
		return	alx_snprintfs(str, NULL, nmemb,
				"[%.4f, %.4f, %.4f, %.4f, %.4f, %.4f]",
				pose->j.j[0], pose->j.j[1], pose->j.j[2],
				pose->j.j[3], pose->j.j[4], pose->j.j[5]);
	default:
		return	-1;
	}
}

int	alx_ur_sprintf_pose_rel	(ptrdiff_t nmemb,
				 char str[static restrict nmemb],
				 const struct Alx_UR_Pose *restrict pose_rel)
{
	const char	*pos;
	char		pos_rel[BUFSIZ];

	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos_rel), pos_rel, pose_rel))
		return	-1;

	switch (pos_rel[0]) {
	case 'p':	/* xyz */
		pos	= "get_actual_tcp_pose()";
		break;
	case '[':	/* joints */
		pos	= "get_actual_joint_positions()";
		break;
	default:
		return	-1;
	}

	return alx_snprintfs(str, NULL,nmemb, "pose_add(%s, %s)", pos, pos_rel);
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(ur_pose_diff,		alx_ur_pose_diff);
ALX_ALIAS_WEAK_DEF(ur_is_at_pose,	alx_ur_is_at_pose);
ALX_ALIAS_WEAK_DEF(ur_is_at_target,	alx_ur_is_at_target);
ALX_ALIAS_WEAK_DEF(ur_sprintf_pose,	alx_ur_sprintf_pose);
ALX_ALIAS_WEAK_DEF(ur_sprintf_pose_rel,	alx_ur_sprintf_pose_rel);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
