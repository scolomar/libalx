/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/

/*
 * TODO:
 *	X/Y plot
 *	ANOVA
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/alx/data-structures/dataframe.h"

#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "libalx/alx/data-structures/bst.h"
#include "libalx/alx/data-structures/dyn-array.h"
#include "libalx/alx/data-structures/dyn-buffer.h"
#include "libalx/alx/data-structures/llist.h"
#include "libalx/alx/data-structures/node.h"
#include "libalx/alx/data-structures/types.h"
#include "libalx/base/compiler/unused.h"
#include "libalx/base/stdlib/alloc/frees.h"
#include "libalx/base/stdlib/alloc/mallocarrays.h"
#include "libalx/base/stdlib/compare.h"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
__attribute__((nonnull, warn_unused_result))
static
int	df_cmp_data		(const void *user_data, const void *ds_data);

__attribute__((nonnull(1, 2), warn_unused_result))
static
int	df_ins_col_value	(struct Alx_DF_Col *col,
				 const char *restrict value,
				 const char **restrict s);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_df_init		(struct Alx_DataFrame **df, ptrdiff_t ncols)
{

	if (alx_mallocarrays(df, 1))
		return	ENOMEM;
	if (alx_dynarr_init(&(*df)->cols, sizeof(struct Alx_DF_Col)))
		goto free_df;
	if (alx_dynarr_resize((*df)->cols, ncols, 0))
		goto free_cols;
	if (alx_llist_init(&(*df)->rows))
		goto free_cols;
	(*df)->ncols	= &(*df)->cols->written;
	(*df)->nrows	= &(*df)->rows->nmemb;

	return	0;

free_cols:
	alx_dynarr_deinit((*df)->cols);
free_df:
	alx_frees(df);
	return	ENOMEM;
}

void	alx_df_deinit		(struct Alx_DataFrame *df)
{

	if (!df)
		return;
	// TODO: deinit rows (now this is a memleak)
	alx_llist_deinit(df->rows);
	alx_dynarr_deinit(df->cols);
	free(df);
}

int	alx_df_ins_col		(struct Alx_DataFrame *restrict df,
				 ptrdiff_t ncol, int type, char *restrict hdr,
				 const char *values[restrict])
{

	struct Alx_DF_Col	col = {0};

	col.type	= type;

	if (hdr) {
		if (alx_dynbuf_init(&col.hdr))
			return	ENOMEM;
		if (alx_dynbuf_write(col.hdr, 0, hdr, strlen(hdr) + 1))
			goto free_buf;
	} else {
		col.hdr	= NULL;
	}

	if (alx_bst_init(&col.values, &df_cmp_data, false))
		goto free_buf;
	if (values) {
		for (ptrdiff_t i = 0; values[i]; i++) {
			if (df_ins_col_value(&col, values[i], NULL))
				goto free_bst;
		}
	}
	col.ltd_values	= values;

	if (alx_dynarr_insert(df->cols, ncol, &col))
		goto free_bst;

	return	0;
free_bst:
	alx_bst_deinit(col.values);
free_buf:
	alx_dynbuf_deinit(col.hdr);
	return	ENOMEM;
}

int	alx_df_get_col		(struct Alx_DF_Col **col,
				 struct Alx_DataFrame *df, ptrdiff_t ncol)
{
	struct Alx_DF_Col	*cdata;

	if (ncol >= *df->ncols  ||  ncol < -*df->ncols)
		goto err;
	if (ncol < 0)
		ncol += *df->ncols;

	cdata	= df->cols->data;
	*col	= &cdata[ncol];
	return	0;
err:
	*col	= NULL;
	return	EBADSLT;
}

int	alx_df_ins_row		(struct Alx_DataFrame *restrict df,
				 ptrdiff_t nrow)
{
	struct Alx_DF_Row	rdata;
	struct Alx_Node	*row;

	rdata.err	= 0;
	if (alx_dynarr_init(&rdata.cells, sizeof(struct Alx_DF_Cell)))
		return	ENOMEM;
	if (alx_dynarr_resize(rdata.cells, *df->ncols, 0))
		goto err;
	if (alx_node_init(&row, &rdata, sizeof(rdata)))
		goto err;
	alx_llist_insert_node_at(df->rows, row, nrow);

	return	0;
err:
	alx_dynarr_deinit(rdata.cells);
	return	ENOMEM;
}

int	alx_df_get_row		(struct Alx_DF_Row **row,
				 struct Alx_DataFrame *df, ptrdiff_t nrow)
{
	struct Alx_Node	*node;
	void			*rdata;
	int			status;

	if (!*df->nrows) {
		status	= ENOENT;
		goto err;
	}
	if (nrow >= *df->nrows  ||  nrow < -*df->nrows) {
		status	= EBADSLT;
		goto err;
	}

	status	= alx_llist_get_node_at(df->rows, &node, nrow);
	if (status)
		goto err;
	status	= alx_node_get_data(&rdata, node);
	if (status)
		goto err;
	*row	= rdata;
	return	0;
err:
	*row	= NULL;
	return	status;
}

int	alx_df_drop_row	(struct Alx_DataFrame *df, ptrdiff_t nrow)
{
	struct Alx_Node	*node;
	struct Alx_DF_Row	*row;
	int			status;

	status	= alx_df_get_row(&row, df, nrow);
	if (status)
		return	status;
	alx_dynarr_deinit(row->cells);

	status	= alx_llist_get_node_at(df->rows, &node, nrow);
	if (status)
		return	status;
	return	alx_llist_delete_node(df->rows, node);
}

int	alx_df_ins_cell	(struct Alx_DataFrame *restrict df,
				 ptrdiff_t nrow, ptrdiff_t ncol,
				 const struct Alx_DF_Cell *restrict data)
{
	struct Alx_DF_Col	*col;
	struct Alx_DF_Row	*row;
	struct Alx_DF_Cell	cell = {0};
	int			status;

	if (alx_df_get_col(&col, df, ncol))
		return	-EBADSLT;
	if (data->type != col->type)
		return	-EINVAL;

	status	= alx_df_get_row(&row, df, nrow);
	if (status)
		return	-status;
	if (ncol < 0)
		ncol += *df->ncols;
	cell.type	= data->type;
	switch (cell.type) {
	case ALX_DF_TYPE_S64:
		cell.i	= data->i;
		break;
	case ALX_DF_TYPE_DBL:
		cell.f	= data->f;
		break;
	case ALX_DF_TYPE_STR:
		status	= df_ins_col_value(col, data->s, &cell.s);
		if (status < 0)
			return	status;
		break;
	default:
		cell.err	= true;
		break;
	}

	return	-alx_dynarr_insert(row->cells, ncol, &cell);
}

int	alx_df_get_row_cell	(struct Alx_DF_Cell **cell,
				 struct Alx_DF_Row *row, ptrdiff_t ncol)
{
	struct Alx_DF_Cell	*rdata;
	int			status;

	if (!row->cells->written) {
		status	= ENOENT;
		goto err;
	}
	if (ncol >= row->cells->written  ||  ncol < -row->cells->written) {
		status	= EBADSLT;
		goto err;
	}
	if (ncol < 0)
		ncol += row->cells->written;

	rdata	= row->cells->data;
	*cell	= &rdata[ncol];
	return	0;
err:
	*cell	= NULL;
	return	status;
}

int	alx_df_get_cell	(struct Alx_DF_Cell **restrict cell,
				 struct Alx_DataFrame *restrict df,
				 ptrdiff_t nrow, ptrdiff_t ncol)
{
	struct Alx_DF_Row	*row;
	int			status;

	status	= alx_df_get_row(&row, df, nrow);
	if (status)
		goto err;
	return	alx_df_get_row_cell(cell, row, ncol);
err:
	*cell	= NULL;
	return	status;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	df_cmp_data		(const void *user_data, const void *ds_data)
{
	return	strcasecmp(user_data, ds_data);
}

static
int	df_ins_col_value	(struct Alx_DF_Col *col,
				 const char *restrict value,
				 const char **restrict s)
{
	struct Alx_Node	*node;
	void			*vp;
	int			status1;
	int			status2;

	if (col->ltd_values) {
		if (alx_bst_find(&node, col->values, value))
			return	-EACCES;
		status1	= EEXIST;
		goto out;
	}

	if (col->values->cmp != &df_cmp_data)
		alx_bst_reorder(col->values, &df_cmp_data);
	status1	= alx_bst_insert(col->values, value, strlen(value) + 1, &node);
	if (status1 < 0)
		return	status1;
out:
	status2	= alx_node_get_data(&vp, node);
	if (status2)
		return	-status2;
	if (s)
		*s	= vp;

	return	status1;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
