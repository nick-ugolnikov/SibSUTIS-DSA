#ifndef BSTREE_H
#define BSTREE_H

struct bstree
{
	char *key;
	int value;
	struct bstree *left;
	struct bstree *right;
};

struct bstree *bstree_create(char *key, int value);

void bstree_delete(struct bstree *root);

void bstree_add(struct bstree *tree, char *key, int value);

struct bstree *bstree_lookup(struct bstree *tree, char *key);

struct bstree *bstree_min(struct bstree *tree);

struct bstree *bstree_max(struct bstree *tree);

short int scmp(char *str1, char *str2); // string compare

#endif
