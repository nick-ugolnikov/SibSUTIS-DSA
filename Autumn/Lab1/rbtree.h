#ifndef BSTREE_H
#define BSTREE_H

struct rbtree
{
	int key;
    char *value;
    short color; // 0 - red, 1 - black;

    struct rbtree *parent;
    struct rbtree *root;
	struct rbtree *left;
	struct rbtree *right;
};

struct rbtree *rbtree_create(int key, char *value);

//void bstree_delete(struct bstree *root);

void rbtree_add(struct rbtree *tree, int key, char *value);

struct rbtree *rbtree_lookup(struct rbtree *tree, int key);

// struct rbtree *rbtree_min(struct rbtree *tree);

// struct rbtree *rbtree_max(struct rbtree *tree);

#endif
