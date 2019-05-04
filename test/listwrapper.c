#include "list.h"
#include <stdio.h>

void list_printall(list_y *list)
{
    for (int i = 0; i < list->size; ++i) {
        printf("%d ", *(list->data + i));
    }
}