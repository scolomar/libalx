/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/cmp.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <stdint.h>

#include "libalx/base/compiler/attribute.h"


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
__attribute__((nonnull, pure))
inline
int	alx_cmp_ldbl	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp		(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_f	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_uint	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_int	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_char	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_u8	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_s8	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_u16	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_s16	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_u32	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_s32	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_u64	(const void *a_ptr, const void *b_ptr);
__attribute__((nonnull, pure))
inline
int	alx_cmp_s64	(const void *a_ptr, const void *b_ptr);


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_DECLARATION(cmp_ldbl,	alx_cmp_ldbl);
ALX_ALIAS_DECLARATION(cmp,	alx_cmp);
ALX_ALIAS_DECLARATION(cmp_f,	alx_cmp_f);
ALX_ALIAS_DECLARATION(cmp_uint,	alx_cmp_uint);
ALX_ALIAS_DECLARATION(cmp_int,	alx_cmp_int);
ALX_ALIAS_DECLARATION(cmp_char,	alx_cmp_char);
ALX_ALIAS_DECLARATION(cmp_u8,	alx_cmp_u8);
ALX_ALIAS_DECLARATION(cmp_s8,	alx_cmp_s8);
ALX_ALIAS_DECLARATION(cmp_u16,	alx_cmp_u16);
ALX_ALIAS_DECLARATION(cmp_s16,	alx_cmp_s16);
ALX_ALIAS_DECLARATION(cmp_u32,	alx_cmp_u32);
ALX_ALIAS_DECLARATION(cmp_s32,	alx_cmp_s32);
ALX_ALIAS_DECLARATION(cmp_u64,	alx_cmp_u64);
ALX_ALIAS_DECLARATION(cmp_s64,	alx_cmp_s64);
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
int	alx_cmp_ldbl	(const void *a_ptr, const void *b_ptr)
{
	long double	a =	*(long double *)a_ptr;
	long double	b =	*(long double *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp		(const void *a_ptr, const void *b_ptr)
{
	double	a =	*(double *)a_ptr;
	double	b =	*(double *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_f	(const void *a_ptr, const void *b_ptr)
{
	float	a =	*(float *)a_ptr;
	float	b =	*(float *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_uint	(const void *a_ptr, const void *b_ptr)
{
	unsigned	a =	*(unsigned *)a_ptr;
	unsigned	b =	*(unsigned *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_int	(const void *a_ptr, const void *b_ptr)
{
	int	a =	*(int *)a_ptr;
	int	b =	*(int *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_char	(const void *a_ptr, const void *b_ptr)
{
	char	a =	*(char *)a_ptr;
	char	b =	*(char *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_u8	(const void *a_ptr, const void *b_ptr)
{
	uint8_t	a =	*(uint8_t *)a_ptr;
	uint8_t	b =	*(uint8_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_s8	(const void *a_ptr, const void *b_ptr)
{
	int8_t	a =	*(int8_t *)a_ptr;
	int8_t	b =	*(int8_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_u16	(const void *a_ptr, const void *b_ptr)
{
	uint16_t	a =	*(uint16_t *)a_ptr;
	uint16_t	b =	*(uint16_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_s16	(const void *a_ptr, const void *b_ptr)
{
	int16_t	a =	*(int16_t *)a_ptr;
	int16_t	b =	*(int16_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_u32	(const void *a_ptr, const void *b_ptr)
{
	uint32_t	a =	*(uint32_t *)a_ptr;
	uint32_t	b =	*(uint32_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_s32	(const void *a_ptr, const void *b_ptr)
{
	int32_t	a =	*(int32_t *)a_ptr;
	int32_t	b =	*(int32_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_u64	(const void *a_ptr, const void *b_ptr)
{
	uint64_t	a =	*(uint64_t *)a_ptr;
	uint64_t	b =	*(uint64_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_cmp_s64	(const void *a_ptr, const void *b_ptr)
{
	int64_t	a =	*(int64_t *)a_ptr;
	int64_t	b =	*(int64_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
