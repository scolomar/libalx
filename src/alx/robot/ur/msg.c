/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/msg.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include <sys/types.h>
#include <sys/socket.h>

#include "libalx/alx/robot/ur/core.h"
#include "libalx/base/compiler/size.h"
#include "libalx/base/compiler/unused.h"
#include "libalx/base/sys/socket/msghdr.h"
#include "libalx/base/sys/socket/timestamp.h"
#include "libalx/base/time/timespec.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define parse_pkg_elem(type, msg)	(				\
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
 ******* enum / struct / union ************************************************
 ******************************************************************************/
enum	Alx_UR_Msg_Type {
	MSG_TYPE_ROBOT_STATE	= 16,
	MSG_TYPE_ROBOT_MSG	= 20
};

struct	Alx_UR_Msg_Hdr {
	int32_t	sz;
	uint8_t	type;
};

struct	Alx_UR_Robot_State_Pkg_Hdr {
	int32_t	sz;
	uint8_t	type;
};

struct	Alx_UR_Robot_Msg_Hdr {
	uint64_t	timestamp;
	char		source;
	int8_t		type;
};


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
static
void	parse_msg_robot_state		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz],
					 const struct timespec *restrict ts);
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
int	alx_ur_recv			(struct Alx_UR *ur)
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
		parse_msg_robot_state(ur, ARRAY_SIZE(buf), buf, &ts);
		return	0;
	case MSG_TYPE_ROBOT_MSG:
// TODO		parse_msg_robot_msg(ur, ARRAY_SIZE(buf), buf);
		return	0;
	default:
		return	-1;	/* Unrecignized msg */
	}
}

int	alx_ur_robot_state_update	(struct Alx_UR *ur)
{
	int64_t		time_ms;
	struct timespec	start;

	clock_gettime(CLOCK_REALTIME, &start);

	do {
		if (alx_ur_recv(ur))
			return	-1;
		time_ms	= alx_timespec_diff_ms(&start, &ur->state.timestamp);
	} while (time_ms < ROBOT_UPDATE_PERIOD_MS);
	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
void	parse_msg_robot_state		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz],
					 const struct timespec *restrict ts)
{
	struct Alx_UR_Robot_State_Pkg_Hdr	hdr;

	ur->state.timestamp	= *ts;

	while (sz > 0) {
		memcpy(&hdr, msg, sizeof(hdr));
		msg	+= sizeof(hdr);
		sz	-= sizeof(hdr);

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

static
void	parse_rspkg_robot_mode_data	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Robot_Mode_Data	*data	= &ur->state.robot_mode;

	data->timestamp			= parse_pkg_elem(uint64_t, &msg);
	data->is_connected		= parse_pkg_elem(bool, &msg);
	data->is_enabled		= parse_pkg_elem(bool, &msg);
	data->is_power_on		= parse_pkg_elem(bool, &msg);
	data->is_emergency_stopped	= parse_pkg_elem(bool, &msg);
	data->is_protective_stopped	= parse_pkg_elem(bool, &msg);
	data->is_running		= parse_pkg_elem(bool, &msg);
	data->is_paused			= parse_pkg_elem(bool, &msg);
	data->robot_mode		= parse_pkg_elem(int8_t, &msg);

	/* Different versions continue differently from here. */
	if (ur->version.v.major < 3) {
		data->target_speed_fraction = parse_pkg_elem(double, &msg);
		return;
	}

	data->ctrl_mode			= parse_pkg_elem(uint8_t, &msg);
	data->target_speed_fraction	= parse_pkg_elem(double, &msg);
	data->speed_scaling		= parse_pkg_elem(double, &msg);

	if (ur->version.v.major == 3  &&  ur->version.v.minor < 2)
		return;

	data->target_speed_fraction_limit = parse_pkg_elem(double, &msg);
}

static
void	parse_rspkg_joint_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Joint_Data	*data	= &ur->state.joint;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->q_actual.j); i++) {
		data->q_actual.j[i]	= parse_pkg_elem(double, &msg);
		data->q_target.j[i]	= parse_pkg_elem(double, &msg);
		data->qd_actual.j[i]	= parse_pkg_elem(double, &msg);
		data->i_actual.j[i]	= parse_pkg_elem(float, &msg);
		data->v_actual.j[i]	= parse_pkg_elem(float, &msg);
		data->t_motor.j[i]	= parse_pkg_elem(float, &msg);
		data->_t_micro.j[i]	= parse_pkg_elem(float, &msg);
		data->mode.j[i]		= parse_pkg_elem(uint8_t, &msg);
	}
}

