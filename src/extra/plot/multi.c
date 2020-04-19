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
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/plot/multi.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "libalx/extra/plot/core.h"



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
const char *multi__cmd__	(const struct Alx_Gnuplot *gnuplot);
static
const char *multi__title__	(const char *title[restrict], ptrdiff_t i);
static
int	multi__begin__		(const struct Alx_Gnuplot *restrict gnuplot,
				 ptrdiff_t n,
				 const char *title[static restrict n]);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_gnuplot_set_multiplot	(struct Alx_Gnuplot *restrict gnuplot,
					 const char *restrict opt)
{

	if (gnuplot->multi)
		return	-1;
	gnuplot->multi	= true;

	if (alx_gnuplot_printf(gnuplot, "set multiplot"))
		return	-1;
	if (opt) {
		if (alx_gnuplot_printf(gnuplot, " %s", opt))
			return	-1;
	}
	return	alx_gnuplot_cmd(gnuplot, " ");
}

int	alx_gnuplot_unset_multiplot	(struct Alx_Gnuplot *gnuplot)
{

	if (!gnuplot->multi)
		return	-1;
	gnuplot->multi	= false;

	return	alx_gnuplot_cmd(gnuplot, "unset multiplot");
}

int	alx_gnuplot_plot_multi_y	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double y[static restrict n][size],
					 const char *title[static restrict n])
{

	if (multi__begin__(gnuplot, n, title))
		return	-1;

	for (ptrdiff_t i = 0; i < n; i++) {
		for (ptrdiff_t x = 0; x < size; x++) {
			if (alx_gnuplot_printf(gnuplot, "%11le\n", y[i][x]))
				return	-1;
		}
		if (alx_gnuplot_cmd(gnuplot, "e"))
			return	-1;
	}

	gnuplot->nplots	+= n;
	return	0;
}

int	alx_gnuplot_plot_x_multi_y	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double x[static restrict size],
					 const double y[static restrict n][size],
					 const char *title[static restrict n])
{

	if (multi__begin__(gnuplot, n, title))
		return	-1;

	for (ptrdiff_t i = 0; i < n; i++) {
		for (ptrdiff_t z = 0; z < size; z++) {
			if (alx_gnuplot_printf(gnuplot, "%11le %11le\n",
							x[z], y[i][z]))
				return	-1;
		}
		if (alx_gnuplot_cmd(gnuplot, "e"))
			return	-1;
	}

	gnuplot->nplots	+= n;
	return	0;
}

int	alx_gnuplot_plot_multi_xy	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double x[static restrict n][size],
					 const double y[static restrict n][size],
					 const char *title[static restrict n])
{

	if (multi__begin__(gnuplot, n, title))
		return	-1;

	for (ptrdiff_t i = 0; i < n; i++) {
		for (ptrdiff_t z = 0; z < size; z++) {
			if (alx_gnuplot_printf(gnuplot, "%11le %11le\n",
							x[i][z], y[i][z]))
				return	-1;
		}
		if (alx_gnuplot_cmd(gnuplot, "e"))
			return	-1;
	}

	gnuplot->nplots	+= n;
	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
const char *multi__cmd__	(const struct Alx_Gnuplot *gnuplot)
{
	static const char plot[]	= "plot";
	static const char replot[]	= "replot";

	if (gnuplot->nplots  &&  !gnuplot->multi)
		return	replot;
	return	plot;
}

static
const char *multi__title__	(const char *title[restrict], ptrdiff_t i)
{
	static const char none[]	= "(none)";

	if (!title)
		return	none;
	return	title[i];
}

static
int	multi__begin__		(const struct Alx_Gnuplot *restrict gnuplot,
				 ptrdiff_t n,
				 const char *title[static restrict n])
{
	const char *cmd;
	const char *t;

	if (n <= 0)
		return	-1;

	cmd	= multi__cmd__(gnuplot);	/* XXX: May be a bug; test */
	t	= multi__title__(title, 0);
	if (alx_gnuplot_printf(gnuplot, "%s '-' title \"%s\" with %s",
							cmd, t, gnuplot->style))
		return	-1;

	for (ptrdiff_t i = 0; i < n; i++) {
		t	= multi__title__(title, i);
		if (alx_gnuplot_printf(gnuplot, ", '-' title \"%s\" with %s",
							t, gnuplot->style))
			return	-1;
	}
	return	alx_gnuplot_cmd(gnuplot, " ");
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
