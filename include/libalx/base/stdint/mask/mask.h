/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdint/mask/mask.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/assert/type.h"


/******************************************************************************
 ******* typedefs *************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define BITMASK_GEN(pos, len)	(~(~0ull << len) << pos)

#define BITMASK_SET(x, mask)	(					\
{									\
	__auto_type	x_	= (x);					\
	__auto_type	m_	= (mask);				\
									\
	alx_Static_assert_unsigned(*x_);				\
	alx_Static_assert_same_type(*x_, m_);				\
									\
	*x_	|= m_;							\
	*x_;								\
}									\
)

#define BITMASK_CLEAR(x, mask)	(					\
{									\
	__auto_type	x_	= (x);					\
	__auto_type	m_	= (mask);				\
									\
	alx_Static_assert_unsigned(*x_);				\
	alx_Static_assert_same_type(*x_, m_);				\
									\
	*x_	&= ~m_;							\
	*x_;								\
}									\
)

#define BITMASK_FLIP(x, mask)	(					\
{									\
	__auto_type	x_	= (x);					\
	__auto_type	m_	= (mask);				\
									\
	alx_Static_assert_unsigned(*x_);				\
	alx_Static_assert_same_type(*x_, m_);				\
									\
	*x_	^= m_;							\
	*x_;								\
}									\
)

#define BITMASK_READ(x, mask)	(					\
{									\
	__auto_type	x_	= (x);					\
	__auto_type	m_	= (mask);				\
									\
	alx_Static_assert_unsigned(x_);					\
	alx_Static_assert_same_type(x_, m_);				\
									\
	x_	&= m_;							\
	x_;								\
}									\
)


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/