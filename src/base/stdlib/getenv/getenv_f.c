/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/getenv/getenv_f.h"

#include <stdlib.h>

#include <libalx/base/stdlib/strto/strtof_s.h>


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
int	alx_getenv_d		(double *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtod_s(num, env, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_getenv_f		(float *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtof_s(num, env, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_getenv_ld		(long double *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtold_s(num, env, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_d	(double *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtod_s(num, env, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_f	(float *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtof_s(num, env, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}

int	alx_secure_getenv_ld	(long double *restrict num,
				 const char *restrict name)
{
	const char	*env;
	int		status;

	env	= secure_getenv(name);
	if (!env)
		return	-2;
	status	= alx_strtold_s(num, env, NULL);
	if (status < 0)
		return	-1;
	if (status)
		return	1;
	return	0;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/
#if defined(ALX_NO_PREFIX)
ALX_ALIAS_WEAK_DEFINITION(getenv_d,		alx_getenv_d);
ALX_ALIAS_WEAK_DEFINITION(getenv_f,		alx_getenv_f);
ALX_ALIAS_WEAK_DEFINITION(getenv_ld,		alx_getenv_ld);
ALX_ALIAS_WEAK_DEFINITION(secure_getenv_d,	alx_secure_getenv_d);
ALX_ALIAS_WEAK_DEFINITION(secure_getenv_f,	alx_secure_getenv_f);
ALX_ALIAS_WEAK_DEFINITION(secure_getenv_ld,	alx_secure_getenv_ld);
#endif


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
