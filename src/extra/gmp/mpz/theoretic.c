/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/extra/gmp/mpz/theoretic.h"

#include <stdint.h>

#include <gmp.h>


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
extern
void	alx_mpz_gcd_u64		(mpz_t rop, const mpz_t op1, uint64_t op2);
extern
void	alx_mpz_lcm_u64		(mpz_t rop, const mpz_t op1, uint64_t op2);

extern
int32_t	alx_mpz_kronecker_s64	(const mpz_t a, int64_t b);
extern
int32_t	alx_mpz_kronecker_u64	(const mpz_t a, uint64_t b);
extern
int32_t	alx_mpz_s64_kronecker	(int64_t a, const mpz_t b);
extern
int32_t	alx_mpz_u64_kronecker	(uint64_t a, const mpz_t b);

extern
void	alx_mpz_fac_u64		(mpz_t rop, uint64_t n);
extern
void	alx_mpz_2fac_u64	(mpz_t rop, uint64_t n);
extern
void	alx_mpz_mfac_u64	(mpz_t rop, uint64_t n, uint64_t m);

extern
void	alx_mpz_primorial_u64	(mpz_t rop, uint64_t n);

extern
void	alx_mpz_bin_u64		(mpz_t rop, const mpz_t n, uint64_t k);
extern
void	alx_mpz_bin_u64u64	(mpz_t rop, uint64_t n, uint64_t k);

extern
void	alx_mpz_fib_u64		(mpz_t fn, uint64_t n);
extern
void	alx_mpz_fib2_u64	(mpz_t fn, mpz_t fnsub1, uint64_t n);

extern
void	alx_mpz_lucnum_u64	(mpz_t ln, uint64_t n);
extern
void	alx_mpz_lucnum2_u64	(mpz_t ln, mpz_t lnsub1, uint64_t n);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(mpz_gcd_u64,		alx_mpz_gcd_u64);
ALX_ALIAS_WEAK_DEF(mpz_lcm_u64,		alx_mpz_lcm_u64);
ALX_ALIAS_WEAK_DEF(mpz_kronecker_s64,	alx_mpz_kronecker_s64);
ALX_ALIAS_WEAK_DEF(mpz_kronecker_u64,	alx_mpz_kronecker_u64);
ALX_ALIAS_WEAK_DEF(mpz_s64_kronecker,	alx_mpz_s64_kronecker);
ALX_ALIAS_WEAK_DEF(mpz_u64_kronecker,	alx_mpz_u64_kronecker);
ALX_ALIAS_WEAK_DEF(mpz_fac_u64,		alx_mpz_fac_u64);
ALX_ALIAS_WEAK_DEF(mpz_2fac_u64,	alx_mpz_2fac_u64);
ALX_ALIAS_WEAK_DEF(mpz_mfac_u64,	alx_mpz_mfac_u64);
ALX_ALIAS_WEAK_DEF(mpz_primorial_u64,	alx_mpz_primorial_u64);
ALX_ALIAS_WEAK_DEF(mpz_bin_u64,		alx_mpz_bin_u64);
ALX_ALIAS_WEAK_DEF(mpz_bin_u64u64,	alx_mpz_bin_u64u64);
ALX_ALIAS_WEAK_DEF(mpz_fib_u64,		alx_mpz_fib_u64);
ALX_ALIAS_WEAK_DEF(mpz_fib2_u64,	alx_mpz_fib2_u64);
ALX_ALIAS_WEAK_DEF(mpz_lucnum_u64,	alx_mpz_lucnum_u64);
ALX_ALIAS_WEAK_DEF(mpz_lucnum2_u64,	alx_mpz_lucnum2_u64);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
