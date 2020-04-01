/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/io.h"

#include <stdbool.h>
#include <stddef.h>
#include <time.h>

#include "libalx/alx/robot/ur/core.h"
#include "libalx/alx/robot/ur/msg.h"
#include "libalx/base/stdint/mask/bit.h"
#include "libalx/base/string/strbool/strbool.h"
#include "libalx/base/time/gettime.h"


/******************************************************************************
 ******* macros ***************************************************************
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
int	alx_ur_set_Dout	(struct Alx_UR *ur, ptrdiff_t idx, bool state,
			 double timeout)
{
	bool		actual_state;
	double		time;
	struct timespec	tm;

	clock_gettime(CLOCK_REALTIME, &tm);

	if (alx_ur_cmd(ur, 0, "set_digital_out(%ti, %s)",
						idx, alx_strBool[!!state]))
		return	-1;

	do {
		if (alx_ur_recv(ur))
			return	-1;
		actual_state	= BIT_READ(ur->state.mb.DO_bits, idx);
		time	= alx_clock_gettime_diff_ms(CLOCK_REALTIME, &tm);
		if (time >= timeout * 1000.0)
			return	-1;
	} while (actual_state != state);

	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
