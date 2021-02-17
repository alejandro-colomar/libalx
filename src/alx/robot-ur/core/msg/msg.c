/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot-ur/core/msg/msg.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include <bsd/sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/compiler/unused.h"
#include "libalx/base/sys/socket/msghdr.h"
#include "libalx/base/sys/socket/timestamp.h"
#include "libalx/base/time/timespec.h"

#include "libalx/alx/robot-ur/core/core.h"
#include "libalx/alx/robot-ur/core/msg/robot_state.h"


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
int	alx_ur_recvmsg			(struct Alx_UR *ur)
{
	struct Alx_UR_Msg_Hdr	hdr;
	struct msghdr		msg;
	struct iovec		iov;
	struct timespec		ts;
	char			cbuf[BUFSIZ];
	ssize_t			n;

	alx_wrap_msghdr(&msg, &iov, sizeof(hdr), &hdr, ARRAY_BYTES(cbuf), cbuf);
	n	= recvmsg(ur->sfd, &msg, MSG_WAITALL);
	if (n != sizeof(hdr))
		return	-1;
	if (alx_msg_get_timestampns(&ts, &msg))
		return	-1;

	unsigned char	buf[hdr.sz];

	n	= recv(ur->sfd, buf, ARRAY_SIZE(buf), MSG_WAITALL);
	if (n != ARRAY_SSIZE(buf))
		return	-1;

	switch (hdr.type) {
	case MSG_TYPE_ROBOT_STATE:
		alx_ur_parse_msg_robot_state(ur, ARRAY_SIZE(buf), buf, &ts);
		return	0;
	case MSG_TYPE_ROBOT_MSG:
// TODO		alx_ur_parse_msg_robot_msg(ur, ARRAY_SIZE(buf), buf);
		return	0;
	default:
		return	-1;	/* Unrecignized msg */
	}
}

int	alx_ur_buffer_read		(struct Alx_UR *ur,
					 int64_t min_timediff_ms)
{
	int64_t		time_ms;
	struct timespec	start;
	struct timespec	diff;

	clock_gettime(CLOCK_REALTIME, &start);

	do {
		if (alx_ur_recvmsg(ur))
			return	-1;
		timespecsub(&ur->state.timestamp, &start, &diff);
		time_ms	= alx_timespec_ms(&diff);
	} while (time_ms < min_timediff_ms);
	return	0;
}

int	alx_ur_buffer_consume		(struct Alx_UR *ur)
{
	return	alx_ur_buffer_read(ur, -ROBOT_UPDATE_PERIOD_MS);
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(ur_recvmsg,		alx_ur_recvmsg);
ALX_ALIAS_WEAK_DEF(ur_buffer_read,	alx_ur_buffer_read);
ALX_ALIAS_WEAK_DEF(ur_buffer_consume,	alx_ur_buffer_consume);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
