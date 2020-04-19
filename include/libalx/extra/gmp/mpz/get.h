/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gmp/mpz/get.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
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
#define mpz_get_u64(op)			alx_mpz_get_u64(op)
#define mpz_get_s64(op)			alx_mpz_get_s64(op)
#define mpz_get_d_2exp_s64(exp, op)	alx_mpz_get_d_2exp_s64(exp, op)
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
uint64_t	alx_mpz_get_u64		(const mpz_t op);
inline
int64_t		alx_mpz_get_s64		(const mpz_t op);
inline
double		alx_mpz_get_d_2exp_s64	(int64_t *exp, const mpz_t op);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
uint64_t	alx_mpz_get_u64		(const mpz_t op)
{
	return	mpz_get_ui(op);
}

inline
int64_t		alx_mpz_get_s64		(const mpz_t op)
{
	return	mpz_get_si(op);
}

inline
double		alx_mpz_get_d_2exp_s64	(int64_t *exp, const mpz_t op)
{
	return	mpz_get_d_2exp(exp, op);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
