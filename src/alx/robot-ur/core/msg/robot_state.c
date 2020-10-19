/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot-ur/core/msg/robot_state.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/compiler/unused.h"
#include "libalx/base/sys/socket/msghdr.h"
#include "libalx/base/sys/socket/timestamp.h"

#include "libalx/alx/robot-ur/core/core.h"
#include "libalx/alx/robot-ur/core/msg/msg.h"


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
void	parse_rspkg_robot_mode_data	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);
static
void	parse_rspkg_joint_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);
static
void	parse_rspkg_tool_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);
static
void	parse_rspkg_mb_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);
static
void	parse_rspkg_cartesian_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);
static
void	parse_rspkg_kinematics_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);
static
void	parse_rspkg_config_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);
static
void	parse_rspkg_force_mode_data	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);

static
void	parse_rspkg_additional_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);
static
void	parse_rspkg_calib_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);
static
void	parse_rspkg_safety_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);
static
void	parse_rspkg_tool_comm_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);
static
void	parse_rspkg_tool_mode_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz]);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_ur_robot_state_update	(struct Alx_UR *ur)
{
	return	alx_ur_buffer_read(ur, ROBOT_UPDATE_PERIOD_MS);
}

void	alx_ur_parse_msg_robot_state	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz],
					 const struct timespec *restrict ts)
{
	struct Alx_UR_Robot_State_Pkg_Hdr	hdr;

	ur->state.timestamp	= *ts;

	while (sz > 0) {
		memcpy(&hdr, msg, sizeof(hdr));
		msg	+= sizeof(hdr);
		sz	-= ssizeof(hdr);

		switch (hdr.type) {
		case ROBOT_STATE_PKG_TYPE_ROBOT_MODE_DATA:
			parse_rspkg_robot_mode_data(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_JOINT_DATA:
			parse_rspkg_joint_data(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_TOOL_DATA:
			parse_rspkg_tool_data(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_MB_DATA:
			parse_rspkg_mb_data(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_CARTESIAN_INFO:
			parse_rspkg_cartesian_info(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_KINEMATICS_INFO:
			parse_rspkg_kinematics_info(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_CONFIG_DATA:
			parse_rspkg_config_data(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_FORCE_MODE_DATA:
			parse_rspkg_force_mode_data(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_ADDITIONAL_INFO:
			parse_rspkg_additional_info(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_CALIB_DATA:
			parse_rspkg_calib_data(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_SAFETY_DATA:
			parse_rspkg_safety_data(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_TOOL_COMM_INFO:
			parse_rspkg_tool_comm_info(ur, hdr.sz, msg);
			break;
		case ROBOT_STATE_PKG_TYPE_TOOL_MODE_INFO:
			parse_rspkg_tool_mode_info(ur, hdr.sz, msg);
			break;
		default:
			break;	/* Unsupported pkg */
		}

		msg	+= hdr.sz;
		sz	-= hdr.sz;
	}
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(ur_robot_state_update,   alx_ur_robot_state_update);
ALX_ALIAS_WEAK_DEF(ur_parse_msg_robot_state,alx_ur_parse_msg_robot_state);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
//#pragma GCC diagnostic push	/* Handle weird UR type decissions */
//#pragma GCC diagnostic ignored	"-Wsign-conversion"
static
void	parse_rspkg_robot_mode_data	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Robot_Mode_Data	*data	= &ur->state.robot_mode;

	data->timestamp			= alx_ur_parse_pkg_elem__(uint64_t, &msg);
	data->is_connected		= alx_ur_parse_pkg_elem__(bool, &msg);
	data->is_enabled		= alx_ur_parse_pkg_elem__(bool, &msg);
	data->is_power_on		= alx_ur_parse_pkg_elem__(bool, &msg);
	data->is_emergency_stopped	= alx_ur_parse_pkg_elem__(bool, &msg);
	data->is_protective_stopped	= alx_ur_parse_pkg_elem__(bool, &msg);
	data->is_running		= alx_ur_parse_pkg_elem__(bool, &msg);
	data->is_paused			= alx_ur_parse_pkg_elem__(bool, &msg);
	data->robot_mode		= alx_ur_parse_pkg_elem__(int8_t, &msg);

	/* Different versions continue differently from here. */
	if (ur->version.v.major < 3) {
		data->target_speed_fraction = alx_ur_parse_pkg_elem__(double, &msg);
		return;
	}

	data->ctrl_mode			= alx_ur_parse_pkg_elem__(uint8_t, &msg);
	data->target_speed_fraction	= alx_ur_parse_pkg_elem__(double, &msg);
	data->speed_scaling		= alx_ur_parse_pkg_elem__(double, &msg);

	if (ur->version.v.major == 3  &&  ur->version.v.minor < 2)
		return;

	data->target_speed_fraction_limit = alx_ur_parse_pkg_elem__(double, &msg);
}

static
void	parse_rspkg_joint_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Joint_Data	*data	= &ur->state.joint;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->q_actual.j); i++) {
		data->q_actual.j[i]	= alx_ur_parse_pkg_elem__(double, &msg);
		data->q_target.j[i]	= alx_ur_parse_pkg_elem__(double, &msg);
		data->qd_actual.j[i]	= alx_ur_parse_pkg_elem__(double, &msg);
		data->i_actual.j[i]	= alx_ur_parse_pkg_elem__(float, &msg);
		data->v_actual.j[i]	= alx_ur_parse_pkg_elem__(float, &msg);
		data->t_motor.j[i]	= alx_ur_parse_pkg_elem__(float, &msg);
		data->_t_micro.j[i]	= alx_ur_parse_pkg_elem__(float, &msg);
		data->mode.j[i]		= alx_ur_parse_pkg_elem__(uint8_t, &msg);
	}
}

static
void	parse_rspkg_tool_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Tool_Data	*data	= &ur->state.tool_data;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AI_range); i++)
		data->AI_range[i]	= alx_ur_parse_pkg_elem__(uint8_t, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AI); i++)
		data->AI[i]		= alx_ur_parse_pkg_elem__(double, &msg);

	data->voltage		= alx_ur_parse_pkg_elem__(float, &msg);
	data->output_voltage	= alx_ur_parse_pkg_elem__(uint8_t, &msg);
	data->current		= alx_ur_parse_pkg_elem__(float, &msg);
	data->temp		= alx_ur_parse_pkg_elem__(float, &msg);
	data->mode		= alx_ur_parse_pkg_elem__(uint8_t, &msg);
}

static
void	parse_rspkg_mb_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_MB_Data	*data	= &ur->state.mb;

	if (ur->version.v.major < 3) {
		data->DI_bits	= alx_ur_parse_pkg_elem__(uint16_t, &msg);
		data->DO_bits	= alx_ur_parse_pkg_elem__(uint16_t, &msg);
	} else {
		data->DI_bits	= alx_ur_parse_pkg_elem__(uint32_t, &msg);
		data->DO_bits	= alx_ur_parse_pkg_elem__(uint32_t, &msg);
	}
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AI_range); i++)
		data->AI_range[i]	= alx_ur_parse_pkg_elem__(uint8_t, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AI); i++)
		data->AI[i]		= alx_ur_parse_pkg_elem__(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AO_domain); i++)
		data->AO_domain[i]	= alx_ur_parse_pkg_elem__(uint8_t, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AO); i++)
		data->AO[i]		= alx_ur_parse_pkg_elem__(double, &msg);

	data->mb_temp		= alx_ur_parse_pkg_elem__(float, &msg);
	data->robot_voltage	= alx_ur_parse_pkg_elem__(float, &msg);
	data->robot_current	= alx_ur_parse_pkg_elem__(float, &msg);
	data->mb_io_current	= alx_ur_parse_pkg_elem__(float, &msg);
	data->safety_mode	= alx_ur_parse_pkg_elem__(uint8_t, &msg);
	data->in_reduced_mode	= alx_ur_parse_pkg_elem__(uint8_t, &msg);

	data->euromap.iface_installed	= alx_ur_parse_pkg_elem__(bool, &msg);
	if (data->euromap.iface_installed) {
		data->euromap.in_bits	= alx_ur_parse_pkg_elem__(uint32_t, &msg);
		data->euromap.out_bits	= alx_ur_parse_pkg_elem__(uint32_t, &msg);
		if (ur->version.v.major < 3) {
			data->euromap.voltage = alx_ur_parse_pkg_elem__(uint16_t, &msg);
			data->euromap.current = alx_ur_parse_pkg_elem__(uint16_t, &msg);
		} else {
			data->euromap.voltage = alx_ur_parse_pkg_elem__(float, &msg);
			data->euromap.current = alx_ur_parse_pkg_elem__(float, &msg);
		}
	}

	if (ur->version.v.major < 3)
		return;

	data->_reserved_0	= alx_ur_parse_pkg_elem__(uint32_t, &msg);

	if (ur->version.v.major == 3  &&  ur->version.v.minor < 2)
		return;

	data->op_mode_sel_in		= alx_ur_parse_pkg_elem__(uint8_t, &msg);
	data->three_pos_enabling_dev_in	= alx_ur_parse_pkg_elem__(uint8_t, &msg);

	if (ur->version.v.major == 3  &&  ur->version.v.minor < 10)
		return;
	if (ur->version.v.major == 5  &&  ur->version.v.minor < 4)
		return;

	data->_reserved_1	= alx_ur_parse_pkg_elem__(uint8_t, &msg);
}
//#pragma GCC diagnostic pop

