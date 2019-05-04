#ifndef LIST_H
#define LIST_H

#include "def.h"

typedef struct _node
{
    VAL data;
    struct _node *next;
} node_y, *list_y;

/**
 * Initialize the list.
 *
 * This function allocate a node called header.
 * The header won't store data, therefore it
 * does not count.
 *
 * @param list
 * @return
 */
int list_init(list_y *list);

int list_free(list_y *list);

int list_append(list_y *list, VAL value);

int list_size(list_y list);

int list_get(list_y list, uint index, VAL *value);

#endif //LIST_H
