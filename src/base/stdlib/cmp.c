/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/cmp.h"


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
int	alx_cmp_ldbl	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp		(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_f	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_uint	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_int	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_char	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_u8	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_s8	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_u16	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_s16	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_u32	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_s32	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_u64	(const void *a_ptr, const void *b_ptr);
extern
int	alx_cmp_s64	(const void *a_ptr, const void *b_ptr);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(cmp_ldbl,	alx_cmp_ldbl);
ALX_ALIAS_WEAK_DEF(cmp,		alx_cmp);
ALX_ALIAS_WEAK_DEF(cmp_f,	alx_cmp_f);
ALX_ALIAS_WEAK_DEF(cmp_uint,	alx_cmp_uint);
ALX_ALIAS_WEAK_DEF(cmp_int,	alx_cmp_int);
ALX_ALIAS_WEAK_DEF(cmp_char,	alx_cmp_char);
ALX_ALIAS_WEAK_DEF(cmp_u8,	alx_cmp_u8);
ALX_ALIAS_WEAK_DEF(cmp_s8,	alx_cmp_s8);
ALX_ALIAS_WEAK_DEF(cmp_u16,	alx_cmp_u16);
ALX_ALIAS_WEAK_DEF(cmp_s16,	alx_cmp_s16);
ALX_ALIAS_WEAK_DEF(cmp_u32,	alx_cmp_u32);
ALX_ALIAS_WEAK_DEF(cmp_s32,	alx_cmp_s32);
ALX_ALIAS_WEAK_DEF(cmp_u64,	alx_cmp_u64);
ALX_ALIAS_WEAK_DEF(cmp_s64,	alx_cmp_s64);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
