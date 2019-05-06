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

bool list_isempty(const list_y list)
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