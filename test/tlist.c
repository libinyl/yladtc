#include "tdef.h"
#include "list.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


static void test_list_init()
{
    list_y list = NULL;
    list_init(&list);

    assert(list != NULL);
    assert(list->first == NULL);
    PRINT_PASSED_INFO();
}

static void test_list_free()
{
    list_y list;
    list_init(&list);

    // init two node
    node_y *first = malloc(sizeof(node_y));
    first->data = 1;

    node_y *second = malloc(sizeof(node_y));
    second->data = 2;
    second->next = NULL;

    node_y *third = malloc(sizeof(node_y));
    third->data = 3;
    third->next = NULL;

    list_y list_bak = list;

    // concat nodes.
    list->first = first;
    first->next = second;
    second->next = third;


    list_free(&list);

    assert(list == NULL);
    assert(list->first == NULL);    //段错误！
    assert(second->next == NULL);
    assert(first->next == NULL);
    assert(list_bak->first == NULL); //段错误！

    PRINT_PASSED_INFO();
}

int main()
{
    test_list_init();
    test_list_free();

    PRINT_ALL_PASSED_INFO(list);
}
