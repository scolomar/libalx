/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/alx/data-structures/node.h"

#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include <sys/types.h>

#include "libalx/alx/data-structures/dyn-buffer.h"
#include "libalx/alx/data-structures/types.h"
#include "libalx/base/stdlib/alloc/mallocarrays.h"


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
int	alx_node_init		(struct Alx_Node **restrict node,
				 const void *restrict data, ssize_t size)
{

	if (alx_node_init_empty(node))
		goto enomem;
	if (!data)
		return	0;

	if (alx_dynbuf_init(&(*node)->buf))
		goto enomem;
	if (alx_node_write(*node, data, size))
		goto enomem;

	return	0;
enomem:
	alx_node_deinit(*node);
	*node	= NULL;
	return	ENOMEM;
}

int	alx_node_init_empty	(struct Alx_Node **node)
{

	if (alx_mallocarrays(node, 1))
		return	ENOMEM;
	(*node)->buf	= NULL;
	(*node)->left	= NULL;
	(*node)->right	= NULL;
	(*node)->parent	= NULL;
	(*node)->dup	= 0;

	return	0;
}

int	alx_node_init_clone	(struct Alx_Node **restrict clone,
				 const struct Alx_Node *restrict ref)
{

	if (!ref) {
		*clone	= NULL;
		return	ENOANO;
	}

	if (alx_node_init_empty(clone))
		goto enomem;

	if (alx_dynbuf_init_clone(&(*clone)->buf, ref->buf) == ENOMEM)
		goto enomem;
	(*clone)->dup	= ref->dup;

	return	0;
enomem:
	alx_node_deinit(*clone);
	*clone	= NULL;
	return	ENOMEM;
}

void	alx_node_deinit		(struct Alx_Node *node)
{

	if (!node)
		return;

	alx_dynbuf_deinit(node->buf);
	node->buf	= NULL;
	free(node);
}

int	alx_node_write		(struct Alx_Node *node,
				 const void *data, ssize_t size)
{
	return	alx_dynbuf_write(node->buf, 0, data, size);
}

ssize_t	alx_node_read		(void *data, ssize_t size,
				 const struct Alx_Node *node)
{
	return	alx_dynbuf_read(data, size, node->buf, 0);
}

int	alx_node_get_data	(void **restrict data,
				 struct Alx_Node *node)
{

	if (!node->buf) {
		*data	= NULL;
		return	ENOANO;
	}
	*data	= node->buf->data;
	return	0;
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
