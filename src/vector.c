#include "vector.h"
#include <stdlib.h>


const uint VECTOR_INIT_SIZE = 16;  // default capacity size

int vector_init(vector_y *vector)
{
    if (!(vector->data = malloc(VECTOR_INIT_SIZE * sizeof(VAL)))) {
        return -1;
    }
    vector->capacity = VECTOR_INIT_SIZE;
    vector->size = 0;
    return 0;
}

int vector_free(vector_y *vector)
{
    if (!vector->data) {
        return -1;
    }

    free(vector->data);
    vector->data = NULL;
    return 0;
}

int vector_isempty(const vector_y *vector)
{
    return vector->size == 0;
}

int _resize(vector_y *vector)
{
    int msize = 2 * vector->capacity * sizeof(VAL);
    if (!(vector->data = realloc(vector->data, msize))) {
        return -1;
    }

    vector->capacity *= 2;
    return 0;
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
                return -1;
        }

        newpos = vector->data + vector->size;
    }

    // set the new value
    *(newpos) = value;
    ++vector->size;

    return 0;

}

int vector_get(const vector_y *vector, uint index, VAL *value)
{
    if (vector->size == 0 || vector->data == NULL)
        return -1;

    *value = *(vector->data + index);

    return 0;
}

int vector_set(vector_y *vector, uint index, VAL value)
{
    if (vector->data == NULL || index + 1 > vector->size )
        return -1;

    *(vector->data + index) = value;
}