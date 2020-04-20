/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/strto/strtou_s.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>

#include "libalx/base/compiler/attribute.h"
#include "libalx/base/stdlib/strto/strtoi_s.h"


/******************************************************************************
 ******* define ***************************************************************
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
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtou8_s		(uint8_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtou16_s		(uint16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtou32_s		(uint32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtou64_s		(uint64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);

__attribute__((nonnull, warn_unused_result))
inline
int	alx_strtoul_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(strtou8_s,	alx_strtou8_s);
ALX_ALIAS_DECLARATION(strtou16_s,	alx_strtou16_s);
ALX_ALIAS_DECLARATION(strtou32_s,	alx_strtou32_s);
ALX_ALIAS_DECLARATION(strtou64_s,	alx_strtou64_s);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
int	alx_strtoul_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before)
{
	return	alx_strtol_status(str, endptr, errno_after, errno_before);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
