/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/string/strchr/strncasechr.h"

#include <ctype.h>
#include <stddef.h>
#include <string.h>


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
ptrdiff_t alx_strncasechr	(ptrdiff_t size, const char str[restrict size],
				 char c)
{
	const ptrdiff_t	len	= strnlen(str, size);
	const char	c_lower	= tolower((unsigned char)c);
	char		s_lower;

	for (ptrdiff_t i = 0; i < len; i++) {
		s_lower	= tolower((unsigned char)str[i]);
		if (c_lower == s_lower)
			return	i;
		if (!s_lower)
			return	-1;
	}

	return	-1;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEFINITION(strncasechr, alx_strncasechr);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
