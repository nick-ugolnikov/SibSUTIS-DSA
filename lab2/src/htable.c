#include "htable.h"
#include "service.h"
#include <string.h>

struct listnode *hashtab[HASH_SIZE];

unsigned int hash(char *s) // KP hash
{	
	unsigned int h = 0;
	char *p;
	for (p = s; *p != '\0'; p++)
	h = h * HASH_MUL + (unsigned int)*p;
	return h % HASH_SIZE;
}

unsigned int fnv_hash(char *key, int len)
{
    unsigned char *p = key;
    unsigned int h = 2166136261;
    int i;

    for (i = 0; i < len; i++)
    {
        h = (h * 16777619) ^ p[i];
    }

    return h % HASH_SIZE;
}

void hashtab_init(struct listnode **hashtab)
{
	int i;
	for (i = 0; i < HASH_SIZE; i++) 
	{
		hashtab[i] = NULL;
	}
}

void hashtab_add(struct listnode **hashtab, char *key, int value)
{
	struct listnode *node;
	unsigned int index = hash(key);
	// Вставка в начало списка
	node = malloc(sizeof(*node));
	if (node != NULL) 
	{	
		node->key = key;
		node->value = value;
		node->next = hashtab[index];
		hashtab[index] = node;
	}
}

void hashtab_add_fnv(struct listnode **hashtab, char *key, int value)
{
	struct listnode *node;
	unsigned int index = fnv_hash(key, strlen(key));
	// Вставка в начало списка
	node = malloc(sizeof(*node));
	if (node != NULL)
	{		
		node->key = key;
		node->value = value;
		node->next = hashtab[index];
		hashtab[index] = node;
	}
}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key)
{
	int index;
	struct listnode *node;
	index = hash(key);
	for (node = hashtab[index];	node != NULL; node = node->next)
	{
		if (scmp(node->key, key) == 0)
		return node;
	}
	return NULL;
}

void hashtab_delete(struct listnode **hashtab, char *key)
{
	int index;
	struct listnode *p, *prev = NULL;
	index = hash(key);
	for (p = hashtab[index]; p != NULL; p = p->next) 
	{
		if (scmp(p->key, key) == 0) 
		{
			if (prev == NULL)
				hashtab[index] = p->next;
			else
				prev->next = p->next;
			free(p);
			return;
		}
	prev = p;
	}
}

int collision(struct listnode **hashtab)
{
	int count = 0;
	struct listnode *startnode, *node;
	for (int i = 0; i < HASH_SIZE; i++)
	{
		startnode = hashtab[i];
		if ((startnode != NULL) && (startnode->next != NULL))
		{
			for (node = startnode->next; node != NULL; node = node->next)
			{
				count++;
			}
		}
	}
	return count;
}
