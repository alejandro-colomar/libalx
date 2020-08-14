/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot/ur/core/core.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hxx`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "libalx/base/compiler/attribute.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define NJOINTS			(6)
#define ROBOT_FREQUENCY		(10)
#define ROBOT_UPDATE_PERIOD_MS	(100)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Alx_UR_Robot_State_Pkg_Type {
	ROBOT_STATE_PKG_TYPE_ROBOT_MODE_DATA,
	ROBOT_STATE_PKG_TYPE_JOINT_DATA,
	ROBOT_STATE_PKG_TYPE_TOOL_DATA,
	ROBOT_STATE_PKG_TYPE_MB_DATA,
	ROBOT_STATE_PKG_TYPE_CARTESIAN_INFO,
	ROBOT_STATE_PKG_TYPE_KINEMATICS_INFO,
	ROBOT_STATE_PKG_TYPE_CONFIG_DATA,
	ROBOT_STATE_PKG_TYPE_FORCE_MODE_DATA,
	ROBOT_STATE_PKG_TYPE_ADDITIONAL_INFO,
	ROBOT_STATE_PKG_TYPE_CALIB_DATA,
	ROBOT_STATE_PKG_TYPE_SAFETY_DATA,
	ROBOT_STATE_PKG_TYPE_TOOL_COMM_INFO,
	ROBOT_STATE_PKG_TYPE_TOOL_MODE_INFO
};

enum	Alx_UR_Ctrl_Mode {
	CTRL_MODE_POSITION,
	CTRL_MODE_TEACH,
	CTRL_MODE_FORCE,
	CTRL_MODE_TORQUE
};

enum	Alx_UR_Joint_Mode {
	JOINT_MODE_RESET			= 235,
	JOINT_MODE_SHUTTING_DOWN		= 236,
	JOINT_PART_D_CALIBRATION_MODE_		= 237,
	JOINT_MODE_BACKDRIVE			= 238,
	JOINT_MODE_POWER_OFF			= 239,
	JOINT_MODE_READY_FOR_POWER_OFF		= 240,

	JOINT_MODE_NOT_RESPONDING		= 245,
	JOINT_MODE_MOTOR_INITIALISATION		= 246,
	JOINT_MODE_BOOTING			= 247,
	JOINT_PART_D_CALIBRATION_ERROR_MODE_	= 248,
	JOINT_MODE_BOOTLOADER			= 249,
	JOINT_CALIBRATION_MODE_			= 250,
	JOINT_MODE_VIOLATION			= 251,
	JOINT_MODE_FAULT			= 252,
	JOINT_MODE_RUNNING			= 253,

	JOINT_MODE_IDLE				= 255
};

enum	Alx_UR_Robot_Mode {
	ROBOT_MODE_NO_CONTROLLER	= -1,
	ROBOT_MODE_DISCONNECTED,
	ROBOT_MODE_CONFIRM_SAFETY,
	ROBOT_MODE_BOOTING,
	ROBOT_MODE_POWER_OFF,
	ROBOT_MODE_POWER_ON,
	ROBOT_MODE_IDLE,
	ROBOT_MODE_BACKDRIVE,
	ROBOT_MODE_RUNNING,
	ROBOT_MODE_UPDATING_FIRMWARE
};

enum	Alx_UR_Tool_Mode {
	TOOL_MODE_RESET			= JOINT_MODE_RESET,
	TOOL_MODE_SHUTTING_DOWN		= JOINT_MODE_SHUTTING_DOWN,
	TOOL_MODE_POWER_OFF		= JOINT_MODE_POWER_OFF,
	TOOL_MODE_NOT_RESPONDING	= JOINT_MODE_NOT_RESPONDING,
	TOOL_MODE_BOOTING		= JOINT_MODE_BOOTING,
	TOOL_MODE_BOOTLOADER		= JOINT_MODE_BOOTLOADER,
	TOOL_MODE_FAULT			= JOINT_MODE_FAULT,
	TOOL_MODE_RUNNING		= JOINT_MODE_RUNNING,
	TOOL_MODE_IDLE			= JOINT_MODE_IDLE
};

enum	Alx_UR_Safety_Mode {
	SAFETY_MODE_NORMAL	= 1,
	SAFETY_MODE_REDUCED,
	SAFETY_MODE_PROTECTIVE_STOP,
	SAFETY_MODE_RECOVERY,
	SAFETY_MODE_SAFEGUARD_STOP,
	SAFETY_MODE_SYSTEM_EMERGENCY_STOP,
	SAFETY_MODE_ROBOT_EMERGENCY_STOP,
	SAFETY_MODE_VIOLATION,
	SAFETY_MODE_FAULT,
	SAFETY_MODE_VALIDATE_JOINT_ID,
	SAFETY_MODE_UNDEFINED_SAFETY_MODE
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
struct	Alx_UR_Coord {
	double	x;
	double	y;
	double	z;
	double	rx;
	double	ry;
	double	rz;
};

union	Alx_UR_Joints {
	struct {
		double	base;
		double	shoulder;
		double	elbow;
		double	wrist1;
		double	wrist2;
		double	wrist3;
	};
	double	j[NJOINTS];
};

struct	Alx_UR_Robot_Mode_Data {
	int64_t		timestamp;
	bool		is_connected	:1;
	bool		is_enabled	:1;
	bool		is_power_on	:1;
	bool		is_emergency_stopped	:1;
	bool		is_protective_stopped	:1;
	bool		is_running	:1;
	bool		is_paused	:1;
	int		robot_mode;
	int		ctrl_mode;
	double		target_speed_fraction;
	double		speed_scaling;
	double		target_speed_fraction_limit;
	unsigned char	_reserved;
};

struct	Alx_UR_Joint_Data {
	union Alx_UR_Joints	q_actual;
	union Alx_UR_Joints	q_target;
	union Alx_UR_Joints	qd_actual;
	union Alx_UR_Joints	i_actual;
	union Alx_UR_Joints	v_actual;
	union Alx_UR_Joints	t_motor;
	union Alx_UR_Joints	_t_micro;
	union {
		struct {
			double	base;
			double	shoulder;
			double	elbow;
			double	wrist1;
			double	wrist2;
			double	wrist3;
		};
		int	j[NJOINTS];
	} mode;
};

struct	Alx_UR_Tool_Data {
	uint8_t		AI_range[2];
	double		AI[2];
	float		voltage;
	uint8_t		output_voltage;
	float		current;
	float		temp;
	uint8_t		mode;
};

struct	Alx_UR_MB_Data {

	uint32_t	DI_bits;
	uint32_t	DO_bits;
	uint8_t		AI_range[2];
	double		AI[2];
	int8_t		AO_domain[2];
	double		AO[2];
	float		mb_temp;
	float		robot_voltage;
	float		robot_current;
	float		mb_io_current;
	uint8_t		safety_mode;
	uint8_t		in_reduced_mode;
	struct {
		bool		iface_installed;
		uint32_t	in_bits;
		uint32_t	out_bits;
		float		voltage;
		float		current;
	} euromap;
	uint32_t	_reserved_0;
	uint8_t		op_mode_sel_in;
	uint8_t		three_pos_enabling_dev_in;
	uint8_t		_reserved_1;
};

struct	Alx_UR_Cartesian_Info {
	struct Alx_UR_Coord	pos;
	struct Alx_UR_Coord	tcp_offset;
};

struct	Alx_UR_Kinematics_Info {
	struct {
		uint32_t	chksum;
		double		DH_theta;
		double		DH_a;
		double		Dh_d;
		double		Dh_alpha;
	} joint[NJOINTS];
	uint32_t	calib;
};

struct	Alx_UR_Config_Data {
	struct	Joint {
		double	min_limit;
		double	max_limit;
		double	max_speed;
		double	max_accel;
		double	DH_a;
		double	Dh_d;
		double	Dh_alpha;
		double	DH_theta;
	} joint[NJOINTS];
	double		v_joint_default;
	double		a_joint_default;
	double		v_tool_default;
	double		a_tool_default;
	double		eq_radius;
	int32_t		mb_version;
	int32_t		ctrl_box_type;
	int32_t		robot_type;
	int32_t		robot_subtype;
};

struct	Alx_UR_Force_Mode_Data {
	struct Alx_UR_Coord	f;
	double		dexterity;
};

struct	Alx_UR_Additional_Info {
	uint8_t	tp_button_state;
	bool	freedrive_button_enabled	:1;
	bool	io_enabled_freedrive		:1;
	uint8_t	_reserved;
};

struct	Alx_UR_Calib_Data {
	struct Alx_UR_Coord	f;
};

__extension__
struct	Alx_UR_Safety_Data {
};

struct	Alx_UR_Tool_Comm_Info {
	bool	tool_comm_enabled;
	int32_t	baud_rate;
	int32_t	parity;
	int32_t	stop_bits;
	double	RX_idle_chars;
	double	TX_idle_chars;
};

struct	Alx_UR_Tool_Mode_Info {
	uint8_t	output_mode;
	uint8_t	DO_mode[2];
};

struct	Alx_UR_Robot_State {
	struct timespec			timestamp;
	struct Alx_UR_Robot_Mode_Data	robot_mode;
	struct Alx_UR_Joint_Data	joint;
	struct Alx_UR_Tool_Data		tool_data;
	struct Alx_UR_MB_Data		mb;
	struct Alx_UR_Cartesian_Info	cartesian;
	struct Alx_UR_Kinematics_Info	kinematics;
	struct Alx_UR_Config_Data	config;
	struct Alx_UR_Force_Mode_Data	force;
	struct Alx_UR_Additional_Info	additional;
	struct Alx_UR_Calib_Data	_calib;
	struct Alx_UR_Safety_Data	_safety;
	struct Alx_UR_Tool_Comm_Info	tool_comm;
	struct Alx_UR_Tool_Mode_Info	tool_mode;
};

struct	Alx_UR_Version {
	int8_t	prj_name_sz;
	char	prj_name[BUFSIZ];
	struct {
		uint8_t	major;
		uint8_t	minor;
		int32_t	bugfix;
		int32_t	build;
	} v;
	char	date[BUFSIZ];
};

struct	Alx_UR {
	int				sfd;
	struct Alx_UR_Robot_State	state;
	struct Alx_UR_Version		version;
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_init	(struct Alx_UR **restrict ur,
			 const char *restrict ur_ip);
[[gnu::warn_unused_result]]
int	alx_ur_deinit	(struct Alx_UR *ur);

[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_cmd	(const struct Alx_UR *restrict ur,
			 const char *restrict fmt, ...);

[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_poweroff	(const struct Alx_UR *ur);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(ur_init,		alx_ur_init);
ALX_ALIAS_DECLARATION(ur_deinit,	alx_ur_deinit);
ALX_ALIAS_DECLARATION(ur_cmd,		alx_ur_cmd);
ALX_ALIAS_DECLARATION(ur_poweroff,	alx_ur_poweroff);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
