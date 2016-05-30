#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

struct listnode {
    int value; /* Data */
    struct listnode *next; /* Next node */
};

struct listnode *list_createnode(int value);

#endif
