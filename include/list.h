#ifndef YL_LIST_H
#define YL_LIST_H

#include "def.h"


typedef int VAL;

typedef struct _list
{
    VAL *data;      // data space for storage
    uint capacity;  // entire memory size,including empty positon
    uint size;      // actual number of data
} list_y;

/**
 * Initialize the list.
 *
 * Node:you must call this function whenever you want to
 * use the declared list, otherwise the behavior is undefined.
 *
 * @param list the list to be initialized.
 * @return 0 if memory allocation succeed, otherwise return -1.
 */
int list_init(list_y *list);

/*
 * Free the memory space of the list.
 *
 * Note that you must call this function everytime
 * when you finished using the initicalized list.
 *
 */
int list_free(list_y *list);

int list_isempty(const list_y *list);

int list_append(list_y *list, VAL value);

/**
 *  Get value from the list by the specified index.
 *
 * @param list
 * @param index
 * @param value
 * @return 0 if the list is valid; otherwise return -1.
 */
int list_get(const list_y *list, uint index, VAL *value);

#endif //LIST_H