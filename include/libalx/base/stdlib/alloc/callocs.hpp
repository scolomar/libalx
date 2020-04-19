/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/callocs.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]]
 * int	callocs(type **ptr, size_t nmemb);
 *
 * Read  <libalx/base/stdlib/alloc/callocs.h>  for documentation.
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>

#include "libalx/base/compiler/unused.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define alx_callocs(ptr, nmemb)	(					\
{									\
	auto	ptr_	= (ptr);					\
	void	*vp_;							\
	int	err_;							\
									\
	vp_	= alx_callocs__(nmemb, sizeof(**ptr_), &err_);		\
	*ptr_	= static_cast<typeof(*ptr_)>(vp_);			\
	alx_warn_unused_int(err_);					\
}									\
)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define callocs(ptr, nmemb)	alx_callocs(ptr, nmemb)
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::malloc]] [[gnu::nonnull]] [[gnu::warn_unused_result]]
void	*alx_callocs__	(ptrdiff_t nmemb, size_t size, int *error);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


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
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