static
void	parse_rspkg_cartesian_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Cartesian_Info	*data	= &ur->state.cartesian;

	data->pos.x	= alx_ur_parse_pkg_elem__(double, &msg);
	data->pos.y	= alx_ur_parse_pkg_elem__(double, &msg);
	data->pos.z	= alx_ur_parse_pkg_elem__(double, &msg);
	data->pos.rx	= alx_ur_parse_pkg_elem__(double, &msg);
	data->pos.ry	= alx_ur_parse_pkg_elem__(double, &msg);
	data->pos.rz	= alx_ur_parse_pkg_elem__(double, &msg);

	if (ur->version.v.major < 3)
		return;
	if (ur->version.v.major == 3  &&  ur->version.v.minor < 1)
		return;

	data->tcp_offset.x	= alx_ur_parse_pkg_elem__(double, &msg);
	data->tcp_offset.y	= alx_ur_parse_pkg_elem__(double, &msg);
	data->tcp_offset.z	= alx_ur_parse_pkg_elem__(double, &msg);
	data->tcp_offset.rx	= alx_ur_parse_pkg_elem__(double, &msg);
	data->tcp_offset.ry	= alx_ur_parse_pkg_elem__(double, &msg);
	data->tcp_offset.rz	= alx_ur_parse_pkg_elem__(double, &msg);
}

