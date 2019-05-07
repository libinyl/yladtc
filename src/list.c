#include "list.h"
#include <stddef.h>
#include <stdlib.h>

int list_init(list_y *plist)
{
    if (!(*plist = malloc(sizeof(struct _list))))
        return RT_FAILED;

    (*plist)->first = NULL;
    return RT_SUCCEED;
}

void __list_free(node_y *pnode)
{
    if (pnode == NULL) {
        return;
    }
    if (pnode->next == NULL) {
        free(pnode);
        return;
    }
    else {
        __list_free(pnode->next);
        pnode->next = NULL;
        free(pnode);
        return;
    }
}

void list_free(list_y *plist)
{
    if (plist == NULL)
        return;

    __list_free((*plist)->first);
    free(*plist);
    *plist = NULL;
}

bool list_isempty(list_y list)
{
    return list->first == NULL;
}

int list_clear(list_y *plist)
{
    if (plist == NULL || *plist == NULL)
        return RT_FAILED;

    __list_free((*plist)->first);
    (*plist)->first = NULL;
    return RT_SUCCEED;
}

uint list_size(list_y list)
{

    if (list == NULL)
        return 0;

    node_y *tmpnode = list->first;
    if (tmpnode == NULL)
        return 0;

    uint size = 1;
    while (tmpnode->next != NULL) {
        tmpnode = tmpnode->next;
        ++size;
    }

    return size;

}

int list_append(list_y *plist, VAL val)
{
    list_y list = *plist;
    if (list == NULL)
        return RT_FAILED;

    node_y *newnode = NULL;
    if (NULL == (newnode = malloc(sizeof(node_y))))
        return RT_FAILED;

    //config the new node.
    newnode->data = val;
    newnode->next = NULL;


    if (list->first == NULL) {
        // concat the nodes.
        list->first = newnode;
        list->first->next = NULL;
        return RT_SUCCEED;
    }

    // go to tail.
    node_y *tmpnode = list->first;

    while (tmpnode->next != NULL) {
        tmpnode = tmpnode->next;
    }
    tmpnode->next = newnode;

    return RT_SUCCEED;
}
