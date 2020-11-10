/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/sys/socket/tcp/client.h"

#include <errno.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
static
int	get_addrs	(const char *server_addr, const char *server_port,
			 struct addrinfo **addrs);
static
int	set_socket	(struct addrinfo *addrs);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_tcp_client_open	(const char *restrict server_addr,
				 const char *restrict server_port)
{
	int		sock;
	struct addrinfo	*addrs;

	if (get_addrs(server_addr, server_port, &addrs))
		return	-2;
	sock	= set_socket(addrs);
	freeaddrinfo(addrs);

	return	sock;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(tcp_client_open, alx_tcp_client_open);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	get_addrs	(const char *server_addr, const char *server_port,
			 struct addrinfo **addrs)
{
	struct protoent	*tcp;
	struct addrinfo	hint = {0};

	tcp	= getprotobyname("tcp");
	if (!tcp)
		return	-1;
	hint.ai_family		= AF_UNSPEC;
	hint.ai_socktype	= SOCK_STREAM;
	hint.ai_protocol	= tcp->p_proto;
	if (getaddrinfo(server_addr, server_port, &hint, addrs))
		return	-1;
	return	0;
}

static
int	set_socket	(struct addrinfo *addrs)
{
	int	sock;

	sock	= -1;
	for (struct addrinfo *ad = addrs; ad; ad = ad->ai_next) {
		sock = socket(ad->ai_family, ad->ai_socktype, ad->ai_protocol);
		if (sock < 0)
			continue;
		if (connect(sock, ad->ai_addr, ad->ai_addrlen))
			goto try_next;
		break;
	try_next:
		close(sock);
		sock	= -1;
	}

	return	sock;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

