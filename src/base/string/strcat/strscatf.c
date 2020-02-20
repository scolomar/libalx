/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/string/strcat/strscatf.h"

#include <errno.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>

#include "libalx/base/stdio/printf/snprintfs.h"


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
ptrdiff_t alx_strscatf		(ptrdiff_t size,
				 char dest[static restrict size],
				 const char *restrict format, ...)
{
	va_list		ap;
	ptrdiff_t	len;

	va_start(ap, format);
	len	= alx_vstrscatf(size, dest, format, ap);
	va_end(ap);

	return	len;
}

ptrdiff_t alx_vstrscatf		(ptrdiff_t size,
				 char dest[static restrict size],
				 const char *restrict format, va_list ap)
{
	ptrdiff_t	dlen;
	ptrdiff_t	slen;

	if (size <= 0)
		return	-E2BIG;

	dlen	= strnlen(dest, size);
	if (dlen == size)
		goto err;

	if (alx_snprintfs(dest + dlen, &slen, size - dlen, format, ap))
		goto err;

	return	dlen + slen;
err:
	dest[dlen - 1] = '\0';
	return	-1;

}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
