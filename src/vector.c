#include "vector.h"
#include <stdlib.h>


const uint VECTOR_INIT_SIZE = 16;  // default capacity size

int vector_init(vector_y *vector)
{
    if (!(vector->data = malloc(VECTOR_INIT_SIZE * sizeof(VAL)))) {
        return RT_FAILED;
    }
    vector->capacity = VECTOR_INIT_SIZE;
    vector->size = 0;
    return RT_SUCCEED;
}

int vector_free(vector_y *vector)
{
    if (!vector->data) {
        return RT_FAILED;
    }

    free(vector->data);
    vector->data = NULL;
    return RT_SUCCEED;
}

bool vector_isempty(const vector_y *vector)
{
    return vector->size == 0;
}

int _resize(vector_y *vector)
{
    int msize = 2 * vector->capacity * sizeof(VAL);
    if (!(vector->data = realloc(vector->data, msize))) {
        return RT_FAILED;
    }

    vector->capacity *= 2;
    return RT_SUCCEED;
}

int vector_append(vector_y *vector, VAL value)
{
    VAL *newpos = NULL;

    if (vector->size == 0) {
        newpos = vector->data;
    }
    else {
        // resize if needed
        if (vector->size == vector->capacity) {
            if (_resize(vector))
                return RT_FAILED;
        }

        newpos = vector->data + vector->size;
    }

    // set the new value
    *(newpos) = value;
    ++vector->size;

    return RT_SUCCEED;

}

int vector_get(const vector_y *vector, uint index, VAL *value)
{
    if (vector->size == 0 || vector->data == NULL)
        return RT_FAILED;

    *value = *(vector->data + index);

    return RT_SUCCEED;
}

int vector_set(vector_y *vector, uint index, VAL value)
{
    if (vector->data == NULL || index < 0 || index >= vector->size)
        return RT_FAILED;

    *(vector->data + index) = value;

    return RT_SUCCEED;
}

int vector_remove(vector_y *vector, uint index)
{
    if (vector->data == NULL || index < 0 || index >= vector->size)
        return RT_FAILED;

    for (int i = index; i < vector->size - 1; ++i) {
        *(vector->data + i) = *(vector->data + 1 + i);
    }
    --vector->size;

    return RT_SUCCEED;
}