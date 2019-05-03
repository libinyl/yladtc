#include "list.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

void test_list_init()
{
    list_y list;
    list_init(&list);
    assert(list.data != NULL);
    assert(list.size==0);
    assert(list.capacity>0);
    printf("[test_list_init] passed.\n");
}

int main()
{
    test_list_init();
    printf("tests all passed.\n");
    return 0;
}