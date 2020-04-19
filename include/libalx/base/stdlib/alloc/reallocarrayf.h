/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/reallocarrayf.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::warn_unused_result]]
 * void	*reallocarrayf(void *ptr, ptrdiff_t nmemb, size_t size);
 *
 * Almost equivalent to `reallocarray()`.
 *
 * PARAMETERS:
 * ptr:		Pointer to allocated memory (or NULL).
 * nmemb:	Number of elements in the array.
 * size:	Size of each element in the array.
 *
 * RETURN:
 *	!= NULL:	OK.
 *	NULL:		Failed  OR  zero size reallocation.
 *
 * FEATURES:
 * - Returns NULL on zero size reallocation.
 * - Fails safely if (nmemb < 0).
 * - Fails safely if (nmemb * size) would overflow.
 * - Upon failure, the passed pointer is freed.
 *
 * EXAMPLE:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/reallocarrayf.h>
 *
 *		int *arr;
 *
 *		arr	= mallocarray(5, sizeof(*arr);		// int arr[5];
 *		arr	= reallocarrayf(arr, 7, sizeof(*arr));	// int arr[7];
 *		if (!arr)
 *			goto err;
 *
 *		// `arr` has been succesfully reallocated here
 *		free(arr);
 *	err:
 *		// No memory leaks
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define reallocarrayf(ptr, nmemb, size)	alx_reallocarrayf(ptr, nmemb, size)
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((warn_unused_result))
void	*alx_reallocarrayf	(void *ptr, ptrdiff_t nmemb, size_t size);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
