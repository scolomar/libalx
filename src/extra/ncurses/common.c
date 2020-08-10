/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/ncurses/common.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <ncurses.h>


/******************************************************************************
 ******* define ***************************************************************
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
void	alx_ncurses_init	(void)
{

	initscr();
	nonl();
	cbreak();
	noecho();
	keypad(stdscr, true);

	if (has_colors()) {
		start_color();
		use_default_colors();
	}
//	mousemask(BUTTON4_PRESSED | BUTTON2_PRESSED, NULL);
}

void	alx_ncurses_pause	(void)
{

	def_prog_mode();
	endwin();
}

void	alx_ncurses_resume	(void)
{

	fflush(stdout);
	reset_prog_mode();
}

void	alx_ncurses_deinit	(void)
{

	clear();
	refresh();
	endwin();
}

void	alx_ncurses_delwin	(WINDOW *restrict win)
{

	wbkgd(win, 0);
	wclear(win);
	wrefresh(win);
	delwin(win);
}

void	alx_ncurses_title	(WINDOW *restrict win,
				 const char *restrict title)
{
	int	w;
	int	len;

	/* Size of window */
	w	= getmaxx(win);

	/* Length of title */
	len	= strlen(title);

	/* Print title centered */
	mvwaddch(win, 0, (w - (len + 2))/2 - 1, ACS_RTEE);
	wprintw(win, " %s ", title);
	waddch(win, ACS_LTEE);
}

void	alx_ncurses_subtitle	(WINDOW *restrict win,
				 const char *restrict subtitle)
{
	int	h;
	int	w;
	int	len;

	/* Size of window */
	h	= getmaxy(win);
	w	= getmaxx(win);

	/* Length of title */
	len	= strlen(subtitle);

	/* Print subtitle centered */
	mvwaddch(win, h - 1, (w - (len + 2))/2 - 1, ACS_RTEE);
	wprintw(win, " %s ", subtitle);
	waddch(win, ACS_LTEE);
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
