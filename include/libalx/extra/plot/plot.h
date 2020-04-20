/******************************************************************************
 *	The code given here is all public domain			      *
 ******************************************************************************/


/******************************************************************************
 * Original file:	gnuplot_i.h					      *
 * Original author:	N. Devillard					      *
 * Date:		Sep 1998					      *
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
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/plot/plot.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include "libalx/extra/plot/core.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define gnuplot_reset_plot(gnuplot)					\
			alx_gnuplot_reset_plot(gnuplot)
#define gnuplot_plot_y(gnuplot, size, y, title)				\
			alx_gnuplot_plot_y(gnuplot, size, y, title)
#define gnuplot_plot_xy(gnuplot, size, x, y, title)			\
			alx_gnuplot_plot_xy(gnuplot, size, x, y, title)
#define gnuplot_plot_slope(gnuplot, a, b, title)			\
			alx_gnuplot_plot_slope(gnuplot, a, b, title)
#define gnuplot_plot_equation(gnuplot, equation, title)			\
			alx_gnuplot_plot_equation(gnuplot, equation, title)
#endif


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull))
void	alx_gnuplot_reset_plot		(struct Alx_Gnuplot *gnuplot);
__attribute__((nonnull(1, 3)))
int	alx_gnuplot_plot_y		(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t size,
					 const double y[static restrict size],
					 const char *restrict title);
__attribute__((nonnull(1, 3, 4)))
int	alx_gnuplot_plot_xy		(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t size,
					 const double x[static restrict size],
					 const double y[static restrict size],
					 const char *restrict title);
__attribute__((nonnull(1)))
int	alx_gnuplot_plot_slope		(struct Alx_Gnuplot *restrict gnuplot,
					 double a, double b,
					 const char *restrict title);
__attribute__((nonnull(1)))
int	alx_gnuplot_plot_equation	(struct Alx_Gnuplot *restrict gnuplot,
					 const char *equation,
					 const char *title);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
