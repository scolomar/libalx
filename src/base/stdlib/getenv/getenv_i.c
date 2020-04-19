/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/getenv/getenv_i.h"

#include <stdint.h>
#include <stdlib.h>

#include <libalx/base/stdlib/strto/strtoi_s.h>


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
int	alx_getenv_i64		(int64_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtoi64_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_getenv_i32		(int32_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtoi32_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_getenv_i16		(int16_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtoi16_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_getenv_i8		(int8_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtoi8_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_i64	(int64_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtoi64_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_i32	(int32_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtoi32_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_i16	(int16_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtoi16_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_i8	(int8_t *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtoi8_s(num, env, 0, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
