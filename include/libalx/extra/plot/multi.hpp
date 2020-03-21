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
#pragma once	/* libalx/extra/plot/multi.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>

#include "libalx/base/compiler/restrict.hpp"
#include "libalx/extra/plot/core.hpp"


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
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull(1)]]
int	alx_gnuplot_set_multiplot	(struct Alx_Gnuplot *restrict gnuplot,
					 const char *restrict opt);
[[gnu::nonnull]]
int	alx_gnuplot_unset_multiplot	(struct Alx_Gnuplot *gnuplot);

[[gnu::nonnull(1, 4)]]
int	alx_gnuplot_plot_multi_y	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double *restrict y/*[n][size]*/,
					 const char *restrict title/*[n]*/);
[[gnu::nonnull(1, 4, 5)]]
int	alx_gnuplot_plot_x_multi_y	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double *restrict x/*[size]*/,
					 const double *restrict y/*[n][size]*/,
					 const char *restrict title/*[n]*/);
[[gnu::nonnull(1, 4, 5)]]
int	alx_gnuplot_plot_multi_xy	(struct Alx_Gnuplot *restrict gnuplot,
					 ptrdiff_t n,
					 ptrdiff_t size,
					 const double *restrict x/*[n][size]*/,
					 const double *restrict y/*[n][size]*/,
					 const char *restrict title/*[n]*/);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace plot {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace plot */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
