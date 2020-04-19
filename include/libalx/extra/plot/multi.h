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
#pragma once	/* libalx/extra/plot/multi.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include "libalx/extra/plot/core.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define gnuplot_set_multiplot(gnuplot, opt)				\
			alx_gnuplot_set_multiplot(gnuplot, opt)
#define gnuplot_unset_multiplot(gnuplot)				\
			alx_gnuplot_unset_multiplot(gnuplot)
#define gnuplot_plot_multi_y(gp, n, size, y, title)			\
			alx_gnuplot_plot_multi_y(gp, n, size, y, title)
#define gnuplot_plot_x_multi_y(gp, n, size, x, y, title)		\
			alx_gnuplot_plot_x_multi_y(gp, n, size, x, y, title)
#define gnuplot_plot_multi_xy(gp, n, size, x, y, title)			\
			alx_gnuplot_plot_multi_xy(gp, n, size, x, y, title)
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
__attribute__((nonnull(1)))
int	alx_gnuplot_set_multiplot	(struct Alx_Gnuplot *restrict gnuplot,
					 const char *restrict opt);
__attribute__((nonnull))
int	alx_gnuplot_unset_multiplot	(struct Alx_Gnuplot *gnuplot);

__attribute__((nonnull(1, 4)))
int	alx_gnuplot_plot_multi_y	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double y[static restrict n][size],
					 const char *title[static restrict n]);
__attribute__((nonnull(1, 4, 5)))
int	alx_gnuplot_plot_x_multi_y	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double x[static restrict size],
					 const double y[static restrict n][size],
					 const char *title[static restrict n]);
__attribute__((nonnull(1, 4, 5)))
int	alx_gnuplot_plot_multi_xy	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double x[static restrict n][size],
					 const double y[static restrict n][size],
					 const char *title[static restrict n]);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
