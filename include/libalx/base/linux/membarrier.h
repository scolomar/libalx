/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/linux/membarrier.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <unistd.h>
#include <sys/syscall.h>


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
inline
int	alx_membarrier	(int cmd, int flags);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline))
inline
int	membarrier	(int cmd, int flags)
{
	return	alx_membarrier(cmd, flags);
}
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
int	alx_membarrier	(int cmd, int flags)
{
	return	syscall(__NR_membarrier, cmd, flags);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
