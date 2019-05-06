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

    assert(list == NULL); //no need to test list->first and other node.
    //todo memory tests.

    PRINT_PASSED_INFO();
}

static void test_list_isempty()
{
    list_y list;
    list_init(&list);

    assert(list_isempty(list) == true);

    // prepare three nodes
    node_y *first = malloc(sizeof(node_y));
    first->data = 1;
    first->next = NULL;

    list->first = first;
    assert(list_isempty(list) == false);

    //todo: test about appending.
    PRINT_PASSED_INFO();
    list_free(&list);

}

static void test_list_clear()
{
    list_y list = NULL;

    assert(list_clear(&list) == -1);
    list_init(&list);

    assert(list_clear(&list) == 0);

    //todo: test about appending.

    PRINT_PASSED_INFO();
    list_free(&list);
}

static void test_list_size()
{
    list_y list = NULL;
    list_init(&list);

    assert(list_size(list) == 0);

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

    assert(list_size(list) == 3);
    list_free(&list);

    assert(list_size(list) == 0);

    PRINT_PASSED_INFO();
}

int main()
{
    test_list_init();
    test_list_free();
    test_list_isempty();
    test_list_clear();
    test_list_size();

    PRINT_ALL_PASSED_INFO(list);
}
