/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot-ur/move/move.h"

#include <stdio.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/time/gettime.h"

#include "libalx/alx/robot-ur/core/core.h"
#include "libalx/alx/robot-ur/core/msg/robot_state.h"
#include "libalx/alx/robot-ur/pose/pose.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define QD_THRESHOLD	(0.001)


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_ur_halt		(struct Alx_UR *ur,
				 double timeout)
{
	struct timespec	start;

	if (alx_ur_cmd(ur, "halt"))
		return	-1;

	clock_gettime(CLOCK_REALTIME, &start);
	if (alx_ur_wait_while_moving(ur, timeout, &start))
		return	-1;
	return	0;
}

int	alx_ur_check_movement	(struct Alx_UR *restrict ur,
				 double timeout)
{
	struct timespec	start;

	clock_gettime(CLOCK_REALTIME, &start);
	if (alx_ur_wait_while_moving(ur, timeout, &start))
		return	-1;
	if (!alx_ur_is_at_target(ur))
		return	-1;
	return	0;
}

//#pragma GCC diagnostic push	/* Don't need precission */
//#pragma GCC diagnostic ignored	"-Wconversion"
int	alx_ur_wait_while_moving(struct Alx_UR *restrict ur,
				 double timeout,
				 const struct timespec *restrict tm_start)
{
	double	time;

	do {
		if (alx_ur_robot_state_update(ur))
			return	-1;
		if (!alx_ur_is_moving(ur))
			return	0;
		time	= alx_clock_gettime_diff_ms(CLOCK_REALTIME, tm_start);
	} while (time < timeout * 1000.0);

	return	-1;
}
//#pragma GCC diagnostic pop

bool	alx_ur_is_moving	(const struct Alx_UR *ur)
{

	for (ptrdiff_t i = 0; i < NJOINTS; i++) {
		if (ur->state.joint.qd_actual.j[i] > QD_THRESHOLD)
			return	true;
	}
	return	false;
}

int	alx_ur_movej		(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose,
				 double timeout)
{
	char	pos[BUFSIZ];

	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	if (alx_ur_cmd(ur, "movej(%s);", pos))
		return	-1;
	if (alx_ur_check_movement(ur, timeout))
		return	-1;
	return	0;
}

int	alx_ur_movej_rel	(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose_rel,
				 double timeout)
{
	char	pos_rel[BUFSIZ];

	if (alx_ur_sprintf_pose_rel(ARRAY_SIZE(pos_rel), pos_rel, pose_rel))
		return	-1;
	if (alx_ur_cmd(ur, "movej(%s);", pos_rel))
		return	-1;
	if (alx_ur_check_movement(ur, timeout))
		return	-1;
	return	0;
}

int	alx_ur_movel		(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose,
				 double timeout)
{
	char	pos[BUFSIZ];

	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos), pos, pose))
		return	-1;
	if (alx_ur_cmd(ur, "movel(%s);", pos))
		return	-1;
	if (alx_ur_check_movement(ur, timeout))
		return	-1;
	return	0;
}

int	alx_ur_movel_rel	(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose_rel,
				 double timeout)
{
	char	pos_rel[BUFSIZ];

	if (alx_ur_sprintf_pose_rel(ARRAY_SIZE(pos_rel), pos_rel, pose_rel))
		return	-1;
	if (alx_ur_cmd(ur, "movel(%s);", pos_rel))
		return	-1;
	if (alx_ur_check_movement(ur, timeout))
		return	-1;
	return	0;
}

int	alx_ur_movec		(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict via,
				 const struct Alx_UR_Pose *restrict to,
				 double timeout)
{
	char	pos_via[BUFSIZ];
	char	pos_to[BUFSIZ];

	if (via->type != ALX_UR_POSE_XYZ)
		return	-1;

	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos_via), pos_via, via))
		return	-1;
	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos_to), pos_to, to))
		return	-1;
	if (alx_ur_cmd(ur, "movec(%s, %s);", pos_via, pos_to))
		return	-1;
	if (alx_ur_check_movement(ur, timeout))
		return	-1;
	return	0;
}

int	alx_ur_movec_rel	(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict via,
				 const struct Alx_UR_Pose *restrict to,
				 double timeout)
{
	char	pos_via[BUFSIZ];
	char	pos_to[BUFSIZ];

	if (via->type != ALX_UR_POSE_XYZ)
		return	-1;

	if (alx_ur_sprintf_pose_rel(ARRAY_SIZE(pos_via), pos_via, via))
		return	-1;
	if (alx_ur_sprintf_pose_rel(ARRAY_SIZE(pos_to), pos_to, to))
		return	-1;
	if (alx_ur_cmd(ur, "movec(%s, %s);", pos_via, pos_to))
		return	-1;
	if (alx_ur_check_movement(ur, timeout))
		return	-1;
	return	0;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(ur_halt,		alx_ur_halt);
ALX_ALIAS_WEAK_DEF(ur_check_movement,	alx_ur_check_movement);
ALX_ALIAS_WEAK_DEF(ur_wait_while_moving,	alx_ur_wait_while_moving);
ALX_ALIAS_WEAK_DEF(ur_is_moving,		alx_ur_is_moving);
ALX_ALIAS_WEAK_DEF(ur_movej,		alx_ur_movej);
ALX_ALIAS_WEAK_DEF(ur_movej_rel,		alx_ur_movej_rel);
ALX_ALIAS_WEAK_DEF(ur_movel,		alx_ur_movel);
ALX_ALIAS_WEAK_DEF(ur_movel_rel,		alx_ur_movel_rel);
ALX_ALIAS_WEAK_DEF(ur_movec,		alx_ur_movec);
ALX_ALIAS_WEAK_DEF(ur_movec_rel,		alx_ur_movec_rel);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
