#include "vector.h"
#include <stdio.h>

void vector_printall(vector_y *vector)
{
    for (int i = 0; i < vector->size; ++i) {
        printf("%d ", *(vector->data + i));
    }
}