static
void	parse_rspkg_kinematics_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Kinematics_Info	*data	= &ur->state.kinematics;

	if (ur->version.v.major < 3)
		return;
	if (ur->version.v.major == 3  &&  ur->version.v.minor < 6)
		return;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].chksum	= alx_ur_parse_pkg_elem__(uint32_t, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].DH_theta	= alx_ur_parse_pkg_elem__(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].DH_a	= alx_ur_parse_pkg_elem__(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].Dh_d	= alx_ur_parse_pkg_elem__(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].Dh_alpha	= alx_ur_parse_pkg_elem__(double, &msg);

	data->calib	= alx_ur_parse_pkg_elem__(uint32_t, &msg);
}

static
void	parse_rspkg_config_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Config_Data	*data	= &ur->state.config;

	if (ur->version.v.major == 1  &&  ur->version.v.minor < 8)
		return;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++) {
		data->joint[i].min_limit = alx_ur_parse_pkg_elem__(double, &msg);
		data->joint[i].max_limit = alx_ur_parse_pkg_elem__(double, &msg);
	}
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++) {
		data->joint[i].max_speed = alx_ur_parse_pkg_elem__(double, &msg);
		data->joint[i].max_accel = alx_ur_parse_pkg_elem__(double, &msg);
	}
	data->v_joint_default	= alx_ur_parse_pkg_elem__(double, &msg);
	data->a_joint_default	= alx_ur_parse_pkg_elem__(double, &msg);
	data->v_tool_default	= alx_ur_parse_pkg_elem__(double, &msg);
	data->a_tool_default	= alx_ur_parse_pkg_elem__(double, &msg);
	data->eq_radius		= alx_ur_parse_pkg_elem__(double, &msg);

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].DH_theta	= alx_ur_parse_pkg_elem__(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].DH_a	= alx_ur_parse_pkg_elem__(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].Dh_d	= alx_ur_parse_pkg_elem__(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].Dh_alpha	= alx_ur_parse_pkg_elem__(double, &msg);

	data->mb_version	= alx_ur_parse_pkg_elem__(int32_t, &msg);
	data->ctrl_box_type	= alx_ur_parse_pkg_elem__(int32_t, &msg);
	data->robot_type	= alx_ur_parse_pkg_elem__(int32_t, &msg);
	data->robot_subtype	= alx_ur_parse_pkg_elem__(int32_t, &msg);
}

