/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/dataframe.h */

#if defined(__cplusplus)
#warning	This header file should only be included in C.  In C++,	\
		include the header file of the same name and `.hpp`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Similar to python panda's dataframe
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "libalx/alx/data-structures/types.h"


/******************************************************************************
 ******* macros ***************************************************************
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
__attribute__((nonnull, warn_unused_result))
int	alx_df_init		(struct Alx_DataFrame **df, ptrdiff_t ncols);
void	alx_df_deinit		(struct Alx_DataFrame *df);
__attribute__((nonnull(1), warn_unused_result))
int	alx_df_ins_col		(struct Alx_DataFrame *restrict df,
				 ptrdiff_t ncol, int type, char *restrict hdr,
				 const char *values[restrict]);
__attribute__((nonnull, warn_unused_result))
int	alx_df_get_col		(struct Alx_DF_Col **col,
				 struct Alx_DataFrame *df, ptrdiff_t ncol);
__attribute__((nonnull, warn_unused_result))
int	alx_df_drop_col	(struct Alx_DataFrame *df,
				 ptrdiff_t ncol);
__attribute__((nonnull, warn_unused_result))
int	alx_df_ins_row		(struct Alx_DataFrame *restrict df,
				 ptrdiff_t nrow);
__attribute__((nonnull, warn_unused_result))
int	alx_df_get_row		(struct Alx_DF_Row **row,
				 struct Alx_DataFrame *df, ptrdiff_t nrow);
__attribute__((nonnull, warn_unused_result))
int	alx_df_drop_row	(struct Alx_DataFrame *df,
				 ptrdiff_t nrow);
__attribute__((nonnull, warn_unused_result))
int	alx_df_ins_cell	(struct Alx_DataFrame *restrict df,
				 ptrdiff_t nrow, ptrdiff_t ncol,
				 const struct Alx_DF_Cell *restrict cell);
__attribute__((nonnull, warn_unused_result))
int	alx_df_ovr_cell	(struct Alx_DataFrame *restrict df,
				 ptrdiff_t nrow, ptrdiff_t ncol,
				 const struct Alx_DF_Cell *restrict cell);
__attribute__((nonnull, warn_unused_result))
int	alx_df_get_row_cell	(struct Alx_DF_Cell **cell,
				 struct Alx_DF_Row *row, ptrdiff_t ncol);
__attribute__((nonnull, warn_unused_result))
int	alx_df_get_cell	(struct Alx_DF_Cell **restrict cell,
				 struct Alx_DataFrame *restrict df,
				 ptrdiff_t nrow, ptrdiff_t ncol);
int	alx_df_dropna		(struct Alx_DataFrame *df);
int	alx_df_sort		(struct Alx_DataFrame *df,
				 ptrdiff_t ncol);
int	alx_df_sort_bwd	(struct Alx_DataFrame *df,
				 ptrdiff_t ncol);
int	alx_df_describe	(struct Alx_DataFrame *df);
int	alx_df_fprn_data	(FILE *restrict ostream,
				 struct Alx_DataFrame *restrict df);
int	alx_df_fprn_desc	(FILE *restrict ostream,
				 struct Alx_DataFrame *restrict df);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
