/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/io/io.h"

#include <stdbool.h>
#include <stddef.h>
#include <time.h>

#include "libalx/base/stdint/mask/bit.h"
#include "libalx/base/string/strbool/strbool.h"
#include "libalx/base/time/gettime.h"

#include "libalx/alx/robot/ur/core/core.h"
#include "libalx/alx/robot/ur/core/msg/robot_state.h"


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
int	alx_ur_set_Dout	(struct Alx_UR *ur, ptrdiff_t i, bool state,
			 double timeout)
{
	bool		actual_state;
	double		time;
	struct timespec	tm;

	clock_gettime(CLOCK_REALTIME, &tm);

	if (alx_ur_cmd(ur, "set_digital_out(%ti, %s)", i, alx_strBool[!!state]))
		return	-1;

	do {
		if (alx_ur_robot_state_update(ur))
			return	-1;
		actual_state	= BIT_READ(ur->state.mb.DO_bits, i);
		time	= alx_clock_gettime_diff_ms(CLOCK_REALTIME, &tm);
		if (time >= timeout * 1000.0)
			return	-1;
	} while (actual_state != state);

	return	0;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(ur_set_Dout, alx_ur_set_Dout);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
