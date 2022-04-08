/*
** EPITECH PROJECT, 2022
** structure
** File description:
** add at position
*/

#include "list.h"

list_t *proccess_list_add_circ(list_t *start, list_t *end, void *data)
{
    list_t *elem = NULL;

    if (start == NULL || end == NULL || start->next != end)
        return NULL;
    elem = list_init(data);
    if (elem == NULL)
        return NULL;
    start->next = elem;
    end->prev = elem;
    elem->next = end;
    elem->prev = start;
    return start;
}

static list_t *proccess_list_add_stdr(list_t *start, list_t *end, void *data)
{
    if (start == NULL)
        return NULL;
    if (list_get_size(start) < 2 || end == NULL)
        return list_append(start, data);
    else
        return proccess_list_add_circ(start, end, data);
}

static list_t *proccess_list_add_first(list_t *list, void *data)
{
    list->prev = list_init(data);
    if (list->prev == NULL)
        return NULL;
    list->prev->next = list;
    list = list->prev;
    return list;
}

list_t *list_add(list_t *list, void *data, int pos)
{
    list_t *start = NULL;
    list_t *end = NULL;

    if (list == NULL || pos < 0)
        return NULL;
    if (pos == 0 && list->prev == NULL) {
        return proccess_list_add_first(list, data);
    }
    start = list_get_elem(list, pos - 1);
    end = list_get_elem(list, pos);
    if (start == NULL)
        return NULL;
    if (list_is_circ(list) == true) {
        start = proccess_list_add_circ(start, end, data);
    } else
        start = proccess_list_add_stdr(start, end, data);
    if (start == NULL)
        return NULL;
    return list;
}
