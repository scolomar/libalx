/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/search.h"

#include <stddef.h>
#include <stdint.h>


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
ptrdiff_t	alx_search_uint	(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb],
				 unsigned x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_int	(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb],
				 int x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb],
				 uint8_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb],
				 int8_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb],
				 uint16_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb],
				 int16_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb],
				 uint32_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb],
				 int32_t x)
{
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb],
				 uint64_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_s64	(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb],
				 int64_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_WEAK_DEFINITION(search_uint,	alx_search_uint);
ALX_ALIAS_WEAK_DEFINITION(search_int,	alx_search_int);
ALX_ALIAS_WEAK_DEFINITION(search_u8,	alx_search_u8);
ALX_ALIAS_WEAK_DEFINITION(search_s8,	alx_search_s8);
ALX_ALIAS_WEAK_DEFINITION(search_u16,	alx_search_u16);
ALX_ALIAS_WEAK_DEFINITION(search_s16,	alx_search_s16);
ALX_ALIAS_WEAK_DEFINITION(search_u32,	alx_search_u32);
ALX_ALIAS_WEAK_DEFINITION(search_s32,	alx_search_s32);
ALX_ALIAS_WEAK_DEFINITION(search_u64,	alx_search_u64);
ALX_ALIAS_WEAK_DEFINITION(search_s64,	alx_search_s64);
#endif


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
