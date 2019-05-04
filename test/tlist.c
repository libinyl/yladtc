#include "list.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define SUCCEED 1
#define FAILED  0

int test_list_init()
{
    list_y list = NULL;
    list_init(&list);

    assert(list != NULL);
    assert(list->next == NULL);
    assert(list_size(list) == 0);

    printf("[test_list_init] passed.\n");
}

static void test_list_get()
{
    list_y list = NULL;
    list_init(&list);

    list_append(&list, 0);
    list_append(&list, 1);

    int out = 0;
    assert(list_get(list, 0, &out) == SUCCEED);
    assert(out == 0);
    assert(list_get(list, 1, &out) == SUCCEED);
    assert(out == 1);

    //list_free();
}

int test_list_append()
{
    list_y list = NULL;
    list_init(&list);

    int largenum = 100000;
    for (int i = 0; i < largenum; ++i) {
        list_append(&list, i);
    }
    for (int j = 0; j < largenum; ++j) {

    }
}

int main()
{
    test_list_init();
    //test_list_add();
    printf("===Tests of [list] all passed.===\n");
}
