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
#pragma once	/* libalx/extra/plot/core.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdarg>
#include <cstdbool>
#include <cstdio>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern "C" {


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
struct	Alx_Gnuplot {
	FILE	*pipe;
	int	nplots;
	char	style[BUFSIZ];
	bool	multi;
};


/******************************************************************************
 ******* C prototypes *********************************************************
 ******************************************************************************/
[[gnu::nonnull]]
int	alx_gnuplot_init	(struct Alx_Gnuplot **gnuplot);
int	alx_gnuplot_deinit	(struct Alx_Gnuplot *gnuplot);
[[gnu::nonnull]] [[gnu::format(printf, 2, 3)]]
int	alx_gnuplot_cmd		(const struct Alx_Gnuplot *restrict gnuplot,
				 const char *restrict fmt, ...);
[[gnu::nonnull]] [[gnu::format(printf, 2, 3)]]
int	alx_gnuplot_printf	(const struct Alx_Gnuplot *restrict gnuplot,
				 const char *restrict fmt, ...);
[[gnu::nonnull]] [[gnu::format(printf, 2, 0)]]
int	alx_gnuplot_vprintf	(const struct Alx_Gnuplot *restrict gnuplot,
				 const char *restrict fmt, va_list ap);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
#define Gnuplot			      Alx_Gnuplot
#define gnuplot_init(gnuplot)	      alx_gnuplot_init(gnuplot)
#define gnuplot_deinit(gnuplot)	      alx_gnuplot_deinit(gnuplot)
#define gnuplot_cmd(gp, fmt, ...)     alx_gnuplot_cmd(gp, fmt, ##__VA_ARGS__)
#define gnuplot_printf(gp, fmt, ...)  alx_gnuplot_printf(gp, fmt, ##__VA_ARGS__)
#define gnuplot_vprintf(gp, fmt, ap)  alx_gnuplot_vprintf(gp, fmt, ap)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
}	/* extern "C" */


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace plot {


/******************************************************************************
 ******* enum *****************************************************************
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
