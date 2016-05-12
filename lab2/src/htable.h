#ifndef HTABLE
#define HTABLE

#include <stdio.h>
#include <stdlib.h>

#define HASH_MUL 31
#define HASH_SIZE 99971

struct listnode {
	char *key;
	int value;
	struct listnode *next;
};

unsigned int hash(char *s); // KP hash

unsigned int fnv_hash(char *key, int len);

void hashtab_init(struct listnode **hashtab);

void hashtab_add(struct listnode **hashtab, char *key, int value);

void hashtab_add_fnv(struct listnode **hashtab, char *key, int value);

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key);

void hashtab_delete(struct listnode **hashtab, char *key);

int collision(struct listnode **hashtab);

#endif
