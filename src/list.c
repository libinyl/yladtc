#include "list.h"
#include <stdlib.h>


const UINT LIST_INIT_SIZE = 16;  // default capacity size

int list_init(list_y *list)
{
    if (!(list->data = malloc(LIST_INIT_SIZE * sizeof(VAL)))) {
        return -1;
    }
    list->capacity = LIST_INIT_SIZE;
    list->size = 0;
    return 0;
}

int list_free(list_y *list)
{
    if (!list->data) {
        return -1;
    }

    free(list->data);
    list->data = NULL;
    return 0;
}

int list_isempty(list_y *list)
{
    return list->size == 0;
}

int _resize(list_y *list)
{
    int msize = 2 * list->capacity * sizeof(VAL);
    if (!(list->data = realloc(list->data, msize))) {
        return -1;
    }

    list->capacity *= 2;
    return 0;
}

int list_append(list_y *list, VAL value)
{
    VAL *newpos = NULL;

    if (list->size == 0) {
        newpos = list->data;
    }
    else {
        // resize if needed
        if (list->size == list->capacity) {
            if (!_resize(list))
                return -1;
        }

        newpos = list->data + 1; // leave list->data untouched
    }

    // set the new value
    *(newpos) = value;
    ++list->size;

    return 0;

}