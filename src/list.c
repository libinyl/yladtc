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
    __list_free(pnode->next);
    pnode->next = NULL;
    free(pnode);
}

void list_free(list_y *plist)
{
    if(plist==NULL)
        return;

    list_y list = *plist;
    __list_free(list->first);
    list->first = NULL;
    //free(plist);
}
