#include "list.h"
#include <stddef.h>
#include <stdlib.h>

void _movetoindex(list_y header, uint index, node_y *node)
{
    node_y *out = header;
    // move (index+1) steps.
    while (index > -1) {
        out = out->next;
        index--;
    }
}

int list_init(list_y *list)
{
    // allocate space for header node
    if (!(*list = malloc(sizeof(node_y))))
        return RT_FAILED;
    (*list)->next = NULL;
    return RT_SUCCEED;
}

int list_free(list_y *list)
{

}

int list_append(list_y *list, VAL value)
{
    node_y *head = *list;

    // iterate head to last.
    while (head->next != NULL)
        head = head->next;

    // then prepare head->next as the new node.
    if (!(head->next = malloc(sizeof(node_y))))
        return RT_FAILED;

    head->next->data = value;
    head->next->next = NULL;
    return RT_SUCCEED;
}

int list_size(list_y list)
{

    node_y *head = list;
    while (head->next != NULL)
        head = head->next;

    return head - list;
}

int list_get(list_y list, uint index, VAL *value)
{
    node_y *head = list;

    while (head->next != NULL)
        head = head->next;

    // index must be less than size.
    if (index >= head - list)
        return RT_FAILED;
    *value = (head + index + 1)->data;
    return RT_SUCCEED;
}