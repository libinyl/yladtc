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
}

int main()
{
    test_list_init();
    test_list_free();
    test_list_isempty();
    printf("tests all passed.\n");
    return 0;
}