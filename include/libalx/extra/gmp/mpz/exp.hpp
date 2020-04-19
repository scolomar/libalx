/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gmp/mpz/exp.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstdint>

#include <gmp.h>


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define mpz_powm_u64(rop, base, exp, mod)  alx_mpz_powm_u64(rop, base, exp, mod)
#define mpz_pow_u64(rop, base, exp)	   alx_mpz_pow_u64(rop, base, exp)
#define mpz_u64_pow_u64(rop, base, exp)	   alx_mpz_u64_pow_u64(rop, base, exp)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
void	alx_mpz_powm_u64	(mpz_t rop, const mpz_t base, uint64_t exp,
				 const mpz_t mod);
void	alx_mpz_pow_u64		(mpz_t rop, const mpz_t base, uint64_t exp);
void	alx_mpz_u64_pow_u64	(mpz_t rop, uint64_t base, uint64_t exp);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace gmp {


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
}	/* namespace gmp */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
