/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/strto/strtou_s.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define strtou8_s(num, str, base, nread)   alx_strtou8_s(num, str, base, nread)
#define strtou16_s(num, str, base, nread)  alx_strtou16_s(num, str, base, nread)
#define strtou32_s(num, str, base, nread)  alx_strtou32_s(num, str, base, nread)
#define strtou64_s(num, str, base, nread)  alx_strtou64_s(num, str, base, nread)
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull(1, 2)]][[gnu::warn_unused_result]]
int	alx_strtou8_s		(uint8_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
[[gnu::nonnull(1, 2)]][[gnu::warn_unused_result]]
int	alx_strtou16_s		(uint16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
[[gnu::nonnull(1, 2)]][[gnu::warn_unused_result]]
int	alx_strtou32_s		(uint32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);
[[gnu::nonnull(1, 2)]][[gnu::warn_unused_result]]
int	alx_strtou64_s		(uint64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict nread);

[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_strtoul_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before);
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
