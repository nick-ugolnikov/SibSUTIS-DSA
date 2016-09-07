#include "rbtree.h"
#include <stdlib.h>
#include <stdio.h>

struct rbtree *rbtree_create(int key, char *value)
{
	struct rbtree *node = malloc(sizeof(*node));
	if (node != NULL)
	{
		node->key = key;
		node->value = value;
        node->color = 1; //root is always black

        node->parent = NULL;
        node->root = NULL;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

void rbtree_add(struct rbtree *tree, int key, char *value)
{
	if (tree == NULL)
	{
		return;
	}
	struct rbtree *parent;
	while (tree != NULL)
	{
		parent = tree;
		short int compare = scmp(key, parent->key);
		if (key > parent->key)
		{
			tree = tree->right;
		}
		else if (key < parent->key)
		{
			tree = tree->left;
		}
		else return;
	}
	struct rbtree *node = bstree_create(key, value);
	if (key > parent->key)
		{
			parent->right = node;
		}
		else
		{
			parent->left = node;
		}
}

struct rbtree *rbtree_lookup(struct rbtree *tree, int key)
{
	while (tree != NULL)
	{
		short int compare = scmp(key, tree->key);
		if (key == tree->key)
		{
			return tree;
		}
		if (key > tree->key)
		{
			tree = tree->right;
		}
		else tree = tree->left;
	}
	return tree;
}

// struct bstree *bstree_min(struct bstree *tree)
// {
// 	if (tree == NULL)
// 	{
// 		return tree;
// 	}
// 	while (tree->left != NULL)
// 	{
// 		tree = tree->left;
// 	}
// 	return tree;
// }

// struct bstree *bstree_max(struct bstree *tree)
// {
// 	if (tree == NULL)
// 	{
// 		return tree;
// 	}
// 	while (tree->right != NULL)
// 	{
// 		tree = tree->right;
// 	}
// 	return tree;
// }
