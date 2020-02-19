/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/ur/ur.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
struct	Alx_UR {
	int	sfd;
	int	usleep;
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull, warn_unused_result))
int	alx_ur_init	(struct Alx_UR **restrict ur, int usleep_time,
			 const char *restrict ur_ip,
			 const char *restrict ur_port);

__attribute__((warn_unused_result))
int	alx_ur_deinit	(struct Alx_UR *restrict ur);

__attribute__((nonnull, warn_unused_result))
int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 const char *restrict cmd);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull, warn_unused_result))
int	ur_init		(struct Alx_UR **restrict ur, int usleep_time,
			 const char *restrict ur_ip,
			 const char *restrict ur_port)
{
	return	alx_ur_init(ur, usleep_time, ur_ip, ur_port);
}

__attribute__((always_inline, warn_unused_result))
int	ur_deinit	(struct Alx_UR *restrict ur)
{
	return	alx_ur_deinit(ur);
}

__attribute__((always_inline, nonnull, warn_unused_result))
int	ur_cmd		(const struct Alx_UR *restrict ur,
			 const char *restrict cmd)
{
	return	alx_ur_cmd(ur, cmd);
}
#endif	 /* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
