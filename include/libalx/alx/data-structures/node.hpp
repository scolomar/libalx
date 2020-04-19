/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/node.hpp */

#if !defined(__cplusplus)
#warning	This header file should only be included in C++.  In C,	\
		include the header file of the same name and `.h`	\
		extension instead.
#endif


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Node
 *
 * Read  <libalx/alx/data-structures/node.h>  for documentation.
 */


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include <cstddef>

#include "libalx/base/compiler/restrict.hpp"
#include "libalx/alx/data-structures/dyn-buffer.hpp"


/******************************************************************************
 ******* define ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
struct	Alx_Node {
	struct Alx_Dyn_Buffer	*buf;
	struct Alx_Node		*left;
	struct Alx_Node		*right;
	struct Alx_Node		*parent;
};

extern	"C"
{
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_node_init		(struct Alx_Node **restrict node,
				 const void *restrict data, size_t size);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_node_init_empty	(struct Alx_Node **node);
void	alx_node_deinit		(struct Alx_Node *node);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_node_write		(struct Alx_Node *node,
				 const void *data, size_t size);
[[gnu::nonnull]]
int	alx_node_read		(void *data, size_t size
				 const struct Alx_Node *node);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