static
void	parse_rspkg_force_mode_data	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Force_Mode_Data	*data	= &ur->state.force;

	if (ur->version.v.major == 1  &&  ur->version.v.minor < 8)
		return;

	data->f.x	= alx_ur_parse_pkg_elem__(double, &msg);
	data->f.y	= alx_ur_parse_pkg_elem__(double, &msg);
	data->f.z	= alx_ur_parse_pkg_elem__(double, &msg);
	data->f.rx	= alx_ur_parse_pkg_elem__(double, &msg);
	data->f.ry	= alx_ur_parse_pkg_elem__(double, &msg);
	data->f.rz	= alx_ur_parse_pkg_elem__(double, &msg);
	data->dexterity	= alx_ur_parse_pkg_elem__(double, &msg);
}

static
void	parse_rspkg_additional_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Additional_Info	*data	= &ur->state.additional;

	if (ur->version.v.major == 1  &&  ur->version.v.minor < 8)
		return;

	data->tp_button_state		= alx_ur_parse_pkg_elem__(uint8_t, &msg);
	data->freedrive_button_enabled	= alx_ur_parse_pkg_elem__(bool, &msg);

	if (ur->version.v.major < 3)
		return;
	if (ur->version.v.major == 3  &&  ur->version.v.minor < 2)
		return;

	data->io_enabled_freedrive	= alx_ur_parse_pkg_elem__(bool, &msg);

	if (ur->version.v.major == 3  &&  ur->version.v.minor < 11)
		return;

	data->_reserved	= alx_ur_parse_pkg_elem__(uint8_t, &msg);
}

static
void	parse_rspkg_calib_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Calib_Data	*data	= &ur->state._calib;

	if (ur->version.v.major < 3)
		return;
	if (ur->version.v.major == 3  &&  ur->version.v.minor < 6)
		return;

	data->f.x	= alx_ur_parse_pkg_elem__(double, &msg);
	data->f.y	= alx_ur_parse_pkg_elem__(double, &msg);
	data->f.z	= alx_ur_parse_pkg_elem__(double, &msg);
	data->f.rx	= alx_ur_parse_pkg_elem__(double, &msg);
	data->f.ry	= alx_ur_parse_pkg_elem__(double, &msg);
	data->f.rz	= alx_ur_parse_pkg_elem__(double, &msg);
}

static
void	parse_rspkg_safety_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Safety_Data	*data	= &ur->state._safety;

	ALX_UNUSED(msg);
	ALX_UNUSED(data);
	return;
}

static
void	parse_rspkg_tool_comm_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Tool_Comm_Info	*data	= &ur->state.tool_comm;

	if (ur->version.v.major < 5)
		return;

	data->tool_comm_enabled	= alx_ur_parse_pkg_elem__(bool, &msg);
	data->baud_rate		= alx_ur_parse_pkg_elem__(int32_t, &msg);
	data->parity		= alx_ur_parse_pkg_elem__(int32_t, &msg);
	data->stop_bits		= alx_ur_parse_pkg_elem__(int32_t, &msg);
	data->RX_idle_chars	= alx_ur_parse_pkg_elem__(float, &msg);
	data->TX_idle_chars	= alx_ur_parse_pkg_elem__(float, &msg);
}

static
void	parse_rspkg_tool_mode_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Tool_Mode_Info	*data	= &ur->state.tool_mode;

	if (ur->version.v.major < 5)
		return;
	if (ur->version.v.major == 5  &&  ur->version.v.minor < 2)
		return;

	data->output_mode	= alx_ur_parse_pkg_elem__(uint8_t, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->DO_mode); i++)
		data->DO_mode[i]	= alx_ur_parse_pkg_elem__(uint8_t, &msg);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
