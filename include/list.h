#ifndef YL_LIST_H
#define YL_LIST_H

#include "def.h"


typedef int TYPE;

typedef struct _list
{
    TYPE *data;     // data space for storage
    UINT capacity;   // entire memory size,including empty positon
    UINT size;       // actual number of data
}list_y;

int list_init(list_y *list);

#endif //LIST_H