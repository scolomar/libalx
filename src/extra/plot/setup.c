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
#include "libalx/extra/plot/setup.h"

#include "libalx/base/compiler/size.h"
#include "libalx/extra/plot/core.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
static const char *const styles[/*ALX_GNUPLOT_STYLES*/]	= {
	[ALX_GNUPLOT_STYLE_BOXERRORBARS]	= "boxerrorbars",
	[ALX_GNUPLOT_STYLE_BOXES]		= "boxes",
	[ALX_GNUPLOT_STYLE_DOTS]		= "dots",
	[ALX_GNUPLOT_STYLE_ERRORBARS]		= "errorbars",
	[ALX_GNUPLOT_STYLE_IMPULSES]		= "impulses",
	[ALX_GNUPLOT_STYLE_LINES]		= "lines",
	[ALX_GNUPLOT_STYLE_LINESPOINTS]		= "linespoints",
	[ALX_GNUPLOT_STYLE_POINTS]		= "points",
	[ALX_GNUPLOT_STYLE_STEPS]		= "steps"
};


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_gnuplot_set_style		(struct Alx_Gnuplot *gnuplot, int style)
{

	if (style < 0  ||  style >= ARRAY_SSIZE(styles))
		return	-1;
	gnuplot->style	= styles[style];
	return	0;
}

int	alx_gnuplot_set_xlabel		(struct Alx_Gnuplot *restrict gnuplot,
					 const char *restrict label)
{
	return	alx_gnuplot_cmd(gnuplot, "set xlabel \"%s\"", label);
}

int	alx_gnuplot_set_ylabel		(struct Alx_Gnuplot *restrict gnuplot,
					 const char *restrict label)
{
	return	alx_gnuplot_cmd(gnuplot, "set ylabel \"%s\"", label);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

