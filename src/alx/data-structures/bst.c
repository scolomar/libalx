/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include **************************************************************
 ******************************************************************************/
#include "libalx/alx/data-structures/bst.h"

#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include <sys/types.h>

#include "libalx/alx/data-structures/llist.h"
#include "libalx/alx/data-structures/node.h"
#include "libalx/alx/data-structures/types.h"
#include "libalx/base/compiler/unused.h"
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
/*
 * Deletes all the nodes below `node`.
 * If node is NULL, no operation is performed.
 *
 * node:	Pointer to a node in a BST.
 */
static
void	bst_delete_all			(struct Alx_Node *restrict node);

/*
 * Returns the leftmost node in the BST.
 *
 * node:	Pointer to a node.
 */
[[gnu::nonnull]] [[gnu::pure]] [[gnu::warn_unused_result]]
static
struct Alx_Node	*bst_leftmost_node	(struct Alx_Node *node);

/*
 * Returns the rightmost node in the BST.
 *
 * node:	Pointer to a node.
 */
[[gnu::nonnull]] [[gnu::pure]] [[gnu::warn_unused_result]]
static
struct Alx_Node	*bst_rightmost_node	(struct Alx_Node *node);

/*
 * Removes the left and right subtrees of a BST node, and joins them into a
 * new isolated BST.  Updates any necessary metadata.
 * Returns a pointer to the new BST.
 *
 * node:	Pointer to a node.
 */
[[gnu::nonnull]]
static
struct Alx_Node	*bst_join_L_R		(struct Alx_Node *restrict node);

/*
 * Helper function for alx_bst_apply()
 */
static
int	bst_apply_recursive		(struct Alx_Node *restrict node,
					 int (*f)(struct Alx_Node *restrict node,
						  void *restrict state),
					 void *restrict state);

/*
 * Helper function for alx_bst_apply_bwd()
 */
static
int	bst_apply_bwd_recursive		(struct Alx_Node *restrict node,
					 int (*f)(struct Alx_Node *restrict node,
						  void *restrict state),
					 void *restrict state);

/*
 * Helper function for alx_bst_to_llist()
 */
static
void	bst_to_llist_recursive		(struct Alx_Node *restrict bst,
					 struct Alx_LinkedList *restrict list);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_bst_init		(struct Alx_BST **restrict bst,
				 alx_bst_cmp_f *cmp, bool dup)
{

	if (alx_mallocarrays(bst, 1))
		return	ENOMEM;
	(*bst)->root	= NULL;
	(*bst)->nmemb	= 0;
	(*bst)->cmp	= cmp;
	(*bst)->dup	= dup;

	return	0;
}

void	alx_bst_deinit		(struct Alx_BST *bst)
{

	if (!bst)
		return;

	alx_bst_delete_all(bst);
	free(bst);
}

int	alx_bst_insert		(struct Alx_BST *restrict bst,
				 const void *restrict data, ssize_t size,
				 struct Alx_Node **restrict bstnode)
{
	struct Alx_Node	*node;

	if (alx_node_init(&node, data, size)) {
		*bstnode	= NULL;
		return		-ENOMEM;
	}
	return	alx_bst_insert_node(bst, node, bstnode);
}

int	alx_bst_insert_node	(struct Alx_BST *restrict bst,
				 struct Alx_Node *restrict node,
				 struct Alx_Node **restrict bstnode)
{
	enum		{LEFT, RIGHT};

	struct Alx_Node	*parent;
	struct Alx_Node	*son;
	int		pos;
	int		cmp_res;

	bst->nmemb++;

	if (bstnode)
		*bstnode	= node;

	node->left	= NULL;
	node->right	= NULL;

	if (!bst->root) {
		bst->root	= node;
		return	0;
	}

	son	= bst->root;
	while (son) {
		parent	= son;
		cmp_res	= bst->cmp(node->buf->data, parent->buf->data);
		if (cmp_res < 0) {
			son	= parent->left;
			pos	= LEFT;
		} else if (cmp_res > 0) {
			son	= parent->right;
			pos	= RIGHT;
		} else {
			if (!bst->dup) {
				parent->dup += node->dup + 1;
				bst->nmemb--;
				if (bstnode)
					*bstnode	= parent;
				return	EEXIST;
			}
			son	= parent->right;
			pos	= RIGHT;
		}
	}

	if (pos == LEFT)
		parent->left	= node;
	else
		parent->right	= node;
	node->parent	= parent;

	return	0;
}

void	alx_bst_delete_all	(struct Alx_BST *bst)
{

	bst_delete_all(bst->root);
	bst->nmemb	= 0;
}

int	alx_bst_leftmost_node	(struct Alx_Node **restrict node,
				 struct Alx_BST *restrict bst)
{

	*node	= bst->root;
	if (!bst->root)
		return	ENOENT;

	*node	= bst_leftmost_node(bst->root);

	return	0;
}

int	alx_bst_rightmost_node	(struct Alx_Node **restrict node,
				 struct Alx_BST *restrict bst)
{

	*node	= bst->root;
	if (!bst->root)
		return	ENOENT;

	*node	= bst_rightmost_node(bst->root);

	return	0;
}

