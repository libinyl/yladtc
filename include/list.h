#ifndef LIST_H
#define LIST_H

#include "def.h"

typedef struct _list
{
    struct _node *first;
} *list_y;

typedef struct _node
{
    VAL data;
    struct _node *next;
} node_y;

int list_init(list_y *plist);

void list_free(list_y *plist);

#endif //LIST_H
