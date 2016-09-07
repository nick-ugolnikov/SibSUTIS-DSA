#include "bstree.h"
#include <stdlib.h>
#include <stdio.h>

struct bstree *bstree_create(char *key, int value)
{
	struct bstree *node = malloc(sizeof(*node));
	if (node != NULL)
	{
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

void bstree_add(struct bstree *tree, char *key, int value)
{
	if (tree == NULL)
	{
		return;
	}
	struct bstree *parent, *node;
	while (tree != NULL)
	{
		parent = tree;
		short int compare = scmp(key, parent->key);
		if (compare > 0)
		{
			tree = tree->right;
		}
		else if (compare < 0)
		{
			tree = tree->left;
		}
		else return;
	}
	node = bstree_create(key, value);
	if (scmp(key, parent->key) > 0)
		{
			parent->right = node;
		}
		else
		{
			parent->left = node;
		}
}

struct bstree *bstree_lookup(struct bstree *tree, char *key)
{
	while (tree != NULL)
	{
		short int compare = scmp(key, tree->key);
		if (compare == 0)
		{
			return tree;
		}
		if (compare > 0)
		{
			tree = tree->right;
		}
		else tree = tree->left;
	}
	return tree;
}

struct bstree *bstree_min(struct bstree *tree)
{
	if (tree == NULL)
	{
		return tree;
	}
	while (tree->left != NULL)
	{
		tree = tree->left;
	}
	return tree;
}

struct bstree *bstree_max(struct bstree *tree)
{
	if (tree == NULL)
	{
		return tree;
	}
	while (tree->right != NULL)
	{
		tree = tree->right;
	}
	return tree;
}
