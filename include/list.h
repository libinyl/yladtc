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

/**
 * Check if the list is empty.
 * Assuming that the list is not a NULL pointer.
 *
 * @param list
 * @return
 */
bool list_isempty(list_y list);

/**
 * Clear the existed list.
 *
 * Note that the list struct itself won't be freed.
 *
 * @param plist
 * @return -1 if the list is NULL, otherwise return 0.
 */
int list_clear(list_y *plist);

/*
 * Get the size of the list.
 *
 * Assuming the list is valid, that is, if a node_y's next
 * is not NULL, it counts.
 *
 */
uint list_size(list_y list);

#endif //LIST_H
