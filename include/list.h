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
bool list_isempty(const list_y list);

/**
 * Clear the existed list.
 *
 * If the list is NULL,return -1.
 * @param plist
 * @return -1 if the list is NULL, otherwise return 0.
 */
int list_clear(list_y *plist);



#endif //LIST_H
