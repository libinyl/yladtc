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

    // prepare three nodes
    node_y *first = malloc(sizeof(node_y));
    first->data = 1;

    node_y *second = malloc(sizeof(node_y));
    second->data = 2;
    second->next = NULL;

    node_y *third = malloc(sizeof(node_y));
    third->data = 3;
    third->next = NULL;

    // concat the nodes.
    list->first = first;
    first->next = second;
    second->next = third;


    list_free(&list);

    assert(list == NULL); //no need to test list->first
    assert(second->next == NULL);
    assert(first->next == NULL);

    PRINT_PASSED_INFO();
}

int main()
{
    test_list_init();
    test_list_free();

    PRINT_ALL_PASSED_INFO(list);
}
