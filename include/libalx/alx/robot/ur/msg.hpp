/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/robot/ur/msg.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/pose.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
struct	Robot_Mode {
	uint64_t	timestamp;
	bool		is_connected;
	bool		is_enabled;
	bool		is_power_on;
	bool		is_emergency_stopped;
	bool		is_protective_stopped;
	bool		is_running;
	bool		is_paused;
	uint8_t		robot_mode;
	uint8_t		control_mode;
	double		target_speed_fraction;
	double		speed_scaling;
	double		target_speed_fraction_limit;
	unsigned char	_reserved;
};

struct	Alx_UR_Joint_Data {
	struct Alx_UR_Joints	q_actual;
	struct Alx_UR_Joints	q_target;
	struct Alx_UR_Joints	qd_actual;
	float		i_actual;
	float		v_actual;
	float		t_motor;
	float		_t_micro;
	uint8_t		mode;
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
	struct	Europmap {
		bool		iface_installed;
		uint32_t	in_bits;
		uint32_t	out_bits;
		float		voltage;
		float		current;
	};

	uint32_t	DI_bits;
	uint32_t	DO_bits;
	uint8_t		AI_range[2];
	double		AI[2];
	int8_t		AO_domain[2];
	double		AO[2];
	float		MB_temp;
	float		robot_voltage;
	float		robot_current;
	float		MB_IO_current;
	uint8_t		safety_mode;
	uint8_t		in_reduced_mode;
	struct Euromap	euromap;
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
	struct	Joint {
		uint32_t	chksum;
		double		DH_theta;
		double		DH_a;
		double		Dh_d;
		double		Dh_alpha;
	};

	struct Joint	joint[6];
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
	};

	struct Joint	joint[6];
	double		v_joint_default;
	double		a_joint_default;
	double		v_tool_default;
	double		a_tool_default;
	double		eq_radius;
	int32_t		mb_rev;
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
	bool	freedrive_button_enabled;
	bool	io_enabled_freedrive;
	uint8_t	_reserved;
};

struct	Alx_UR_Calib_Data {
	struct Alx_UR_Coord	f;
};

struct	Alx_UR_Safety_Data {
};

struct	Alx_UR_Tool_Comm_Info {
	bool	tool_comm_enabled;
	int32_t	baud_rate;
	int32_t	parity;
	int32_t	stop_bits;
	float	RX_idle_chars;
	float	TX_idle_chars;
};

struct	Alx_UR_Tool_Mode_Info {
	uint8_t	output_mode;
	uint8_t	DO_mode[2];
};

struct	Alx_UR_Robot_State {
	struct Alx_UR_Robot_Mode_Data	robot_mode;
	struct Alx_UR_Joint_Data	joint;
	struct Alx_UR_Tool_Data		tool_data;
	struct Alx_UR_MB_Data		mb_data;
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


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_halt	(const struct Alx_UR *restrict ur,
			 int usleep_after);

[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movej	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movej_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose_rel,
			 int usleep_after);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movel	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose,
			 int usleep_after);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movel_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict pose_rel,
			 int usleep_after);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movec	(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict via,
			 const struct Alx_UR_Pose *restrict to,
			 int usleep_after);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_ur_movec_rel(const struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict via,
			 const struct Alx_UR_Pose *restrict to,
			 int usleep_after);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace UR {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace UR */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
