/*
** EPITECH PROJECT, 2022
** structure
** File description:
** append at end of list
*/

#include "list.h"

static list_t *list_append_stdr(list_t *list, void *data)
{
    list->next = list_init(data);
    if (list->next == NULL)
        return NULL;
    list->next->prev = list;
    return list;
}

list_t *list_append(list_t *list, void *data)
{
    list_t *list_bak = list;

    if (list == NULL) {
        list = list_init(data);
        return list;
    }
    list = list_get_end(list);
    if (list_is_circ(list_bak) == true)
        list = proccess_list_add_circ(list->prev, list, data);
    else
        list = list_append_stdr(list, data);
    if (list == NULL)
        return NULL;
    return list_bak;
}
