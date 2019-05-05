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

//node_y *list_append(node_y *head, node_y *newnode);

//void list_free(node_y *phead);

//int list_append(list_y *list, VAL value);

//int list_size(const list_y list);

//int list_get(const list_y list, uint index, VAL *value);

#endif //LIST_H
