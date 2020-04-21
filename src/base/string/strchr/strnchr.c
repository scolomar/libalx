/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/string/strchr/strnchr.h"

#include <stddef.h>


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
extern
ptrdiff_t alx_strnchr		(ptrdiff_t size,
				 const char str[static restrict size],
				 char c);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(strnchr, alx_strnchr);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
