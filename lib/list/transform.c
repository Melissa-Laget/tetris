/*
** EPITECH PROJECT, 2022
** structure
** File description:
** transform
*/

#include "list.h"

list_t *list_transform_stdr(list_t *list)
{
    if (list == NULL)
        return NULL;
    if (list_is_circ(list) == false)
        return list;
    list->prev->next = NULL;
    list->prev = NULL;
    return list;
}

list_t *list_transform_circ(list_t *list)
{
    list_t *start = NULL;
    list_t *end = NULL;

    if (list == NULL)
        return NULL;
    if (list_is_circ(list) == true)
        return list;
    start = list_get_start(list);
    end = list_get_end(list);
    if (start == NULL || end == NULL)
        return NULL;
    start->prev = end;
    end->next = start;
    return list;
}
