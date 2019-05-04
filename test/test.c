#include "list.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void test_list_init()
{
    list_y list;
    assert(list_init(&list) == 0);
    assert(list.data != NULL);
    assert(list.size == 0);
    assert(list.capacity > 0);
    printf("[test_list_init] passed.\n");

    free(list.data);
    list.data = NULL;
}

static void test_list_free()
{
    list_y list;
    assert(list_init(&list) == 0);

    list_free(&list);
    assert(list.data == NULL);

    printf("[test_list_free] passed.\n");
}

static void test_list_isempty()
{
    list_y list;
    assert(list_init(&list) == 0);

    assert(list_isempty(&list) != 0);
    printf("[test_list_isempty] passed.\n");

    /* TODO: add more test case */
    list_free(&list);
}

static void test_list_append()
{
    list_y list;
    assert(list_init(&list) == 0);

    assert((list.size == 0));

    assert(list_append(&list, 0) == 0);
    assert(list.size == 1);

    assert(list_append(&list, 1) == 0);
    assert(list.size == 2);

    assert(*(list.data + 1) == 1);
    assert(*(list.data) == 0);

    list_free(&list);

    list_init(&list);

    int largenum = 100000;
    for (int i = 0; i < largenum; i++) {
        list_append(&list, i);
    }
    assert(list.size == largenum);

    for (int i = 0; i < largenum; i++) {
        /*
         * printf("%d ", *(list.data + i));
         * if (i > 200 && i % 200 == 0) {
         *     printf("\n");
         * }
         */
        assert(*(list.data + i) == i);
    }

    printf("[test_list_append] passed.\n");
    list_free(&list);
}

static void test_list_get()
{
    list_y list;
    assert(list_init(&list) == 0);

    int val;
    assert(list_get(&list, 1, &val) == -1);

    list_append(&list, 0);
    list_append(&list, 1);

    assert(list_get(&list, 1, &val) == 0);
    assert(val == 1);

    assert(list_get(&list, 0, &val) == 0);
    assert(val == 0);

    printf("[test_list_get] passed.\n");
    list_free(&list);
}

int main()
{
    test_list_init();
    test_list_free();
    test_list_isempty();
    test_list_append();
    test_list_get();
    printf("tests all passed.\n");
    return 0;
}