int	alx_bst_find		(struct Alx_Node **restrict node,
				 struct Alx_BST *restrict bst,
				 const void *restrict data)
{
	struct Alx_Node	*parent;
	struct Alx_Node	*son;
	int			cmp_res;

	if (!bst->root)
		goto enoent;

	son	= bst->root;
	while (son) {
		parent	= son;
		cmp_res	= bst->cmp(data, parent->buf->data);
		if (cmp_res < 0) {
			son	= parent->left;
		} else if (cmp_res > 0) {
			son	= parent->right;
		} else {
			*node	= parent;
			return	0;
		}
	}

enoent:
	*node	= NULL;
	return	ENOENT;
}

int	alx_bst_remove		(struct Alx_Node **restrict node,
				 struct Alx_BST *restrict bst,
				 const void *restrict data)
{

	if (alx_bst_find(node, bst, data))
		return	ENOENT;
	alx_bst_remove_node(bst, *node);

	return	0;
}

void	alx_bst_remove_node	(struct Alx_BST *restrict bst,
				 struct Alx_Node *restrict node)
{

	if (!node)
		return;

	if (node == bst->root) {
		bst->root		= bst_join_L_R(node);
	} else if (node == node->parent->left) {
		node->parent->left	= bst_join_L_R(node);
	} else {	/* (node == node->parent->right) */
		node->parent->right	= bst_join_L_R(node);
	}

	node->left	= NULL;
	node->right	= NULL;
	node->parent	= NULL;

	bst->nmemb--;
}

int	alx_bst_apply		(struct Alx_BST *restrict bst,
				 int (*f)(struct Alx_Node *restrict node,
					  void *restrict state),
				 void *restrict state)
{
	return	bst_apply_recursive(bst->root, f, state);
}

int	alx_bst_apply_bwd	(struct Alx_BST *restrict bst,
				 int (*f)(struct Alx_Node *restrict node,
					  void *restrict state),
				 void *restrict state)
{
	return	bst_apply_bwd_recursive(bst->root, f, state);
}

int	alx_bst_reorder	(struct Alx_BST *restrict bst,
				 alx_bst_cmp_f *cmp)
{
	struct Alx_LinkedList	*list;

	if (alx_llist_init(&list))
		return	ENOMEM;

	alx_bst_to_llist(list, bst);
	bst->cmp	= cmp;
	alx_llist_to_bst(bst, list);

	alx_llist_deinit(list);
	return	0;
}

void	alx_bst_to_llist	(struct Alx_LinkedList *restrict list,
				 struct Alx_BST *restrict bst)
{

	bst_to_llist_recursive(bst->root, list);
	bst->root	= NULL;
	bst->nmemb	= 0;
}


/******************************************************************************
 ******* alias ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
void	bst_delete_all			(struct Alx_Node *restrict node)
{
	struct Alx_Node	*right;

	if (!node)
		return;

	bst_delete_all(node->left);
	right	= node->right;
	alx_node_deinit(node);
	bst_delete_all(right);
}

static
struct Alx_Node	*bst_leftmost_node	(struct Alx_Node *node)
{

	while (node->left)
		node	= node->left;

	return	node;
}

static
struct Alx_Node	*bst_rightmost_node	(struct Alx_Node *node)
{

	while (node->right)
		node	= node->right;

	return	node;
}

static
struct Alx_Node	*bst_join_L_R		(struct Alx_Node *restrict node)
{
	struct Alx_Node	*tmp;
	struct Alx_Node	*new;

	if (!node->left  &&  !node->right)
		return	NULL;
	if (!node->left) {
		new		= node->right;
		new->parent	= NULL;
		node->right	= NULL;
		return	new;
	}
	if (!node->right) {
		new		= node->left;
		new->parent	= NULL;
		node->left	= NULL;
		return	new;
	}

	new		= node->left;
	new->parent	= NULL;
	tmp		= bst_rightmost_node(new);
	tmp->right	= node->right;
	node->right->parent	= tmp;

	node->left	= NULL;
	node->right	= NULL;

	return	new;
}

static
int	bst_apply_recursive		(struct Alx_Node *restrict node,
					 int (*f)(struct Alx_Node *restrict node,
						  void *restrict state),
					 void *restrict state)
{
	struct Alx_Node	*right;
	int		status;

	if (!node)
		return	0;

	status	= bst_apply_recursive(node->left, f, state);
	if (status)
		return	status;

	right	= node->right;
	status	= f(node, state);
	if (status)
		return	status;

	return	bst_apply_recursive(right, f, state);
}

static
int	bst_apply_bwd_recursive		(struct Alx_Node *restrict node,
					 int (*f)(struct Alx_Node *restrict node,
						  void *restrict state),
					 void *restrict state)
{
	struct Alx_Node	*left;
	int		status;

	if (!node)
		return	0;

	status	= bst_apply_bwd_recursive(node->right, f, state);
	if (status)
		return	status;

	left	= node->left;
	status	= f(node, state);
	if (status)
		return	status;

	return	bst_apply_bwd_recursive(left, f, state);
}

static
void	bst_to_llist_recursive		(struct Alx_Node *restrict node,
					 struct Alx_LinkedList *restrict list)
{
	struct Alx_Node	*right;

	if (!node)
		return;
	bst_to_llist_recursive(node->left, list);
	right	= node->right;
	alx_llist_append_node(list, node);
	bst_to_llist_recursive(right, list);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
