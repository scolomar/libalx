/******************************************************************************
 *	The code given here is all public domain			      *
 ******************************************************************************/


/******************************************************************************
 * Original file:	gnuplot_i.c					      *
 * Original author:	N. Devillard					      *
 * Date:		1998						      *
 * Site:		< http://ndevilla.free.fr/gnuplot/ >		      *
 * Brief:		C interface to gnuplot				      *
 *									      *
 * gnuplot  is a freely available, command-driven graphical display tool      *
 * for Unix.  It compiles and works quite well on a number of Unix	      *
 * flavours as well as other operating systems.  The following module	      *
 * enables sending display requests to gnuplot through simple C calls.	      *
 ******************************************************************************
 * Modified by:		pingplug					      *
 * Site:		< https://github.com/pingplug/gnuplot_i >	      *
 ******************************************************************************
 * Modified by:		Alejandro Colomar Andrés			      *
 * Date:		2020						      *
 * Site:		< https://github.com/alejandro-colomar/libalx >	      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/plot/core.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "libalx/base/stdlib/alloc/frees.h"
#include "libalx/base/stdlib/alloc/mallocarrays.h"
#include "libalx/extra/plot/setup.h"


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
int	alx_gnuplot_init	(struct Alx_Gnuplot **gnuplot)
{

	if (!getenv("DISPLAY"))
		return	-1;

	if (alx_mallocarrays(gnuplot, 1))
		return	-2;

	(*gnuplot)->nplots	= 0;
	(*gnuplot)->multi	= false;
	alx_gnuplot_set_style(*gnuplot, ALX_GNUPLOT_STYLE_POINTS, NULL);
	(*gnuplot)->pipe	= popen("gnuplot", "w");
	if (!(*gnuplot)->pipe)
		goto err;

	return	0;
err:
	alx_frees(gnuplot);
	return	-3;
}

int	alx_gnuplot_deinit	(struct Alx_Gnuplot *gnuplot)
{

	if (pclose(gnuplot->pipe) < 0)
		return	-1;
	free(gnuplot);
	return	0;
}

int	alx_gnuplot_cmd		(const struct Alx_Gnuplot *restrict gnuplot,
				 const char *restrict fmt, ...)
{
	va_list	ap;
	int	status;

	va_start(ap, fmt);
	status	= alx_gnuplot_vprintf(gnuplot, fmt, ap);
	va_end(ap);

	if (status < 0)
		return	-1;
	if (fputc('\n', gnuplot->pipe) < 0)
		return	-1;
	return	fflush(gnuplot->pipe);
}

int	alx_gnuplot_printf	(const struct Alx_Gnuplot *restrict gnuplot,
				 const char *restrict fmt, ...)
{
	va_list	ap;
	int	status;

	va_start(ap, fmt);
	status	= alx_gnuplot_vprintf(gnuplot, fmt, ap);
	va_end(ap);

	return	status;
}

int	alx_gnuplot_vprintf	(const struct Alx_Gnuplot *restrict gnuplot,
				 const char *restrict fmt, va_list ap)
{

	if (vfprintf(gnuplot->pipe, fmt, ap) < 0)
		return	-1;
	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
