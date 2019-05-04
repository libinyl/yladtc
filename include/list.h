#ifndef YL_LIST_H
#define YL_LIST_H

#include "def.h"


typedef int VAL;

typedef struct _list
{
    VAL *data;      // data space for storage
    UINT capacity;  // entire memory size,including empty positon
    UINT size;      // actual number of data
} list_y;

/**
 * Initialize the list.
 *
 * Node:you must call this function whenever you want to
 * use the declared list, otherwise the behavior is undefined.
 *
 * @param list the list to be initialized.
 * @return -1 if memory allocation falied, otherwise return 0.
 */
int list_init(list_y *list);

int list_free(list_y *list);

int list_isempty(list_y *list);

int list_append(list_y *list, VAL value);

#endif //LIST_H