#ifndef VECTOR_H
#define VECTOR_H

#include "def.h"

typedef struct _vector
{
    VAL *data;      // data space for storage
    uint capacity;  // entire memory size,including empty positon
    uint size;      // actual number of data
} vector_y;

/**
 * Initialize the vector.
 *
 * Node:you must call this function before whenever
 * using the declared (or just freed) vector,
 * otherwise the behavior is undefined.
 *
 * @param vector the vector to be initialized.
 * @return 0 if memory allocation succeed, otherwise return -1.
 */
int vector_init(vector_y *vector);

/*
 * Free the memory space of the vector.
 *
 * Note that you must call this function everytime
 * when you finished using the initicalized vector.
 *
 */
int vector_free(vector_y *vector);

int vector_isempty(const vector_y *vector);

int vector_append(vector_y *vector, VAL value);

/**
 *  Get value from the vector by the specified index.
 *
 * @param vector
 * @param index
 * @param value
 * @return 0 if the vector is valid; otherwise return -1.
 */
int vector_get(const vector_y *vector, uint index, VAL *value);

/**
 * Modify value from the vector by the specified index.
 * if index is out-of-bound,return -1.
 *
 * @param vector
 * @param index
 * @param value
 * @return -1 if the index if invalid, otherwise return 0.
 */
int vector_set(vector_y *vector, uint index, VAL value);

int vector_remove(vector_y *vector, uint index);

#endif //YL_VECTOR_H