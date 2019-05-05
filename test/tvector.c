#include "tdef.h"
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

    PRINT_PASSED_INFO();

    free(vector.data);
}

static void test_vector_free()
{
    vector_y vector;
    assert(vector_init(&vector) == 0);

    vector_free(&vector);
    assert(vector.data == NULL);

    PRINT_PASSED_INFO();
}

static void test_vector_isempty()
{
    vector_y vector;
    assert(vector_init(&vector) == 0);
    assert(vector_isempty(&vector) == 1);

    vector_append(&vector, 1);
    assert(vector_isempty(&vector) == 0);

    PRINT_PASSED_INFO();
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
         * PRINT_PASSED_INFO();
         * if (i > 200 && i % 200 == 0) {
         *     PRINT_PASSED_INFO();
         * }
         */
        assert(*(vector.data + i) == i);
    }

    PRINT_PASSED_INFO();
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

    PRINT_PASSED_INFO();
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

    PRINT_PASSED_INFO();
    vector_free(&vector);
}

static void test_vector_remove()
{
    vector_y vector;
    assert(vector_init(&vector) == 0);

    int largenum = 10000;
    for (int i = 0; i < largenum; ++i) {
        vector_append(&vector, i);
    }

    int index1 = 100, index2 = 1000;
    vector_remove(&vector, index1);
    vector_remove(&vector, index2);

    assert(vector.size == largenum - 2);

    for (int j = 0; j < largenum - 2; ++j) {
        int out;
        vector_get(&vector, j, &out);
        if (j < index1) {
            assert(out == j);
        }
        if (j >= index1 && j < index2) {
            assert(out == j + 1);
        }
        if (j >= index2) {
            assert(out == j + 2);
        }
    }

    PRINT_PASSED_INFO();
}

int main()
{
    test_vector_init();
    test_vector_free();
    test_vector_isempty();
    test_vector_append();
    test_vector_get();
    test_vector_set();
    test_vector_remove();

    PRINT_ALL_PASSED_INFO(vector);
    return 0;
}