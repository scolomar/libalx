/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/average.h */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
#define	ALX_AVG(a, b) (							\
{									\
	((a) + (b)) / 2;						\
}									\
)

#define	ALX_AVGS(a, b) (						\
{									\
	__auto_type	a_	= (a);					\
	__auto_type	b_	= (b);					\
									\
	(a_ / 2) + (b_ / 2) + (((a_ % 2) + (b_ % 2)) / 2);		\
}									\
)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define AVG(a, b)	ALX_AVG(a, b)
#define AVGS(a, b)	ALX_AVGS(a, b)
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


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
