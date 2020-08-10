/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/lmax.h"

#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "libalx/base/compiler/size.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/
enum	Cell {
	NOT_LOCAL_MAX,
	MAYBE_LOCAL_MAX,
	LOCAL_MAX
};


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
//#pragma GCC diagnostic push	/* Over/underflow is explicitly handled */
//#pragma GCC diagnostic ignored	"-Wsign-conversion"
void	alx_lmax_ldbl	(ptrdiff_t rows, ptrdiff_t cols,
			 const long double arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_out, 0, sizeof(arr_out[0][0]) * rows * cols);

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
			}
			}
		}
		}
		arr_out[i][j]	= true;
		continue;
not_maxima:
		;
	}
	}
}

void	alx_lmax	(ptrdiff_t rows, ptrdiff_t cols,
			 const double arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_out, 0, sizeof(arr_out[0][0]) * rows * cols);

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
			}
			}
		}
		}
		arr_out[i][j]	= true;
		continue;
not_maxima:
		;
	}
	}
}

void	alx_lmax_f	(ptrdiff_t rows, ptrdiff_t cols,
			 const float arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_out, 0, sizeof(arr_out[0][0]) * rows * cols);

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
			}
			}
		}
		}
		arr_out[i][j]	= true;
		continue;
not_maxima:
		;
	}
	}
}

void	alx_lmax_uint	(ptrdiff_t rows, ptrdiff_t cols,
			 const unsigned arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_tmp, 0, ARRAY_BYTES(arr_tmp));

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do {
		wh	= false;
		for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
			for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= NOT_LOCAL_MAX;
		}
		}
	} while (wh);

	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++)
			arr_out[i][j]	= arr_tmp[i][j];
	}
}

void	alx_lmax_int	(ptrdiff_t rows, ptrdiff_t cols,
			 const int arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_tmp, 0, ARRAY_BYTES(arr_tmp));

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do {
		wh	= false;
		for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
			for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= NOT_LOCAL_MAX;
		}
		}
	} while (wh);

	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++)
			arr_out[i][j]	= arr_tmp[i][j];
	}
}

void	alx_lmax_u8	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint8_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_tmp, 0, ARRAY_BYTES(arr_tmp));

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do {
		wh	= false;
		for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
			for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= NOT_LOCAL_MAX;
		}
		}
	} while (wh);

	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++)
			arr_out[i][j]	= arr_tmp[i][j];
	}
}

void	alx_lmax_s8	(ptrdiff_t rows, ptrdiff_t cols,
			 const int8_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_tmp, 0, ARRAY_BYTES(arr_tmp));

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do {
		wh	= false;
		for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
			for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= NOT_LOCAL_MAX;
		}
		}
	} while (wh);

	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++)
			arr_out[i][j]	= arr_tmp[i][j];
	}
}

void	alx_lmax_u16	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint16_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_tmp, 0, ARRAY_BYTES(arr_tmp));

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do {
		wh	= false;
		for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
			for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= NOT_LOCAL_MAX;
		}
		}
	} while (wh);

	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++)
			arr_out[i][j]	= arr_tmp[i][j];
	}
}

void	alx_lmax_s16	(ptrdiff_t rows, ptrdiff_t cols,
			 const int16_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_tmp, 0, ARRAY_BYTES(arr_tmp));

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do {
		wh	= false;
		for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
			for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= NOT_LOCAL_MAX;
		}
		}
	} while (wh);

	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++)
			arr_out[i][j]	= arr_tmp[i][j];
	}
}

void	alx_lmax_u32	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint32_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_tmp, 0, ARRAY_BYTES(arr_tmp));

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do {
		wh	= false;
		for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
			for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= NOT_LOCAL_MAX;
		}
		}
	} while (wh);

	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++)
			arr_out[i][j]	= arr_tmp[i][j];
	}
}

void	alx_lmax_s32	(ptrdiff_t rows, ptrdiff_t cols,
			 const int32_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_tmp, 0, ARRAY_BYTES(arr_tmp));

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do {
		wh	= false;
		for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
			for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= NOT_LOCAL_MAX;
		}
		}
	} while (wh);

	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++)
			arr_out[i][j]	= arr_tmp[i][j];
	}
}

void	alx_lmax_u64	(ptrdiff_t rows, ptrdiff_t cols,
			 const uint64_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_tmp, 0, ARRAY_BYTES(arr_tmp));

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do {
		wh	= false;
		for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
			for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= NOT_LOCAL_MAX;
		}
		}
	} while (wh);

	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++)
			arr_out[i][j]	= arr_tmp[i][j];
	}
}

void	alx_lmax_s64	(ptrdiff_t rows, ptrdiff_t cols,
			 const int64_t arr_in[static restrict rows][cols],
			 bool arr_out[static restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	if ((size_t)rows > (SSIZE_MAX / (cols * sizeof(arr_out[0][0])))) {
		errno	= EOVERFLOW;
		return;
	}
	if ((rows >= (PTRDIFF_MAX - 1))  ||  (cols >= (PTRDIFF_MAX - 1))) {
		errno	= EOVERFLOW;
		return;
	}

	memset(arr_tmp, 0, ARRAY_BYTES(arr_tmp));

	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
		for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				if (arr_in[k][l] > arr_in[i][j])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do {
		wh	= false;
		for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = i + 1; k >= (i - 1); k--) {
			for (ptrdiff_t l = j + 1; l >= (j - 1); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= NOT_LOCAL_MAX;
		}
		}
	} while (wh);

	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++)
			arr_out[i][j]	= arr_tmp[i][j];
	}
}
//#pragma GCC diagnostic pop


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
