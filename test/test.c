#include "vector.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void test_vector_init()
{
    vector_y vector;
    assert(vector_init(&vector) == 0);
    assert(vector.data != NULL);
    assert(vector.size == 0);
    assert(vector.capacity > 0);
    printf("[test_vector_init] passed.\n");

    free(vector.data);
    vector.data = NULL;
}

static void test_vector_free()
{
    vector_y vector;
    assert(vector_init(&vector) == 0);

    vector_free(&vector);
    assert(vector.data == NULL);

    printf("[test_vector_free] passed.\n");
}

static void test_vector_isempty()
{
    vector_y vector;
    assert(vector_init(&vector) == 0);
    assert(vector_isempty(&vector) == 1);

    vector_append(&vector, 1);
    assert(vector_isempty(&vector) == 0);

    printf("[test_vector_isempty] passed.\n");
    vector_free(&vector);
}

static void test_vector_append()
{
    vector_y vector;
    assert(vector_init(&vector) == 0);

    assert((vector.size == 0));

    assert(vector_append(&vector, 0) == 0);
    assert(vector.size == 1);

    assert(vector_append(&vector, 1) == 0);
    assert(vector.size == 2);

    assert(*(vector.data + 1) == 1);
    assert(*(vector.data) == 0);

    vector_free(&vector);

    vector_init(&vector);

    int largenum = 100000;
    for (int i = 0; i < largenum; i++) {
        vector_append(&vector, i);
    }
    assert(vector.size == largenum);

    for (int i = 0; i < largenum; i++) {
        /*
         * printf("%d ", *(vector.data + i));
         * if (i > 200 && i % 200 == 0) {
         *     printf("\n");
         * }
         */
        assert(*(vector.data + i) == i);
    }

    printf("[test_vector_append] passed.\n");
    vector_free(&vector);
}

static void test_vector_get()
{
    vector_y vector;
    assert(vector_init(&vector) == 0);

    int val;
    assert(vector_get(&vector, 1, &val) == -1);

    vector_append(&vector, 0);
    vector_append(&vector, 1);

    assert(vector_get(&vector, 1, &val) == 0);
    assert(val == 1);

    assert(vector_get(&vector, 0, &val) == 0);
    assert(val == 0);

    printf("[test_vector_get] passed.\n");
    vector_free(&vector);
}

static void test_vector_set()
{
    vector_y vector;
    assert(vector_init(&vector) == 0);

    assert(vector_set(&vector, 0, 0) == -1);

    int largenum = 10000;
    for (int i = 0; i < largenum; ++i) {
        vector_append(&vector, i);
    }
    for (int j = 0; j < largenum; ++j) {
        vector_set(&vector, j, 2 * j);
    }
    for (int k = 0; k < largenum; ++k) {
        int out;
        vector_get(&vector, k, &out);
        assert(out == 2 * k);
    }

    printf("[test_vector_set] passed.\n");
    vector_free(&vector);
}

int main()
{
    test_vector_init();
    test_vector_free();
    test_vector_isempty();
    test_vector_append();
    test_vector_get();
    test_vector_set();
    printf("===tests all passed.===\n");
    return 0;
}