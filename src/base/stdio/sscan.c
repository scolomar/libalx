/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdio/sscan.h"

#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "libalx/base/stdio/printf/sbprintf.h"
#include "libalx/base/string/strchr/strcasechr.h"


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
int	alx_sscan_ldbl	(long double *restrict dest,
			 long double m, long double def, long double M,
			 const char *restrict str)
{

	if (sscanf(str, " %Lf", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_dbl	(double *restrict dest,
			 double m, double def, double M,
			 const char *restrict str)
{

	if (sscanf(str, " %lf", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_flt	(float *restrict dest,
			 float m, float def, float M,
			 const char *restrict str)
{

	if (sscanf(str, " %f", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_uint	(unsigned *restrict dest,
			 unsigned m, unsigned def, unsigned M,
			 const char *restrict str)
{

	if (sscanf(str, " %u", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_int	(int *restrict dest,
			 int m, int def, int M,
			 const char *restrict str)
{

	if (sscanf(str, " %i", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_u8	(uint8_t *restrict dest,
			 uint8_t m, uint8_t def, uint8_t M,
			 const char *restrict str)
{

	if (sscanf(str, " %"SCNu8"", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_s8	(int8_t *restrict dest,
			 int8_t m, int8_t def, int8_t M,
			 const char *restrict str)
{

	if (sscanf(str, " %"SCNi8"", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_u16	(uint16_t *restrict dest,
			 uint16_t m, uint16_t def, uint16_t M,
			 const char *restrict str)
{

	if (sscanf(str, " %"SCNu16"", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_s16	(int16_t *restrict dest,
			 int16_t m, int16_t def, int16_t M,
			 const char *restrict str)
{

	if (sscanf(str, " %"SCNi16"", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_u32	(uint32_t *restrict dest,
			 uint32_t m, uint32_t def, uint32_t M,
			 const char *restrict str)
{

	if (sscanf(str, " %"SCNu32"", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_s32	(int32_t *restrict dest,
			 int32_t m, int32_t def, int32_t M,
			 const char *restrict str)
{

	if (sscanf(str, " %"SCNi32"", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_u64	(uint64_t *restrict dest,
			 uint64_t m, uint64_t def, uint64_t M,
			 const char *restrict str)
{

	if (sscanf(str, " %"SCNu64"", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_s64	(int64_t *restrict dest,
			 int64_t m, int64_t def, int64_t M,
			 const char *restrict str)
{

	if (sscanf(str, " %"SCNi64"", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_pdif	(ptrdiff_t *restrict dest,
			 ptrdiff_t m, ptrdiff_t def, ptrdiff_t M,
			 const char *restrict str)
{

	if (sscanf(str, " %ti", dest) != 1)
		goto err_sscanf;
	if ((*dest < m) || (*dest > M))
		goto err_range;

	return	0;

err_range:
	errno	= ERANGE;
err_sscanf:
	*dest	= def;
	return	1;
}

int	alx_sscan_ch	(char *restrict dest,
			 const char *restrict valid,
			 bool skip_space, bool ignore_case,
			 const char *restrict str)
{
	char	*format;

	if (skip_space)
		format	= " %c";
	else
		format	= "%c";

	if (sscanf(str, format, dest) != 1)
		goto err_sscanf;

	if (ignore_case) {
		if (alx_strcasechr(valid, *dest) < 0)
			goto err_nfound;
	} else {
		if (!strchr(valid, *dest))
			goto err_nfound;
	}

	return	0;

err_nfound:
	errno	= ERANGE;
err_sscanf:
	*dest	= valid[0];
	return	1;
}

int	alx_sscan_fname	(const char *restrict path,
			 char fname[restrict FILENAME_MAX],
			 bool exist,
			 const char *restrict str)
{
	char	buff [FILENAME_MAX];
	char	fpath [FILENAME_MAX];
	FILE	*fp;

	if (sscanf(str, " %s", buff) != 1)
		return	-1;
	if (alx_sbprintf(fpath, NULL, "%s/%s", path, buff))
		return	-1;

	fp	= fopen(fpath, "r");
	if (fp) {
		fclose(fp);
		if (!exist)
			goto eexist;
	} else {
		if (exist)
			goto enoent;
	}

	if (snprintf(fname, FILENAME_MAX, "%s", buff) < 0)
		return	-1;

	return	0;

enoent:
	if (!errno)
		errno	= ENOENT;
	return	-1;
eexist:
	if (!errno)
		errno	= EEXIST;
	return	-1;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
