/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/signal/sigterm.h"

#include <signal.h>
#include <stdbool.h>
#include <stddef.h>

#include "libalx/base/compiler/unused.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static variables *****************************************************
 ******************************************************************************/
sig_atomic_t	sigterm;


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
static
void	sigterm_handler		(int sig);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	sigterm_init	(void)
{
	struct sigaction	sa = {0};

	sigterm	= false;
	asm volatile ("" : : : "memory");

	sigemptyset(&sa.sa_mask);
	sa.sa_handler	= &sigterm_handler;
	return	sigaction(SIGTERM, &sa, NULL);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
void	sigterm_handler		(int sig)
{

	ALX_UNUSED(sig);

	sigterm	= true;
	asm volatile ("" : : : "memory");
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
