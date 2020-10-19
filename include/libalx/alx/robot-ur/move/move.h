/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot-ur/move/move.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/compiler/attribute.h"

#include "libalx/alx/robot-ur/core/core.h"
#include "libalx/alx/robot-ur/pose/pose.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_halt		(struct Alx_UR *ur,
				 double timeout);

[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_check_movement	(struct Alx_UR *restrict ur,
				 double timeout);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_wait_while_moving(struct Alx_UR *restrict ur,
				 double timeout,
				 const struct timespec *restrict tm_start);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
bool	alx_ur_is_moving	(const struct Alx_UR *ur);

[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movej		(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose,
				 double timeout);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movej_rel	(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose_rel,
				 double timeout);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movel		(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose,
				 double timeout);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movel_rel	(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict pose_rel,
				 double timeout);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movec		(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict via,
				 const struct Alx_UR_Pose *restrict to,
				 double timeout);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movec_rel	(struct Alx_UR *restrict ur,
				 const struct Alx_UR_Pose *restrict via,
				 const struct Alx_UR_Pose *restrict to,
				 double timeout);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(ur_halt,			alx_ur_halt);
ALX_ALIAS_DECLARATION(ur_check_movement,	alx_ur_check_movement);
ALX_ALIAS_DECLARATION(ur_wait_while_moving,	alx_ur_wait_while_moving);
ALX_ALIAS_DECLARATION(ur_is_moving,		alx_ur_is_moving);
ALX_ALIAS_DECLARATION(ur_movej,			alx_ur_movej);
ALX_ALIAS_DECLARATION(ur_movej_rel,		alx_ur_movej_rel);
ALX_ALIAS_DECLARATION(ur_movel,			alx_ur_movel);
ALX_ALIAS_DECLARATION(ur_movel_rel,		alx_ur_movel_rel);
ALX_ALIAS_DECLARATION(ur_movec,			alx_ur_movec);
ALX_ALIAS_DECLARATION(ur_movec_rel,		alx_ur_movec_rel);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
