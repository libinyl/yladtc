#ifndef YL_LIST_H
#define YL_LIST_H

#include "def.h"


typedef int TYPE;

typedef struct _list
{
    TYPE *data;     // data space for storage
    UINT capacity;   // entire memory size,including empty positon
    UINT size;       // actual number of data
} list_y;

/**
 * Initialize the list.
 *
 * Node:you must call this function whenever you want
 * use the declared list, otherwise the behavior is undefined.
 *
 * @param list the list to be initialized.
 * @return -1 if memory allocation falied, otherwise return 1.
 */
int list_init(list_y *list);

#endif //LIST_H