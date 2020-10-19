/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot-ur/core/core.h"

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "libalx/base/stdlib/alloc/callocs.h"
#include "libalx/base/stdlib/alloc/frees.h"
#include "libalx/base/stdio/printf/sbprintf.h"
#include "libalx/base/string/strcat/strbcatf.h"
#include "libalx/base/sys/socket/tcp/client.h"

#include "libalx/alx/robot-ur/move/move.h"
#include "libalx/alx/robot-ur/core/msg/robot_state.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define UR_SECONDARY_PORT	"30002"


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_ur_init	(struct Alx_UR **restrict ur,
			 const char *restrict ur_ip)
{
	int	sfd;
	int	enable = 1;

	sfd	= alx_tcp_client_open(ur_ip, UR_SECONDARY_PORT);
	if (sfd < 0)
		return	-1;
	if (setsockopt(sfd, SOL_SOCKET, SO_TIMESTAMPNS, &enable,sizeof(enable)))
		goto err1;

	if (alx_callocs(ur, 1))
		goto err1;
	(*ur)->sfd	= sfd;

	/*
	 * First received message is 'version' (in newer UR client versions).
	 * When robot state is updated, version will have been received.
	 */
	if (alx_ur_robot_state_update(*ur))
		goto err2;

	return	0;

err2:	alx_frees(ur);
err1:	close(sfd);
	return	-1;
}

int	alx_ur_deinit	(struct Alx_UR *restrict ur)
{
	int	status;

	if (!ur)
		return	-1;

	status	= alx_ur_halt(ur, 0);
	if (close(ur->sfd))
		return	-1;
	ur->sfd	= -1;
	free(ur);
	return	status;
}

//#pragma GCC diagnostic push	/* Overflow is impossible (vsbprintf) */
//#pragma GCC diagnostic ignored	"-Wsign-conversion"
int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 const char *restrict fmt, ...)
{
	va_list	ap;
	int	status;
	char	buf[BUFSIZ];
	ssize_t	n;
	ssize_t	len;

	va_start(ap, fmt);
	status	= alx_vsbprintf(buf, NULL, fmt, ap);
	va_end(ap);
	if (status)
		return	-1;
	if (alx_strbcatf(buf, NULL, "\n"))
		return	-1;
	len	= strlen(buf);

	n	= send(ur->sfd, buf, len, 0);
	if (n != len)
		goto err;

	printf("%s", buf);
	return	0;
err:
	fprintf(stderr, "%s", buf);
	return	-1;
}
//#pragma GCC diagnostic pop

int	alx_ur_poweroff	(const struct Alx_UR *restrict ur)
{
	return	alx_ur_cmd(ur, "powerdown();");
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(ur_init,	alx_ur_init);
ALX_ALIAS_WEAK_DEF(ur_deinit,	alx_ur_deinit);
ALX_ALIAS_WEAK_DEF(ur_cmd,	alx_ur_cmd);
ALX_ALIAS_WEAK_DEF(ur_poweroff,	alx_ur_poweroff);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
