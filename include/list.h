#ifndef LIST_H
#define LIST_H

#include "def.h"

typedef struct _node
{
    VAL             data;
    struct _node    *next;
} node_y, list_y;

int list_init(list_y *list);


#endif //LIST_H
