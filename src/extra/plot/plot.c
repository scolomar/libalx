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
#include "libalx/extra/plot/plot.h"

#include <stddef.h>

#include "libalx/extra/plot/core.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
static
const char *plot__cmd__		(const struct Alx_Gnuplot *gnuplot);
static
const char *plot__title__	(const char *title);
static
int	plot__begin__		(const struct Alx_Gnuplot *restrict gnuplot,
				 const char *restrict title);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	alx_gnuplot_reset_plot		(struct Alx_Gnuplot *gnuplot)
{
	gnuplot->nplots	= 0;
}

int	alx_gnuplot_plot_y		(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t size,
					 const double y[static restrict size],
					 const char *title)
{

	if (plot__begin__(gnuplot, title))
		return	-1;

	for (ptrdiff_t x = 0; x < size; x++) {
		if (alx_gnuplot_printf(gnuplot, "%11le\n", y[x]))
			return	-1;
	}
	if (alx_gnuplot_cmd(gnuplot, "e"))
		return	-1;

	gnuplot->nplots++;
	return	0;
}

int	alx_gnuplot_plot_xy		(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t size,
					 const double x[static restrict size],
					 const double y[static restrict size],
					 const char *title)
{

	if (plot__begin__(gnuplot, title))
		return	-1;

	for (ptrdiff_t i = 0; i < size; i++) {
		if (alx_gnuplot_printf(gnuplot, "%11le %11le\n", x[i], y[i]))
			return	-1;
	}
	if (alx_gnuplot_cmd(gnuplot, "e"))
		return	-1;

	gnuplot->nplots++;
	return	0;
}

int	alx_gnuplot_plot_slope		(struct Alx_Gnuplot *restrict gnuplot,
					 double a, double b,
					 const char *title)
{
	const char *cmd;

	cmd	= plot__cmd__(gnuplot);
	title	= plot__title__(title);

	if (alx_gnuplot_cmd(gnuplot, "%s %11le * x + %11le title \"%s\" with %s",
					cmd, a, b, title, gnuplot->style))
		return	-1;

	gnuplot->nplots++;
	return	0;
}

int	alx_gnuplot_plot_equation	(struct Alx_Gnuplot *restrict gnuplot,
					 const char *equation,
					 const char *title)
{
	const char *cmd;

	cmd	= plot__cmd__(gnuplot);
	title	= plot__title__(title);

	if (alx_gnuplot_cmd(gnuplot, "%s %s title \"%s\" with %s",
					cmd, equation, title, gnuplot->style))
		return	-1;

	gnuplot->nplots++;
	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
const char *plot__cmd__		(const struct Alx_Gnuplot *gnuplot)
{
	static const char *const plot	= "plot";
	static const char *const replot	= "replot";

	if (gnuplot->nplots  &&  !gnuplot->multi)
		return	replot;
	return	plot;
}

static
const char *plot__title__	(const char *title)
{
	static const char *const none	= "(none)";

	if (!title)
		return	none;
	return	title;
}

static
int	plot__begin__		(const struct Alx_Gnuplot *restrict gnuplot,
				 const char *restrict title)
{

	if (gnuplot->nplots)
		return	-1;
	title	= plot__title__(title);

	if (alx_gnuplot_printf(gnuplot, "plot '-' title \"%s\" with %s\n",
						title, gnuplot->style))
		return	-1;

	return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
