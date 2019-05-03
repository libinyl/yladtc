#include "list.h"
#include <stdlib.h>


const UINT LIST_INIT_SIZE = 16;  // default capacity size

int list_init(list_y *list)
{
    if (!(list->data = malloc(LIST_INIT_SIZE * sizeof(TYPE)))) {
        return -1;
    }
    list->capacity = LIST_INIT_SIZE;
    list->size = 0;
}