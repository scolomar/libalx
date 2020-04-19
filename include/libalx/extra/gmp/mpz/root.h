/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gmp/mpz/root.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>

#include <gmp.h>

#include "libalx/base/assert/stdint.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/
alx_Static_assert_stdint_types();


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define mpz_root_u64(rop, op, n)	  alx_mpz_root_u64(rop, op, n)
#define mpz_rootrem_u64(root, rem, u, n)  alx_mpz_rootrem_u64(root, rem, u, n)
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
inline
bool	alx_mpz_root_u64	(mpz_t rop, const mpz_t op, uint64_t n);
inline
void	alx_mpz_rootrem_u64	(mpz_t root, mpz_t rem,
				 const mpz_t u, uint64_t n);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
bool	alx_mpz_root_u64	(mpz_t rop, const mpz_t op, uint64_t n)
{
	return	mpz_root(rop, op, n);
}

inline
void	alx_mpz_rootrem_u64	(mpz_t root, mpz_t rem,
				 const mpz_t u, uint64_t n)
{
	mpz_rootrem(root, rem, u, n);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