static
void	parse_rspkg_tool_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Tool_Data	*data	= &ur->state.tool_data;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AI_range); i++)
		data->AI_range[i]	= parse_pkg_elem(uint8_t, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AI); i++)
		data->AI[i]		= parse_pkg_elem(double, &msg);

	data->voltage		= parse_pkg_elem(float, &msg);
	data->output_voltage	= parse_pkg_elem(uint8_t, &msg);
	data->current		= parse_pkg_elem(float, &msg);
	data->temp		= parse_pkg_elem(float, &msg);
	data->mode		= parse_pkg_elem(uint8_t, &msg);
}

static
void	parse_rspkg_mb_data		(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_MB_Data	*data	= &ur->state.mb;

	if (ur->version.v.major < 3) {
		data->DI_bits	= parse_pkg_elem(uint16_t, &msg);
		data->DO_bits	= parse_pkg_elem(uint16_t, &msg);
	} else {
		data->DI_bits	= parse_pkg_elem(uint32_t, &msg);
		data->DO_bits	= parse_pkg_elem(uint32_t, &msg);
	}
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AI_range); i++)
		data->AI_range[i]	= parse_pkg_elem(uint8_t, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AI); i++)
		data->AI[i]		= parse_pkg_elem(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AO_domain); i++)
		data->AO_domain[i]	= parse_pkg_elem(uint8_t, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->AO); i++)
		data->AO[i]		= parse_pkg_elem(double, &msg);

	data->mb_temp		= parse_pkg_elem(float, &msg);
	data->robot_voltage	= parse_pkg_elem(float, &msg);
	data->robot_current	= parse_pkg_elem(float, &msg);
	data->mb_io_current	= parse_pkg_elem(float, &msg);
	data->safety_mode	= parse_pkg_elem(uint8_t, &msg);
	data->in_reduced_mode	= parse_pkg_elem(uint8_t, &msg);

	data->euromap.iface_installed	= parse_pkg_elem(bool, &msg);
	if (data->euromap.iface_installed) {
		data->euromap.in_bits	= parse_pkg_elem(uint32_t, &msg);
		data->euromap.out_bits	= parse_pkg_elem(uint32_t, &msg);
		if (ur->version.v.major < 3) {
			data->euromap.voltage = parse_pkg_elem(uint16_t, &msg);
			data->euromap.current = parse_pkg_elem(uint16_t, &msg);
		} else {
			data->euromap.voltage = parse_pkg_elem(float, &msg);
			data->euromap.current = parse_pkg_elem(float, &msg);
		}
	}

	if (ur->version.v.major < 3)
		return;

	data->_reserved_0	= parse_pkg_elem(uint32_t, &msg);

	if (ur->version.v.major == 3  &&  ur->version.v.minor < 2)
		return;

	data->op_mode_sel_in		= parse_pkg_elem(uint8_t, &msg);
	data->three_pos_enabling_dev_in	= parse_pkg_elem(uint8_t, &msg);

	if (ur->version.v.major == 3  &&  ur->version.v.minor < 10)
		return;
	if (ur->version.v.major == 5  &&  ur->version.v.minor < 4)
		return;

	data->_reserved_1	= parse_pkg_elem(uint8_t, &msg);
}

