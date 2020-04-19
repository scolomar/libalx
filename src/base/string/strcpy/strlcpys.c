/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/string/strcpy/strlcpys.h"

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
int	alx_strlcpys		(char dest[restrict /*size*/],
				 const char src[restrict /*size*/],
				 ptrdiff_t size, ptrdiff_t *restrict len)
{
	ptrdiff_t	l;

	if (size <= 0)
		return	-1;

	l	= strlcpy(dest, src, size);
	if (len)
		*len	= l;

	if (l >= size)
		return	1;

	return	0;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEFINITION(strlcpys, alx_strlcpys);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
