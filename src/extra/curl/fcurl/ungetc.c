/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	BSD-2-Clause			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/curl/fcurl/ungetc.h"

#include <errno.h>
#include <stdio.h>

#include "libalx/alx/data-structures/dyn-buffer.h"
#include "libalx/extra/curl/fcurl/URL_FILE.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
static
int	url_ungetc__	(int c, ALX_URL_FILE *restrict stream);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_url_ungetc	(int c, ALX_URL_FILE *restrict stream)
{

	if (c == EOF)
		return	EOF;

	switch (stream->type) {
	case ALX_URL_CFTYPE_FILE:
		return	ungetc(c, stream->handle.file);
	case ALX_URL_CFTYPE_CURL:
		return	url_ungetc__(c, stream);
	default:
		errno	= EBADF;
		return	EOF;
	}
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	url_ungetc__	(int c, ALX_URL_FILE *restrict stream)
{
	unsigned char	ch;

	ch	= c;
	if (alx_dynbuf_insert(stream->buf, 0, &ch, sizeof(ch)))
		return	EOF;

	return	c;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

