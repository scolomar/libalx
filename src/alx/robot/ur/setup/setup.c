/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/robot/ur/setup/setup.h"

#include <stdio.h>

#include "libalx/alx/robot/ur/core/core.h"
#include "libalx/alx/robot/ur/core/msg.h"
#include "libalx/alx/robot/ur/pose/pose.h"
#include "libalx/base/compiler/size.h"


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
int	alx_ur_set_tcp	(struct Alx_UR *restrict ur,
			 const struct Alx_UR_Pose *restrict tcp)
{
	char	pos_tcp[BUFSIZ];

	if (tcp->type != ALX_UR_POSE_XYZ)
		return	-1;

	if (alx_ur_sprintf_pose(ARRAY_SIZE(pos_tcp), pos_tcp, tcp))
		return	-1;
	if (alx_ur_cmd(ur, "set_tcp(%s);", pos_tcp))
		return	-1;
	if (alx_ur_recv(ur))
		return	-1;
	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/