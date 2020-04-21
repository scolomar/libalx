/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/alloc/reallocarrayf.h"

#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "libalx/base/assert/stddef.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/
alx_Static_assert_size_ptrdiff();


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
void	*alx_reallocarrayf	(void *ptr, ptrdiff_t nmemb, size_t size)
{

	if (!nmemb || !size)
		goto zero;
	if (nmemb < 0)
		goto ovf;
	if ((size_t)nmemb  >  (SIZE_MAX / size))
		goto ovf;

	return	reallocf(ptr, (size_t)nmemb * size);
ovf:
	errno	= ENOMEM;
zero:
	free(ptr);
	return	NULL;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_WEAK_DEF(reallocarrayf, alx_reallocarrayf);
#endif


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