static
void	parse_rspkg_cartesian_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Cartesian_Info	*data	= &ur->state.cartesian;

	data->pos.x	= parse_pkg_elem(double, &msg);
	data->pos.y	= parse_pkg_elem(double, &msg);
	data->pos.z	= parse_pkg_elem(double, &msg);
	data->pos.rx	= parse_pkg_elem(double, &msg);
	data->pos.ry	= parse_pkg_elem(double, &msg);
	data->pos.rz	= parse_pkg_elem(double, &msg);

	if (ur->version.v.major < 3)
		return;
	if (ur->version.v.major == 3  &&  ur->version.v.minor < 1)
		return;

	data->tcp_offset.x	= parse_pkg_elem(double, &msg);
	data->tcp_offset.y	= parse_pkg_elem(double, &msg);
	data->tcp_offset.z	= parse_pkg_elem(double, &msg);
	data->tcp_offset.rx	= parse_pkg_elem(double, &msg);
	data->tcp_offset.ry	= parse_pkg_elem(double, &msg);
	data->tcp_offset.rz	= parse_pkg_elem(double, &msg);
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
		data->joint[i].chksum	= parse_pkg_elem(uint32_t, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].DH_theta	= parse_pkg_elem(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].DH_a	= parse_pkg_elem(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].Dh_d	= parse_pkg_elem(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].Dh_alpha	= parse_pkg_elem(double, &msg);

	data->calib	= parse_pkg_elem(uint32_t, &msg);
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
		data->joint[i].min_limit = parse_pkg_elem(double, &msg);
		data->joint[i].max_limit = parse_pkg_elem(double, &msg);
	}
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++) {
		data->joint[i].max_speed = parse_pkg_elem(double, &msg);
		data->joint[i].max_accel = parse_pkg_elem(double, &msg);
	}
	data->v_joint_default	= parse_pkg_elem(double, &msg);
	data->a_joint_default	= parse_pkg_elem(double, &msg);
	data->v_tool_default	= parse_pkg_elem(double, &msg);
	data->a_tool_default	= parse_pkg_elem(double, &msg);
	data->eq_radius		= parse_pkg_elem(double, &msg);

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].DH_theta	= parse_pkg_elem(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].DH_a	= parse_pkg_elem(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].Dh_d	= parse_pkg_elem(double, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->joint); i++)
		data->joint[i].Dh_alpha	= parse_pkg_elem(double, &msg);

	data->mb_version	= parse_pkg_elem(int32_t, &msg);
	data->ctrl_box_type	= parse_pkg_elem(int32_t, &msg);
	data->robot_type	= parse_pkg_elem(int32_t, &msg);
	data->robot_subtype	= parse_pkg_elem(int32_t, &msg);
}

static
void	parse_rspkg_force_mode_data	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Force_Mode_Data	*data	= &ur->state.force;

	if (ur->version.v.major == 1  &&  ur->version.v.minor < 8)
		return;

	data->f.x	= parse_pkg_elem(double, &msg);
	data->f.y	= parse_pkg_elem(double, &msg);
	data->f.z	= parse_pkg_elem(double, &msg);
	data->f.rx	= parse_pkg_elem(double, &msg);
	data->f.ry	= parse_pkg_elem(double, &msg);
	data->f.rz	= parse_pkg_elem(double, &msg);
	data->dexterity	= parse_pkg_elem(double, &msg);
}

static
void	parse_rspkg_additional_info	(struct Alx_UR *restrict ur,
					 ssize_t sz,
					 const unsigned char msg[static restrict sz])
{
	struct Alx_UR_Additional_Info	*data	= &ur->state.additional;

	if (ur->version.v.major == 1  &&  ur->version.v.minor < 8)
		return;

	data->tp_button_state		= parse_pkg_elem(uint8_t, &msg);
	data->freedrive_button_enabled	= parse_pkg_elem(bool, &msg);

	if (ur->version.v.major < 3)
		return;
	if (ur->version.v.major == 3  &&  ur->version.v.minor < 2)
		return;

	data->io_enabled_freedrive	= parse_pkg_elem(bool, &msg);

	if (ur->version.v.major == 3  &&  ur->version.v.minor < 11)
		return;

	data->_reserved	= parse_pkg_elem(uint8_t, &msg);
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

	data->f.x	= parse_pkg_elem(double, &msg);
	data->f.y	= parse_pkg_elem(double, &msg);
	data->f.z	= parse_pkg_elem(double, &msg);
	data->f.rx	= parse_pkg_elem(double, &msg);
	data->f.ry	= parse_pkg_elem(double, &msg);
	data->f.rz	= parse_pkg_elem(double, &msg);
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

	data->tool_comm_enabled	= parse_pkg_elem(bool, &msg);
	data->baud_rate		= parse_pkg_elem(int32_t, &msg);
	data->parity		= parse_pkg_elem(int32_t, &msg);
	data->stop_bits		= parse_pkg_elem(int32_t, &msg);
	data->RX_idle_chars	= parse_pkg_elem(float, &msg);
	data->TX_idle_chars	= parse_pkg_elem(float, &msg);
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

	data->output_mode	= parse_pkg_elem(uint8_t, &msg);
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(data->DO_mode); i++)
		data->DO_mode[i]	= parse_pkg_elem(uint8_t, &msg);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
