/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/getenv/getenv_u.h"

#include <stdint.h>
#include <stdlib.h>

#include <libalx/base/stdlib/strto/strtou_s.h>


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
int	alx_getenv_u64		(uint64_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtou64_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_getenv_u32		(uint32_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtou32_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_getenv_u16		(uint16_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtou16_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_getenv_u8		(uint8_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtou8_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_u64	(uint64_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtou64_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_u32	(uint32_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtou32_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_u16	(uint16_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtou16_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_u8	(uint8_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtou8_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
ALX_ALIAS_WEAK_DEF(getenv_u64,		alx_getenv_u64);
ALX_ALIAS_WEAK_DEF(getenv_u32,		alx_getenv_u32);
ALX_ALIAS_WEAK_DEF(getenv_u16,		alx_getenv_u16);
ALX_ALIAS_WEAK_DEF(getenv_u8,		alx_getenv_u8);
ALX_ALIAS_WEAK_DEF(secure_getenv_u64,	alx_secure_getenv_u64);
ALX_ALIAS_WEAK_DEF(secure_getenv_u32,	alx_secure_getenv_u32);
ALX_ALIAS_WEAK_DEF(secure_getenv_u16,	alx_secure_getenv_u16);
ALX_ALIAS_WEAK_DEF(secure_getenv_u8,	alx_secure_getenv_u8);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
