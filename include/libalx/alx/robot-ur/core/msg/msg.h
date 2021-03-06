/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/

/*
 * Suported versions of UR secondary client interface:
 *	major	minor
 *	1	6 ... 8
 *	3	0 ... 12
 *	5	0 ... 6
 */


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot-ur/core/msg/msg.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdint.h>

#include "libalx/base/compiler/attribute.h"

#include "libalx/alx/robot-ur/core/core.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define alx_ur_parse_pkg_elem__(type, msg)	__extension__(		\
{									\
	type				t_;				\
	const unsigned char *restrict	*p2_	= msg;			\
	const unsigned char		*p_	= *p2_;			\
									\
	_Generic(t_,							\
	bool: ({	/* bool is sent as char by the UR */		\
		t_	= *p_;						\
		*p2_	+= sizeof(char);				\
	}),								\
	default: ({							\
		memcpy(&t_, p_, sizeof(t_));				\
		*p2_	+= sizeof(t_);					\
	})								\
	);								\
									\
	t_;								\
}									\
)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Alx_UR_Msg_Type {
	MSG_TYPE_ROBOT_STATE	= 16,
	MSG_TYPE_ROBOT_MSG	= 20
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
struct	Alx_UR_Msg_Hdr {
	int32_t	sz;
	uint8_t	type;
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_recvmsg		(struct Alx_UR *ur);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_buffer_read	(struct Alx_UR *ur, int64_t min_timediff_ms);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_buffer_consume	(struct Alx_UR *ur);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(ur_recvmsg,		alx_ur_recvmsg);
ALX_ALIAS_DECLARATION(ur_buffer_read,		alx_ur_buffer_read);
ALX_ALIAS_DECLARATION(ur_buffer_consume,	alx_ur_buffer_consume);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
