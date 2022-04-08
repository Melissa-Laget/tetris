/*
** EPITECH PROJECT, 2022
** structure
** File description:
** del at at position (negatif will go in reverse)
*/

#include "list.h"

list_t *list_del_current(list_t *list, bool free_data)
{
    list_t *list_bak = NULL;

    if (list == NULL)
        return NULL;
    if (list->prev != NULL)
        list->prev->next = list->next;
    if (list->next != NULL)
        list->next->prev = list->prev;
    if (list->next != NULL)
        list_bak = list->next;
    else if (list->prev != NULL)
        list_bak = list->prev;
    if (list_free_current(list, free_data) != 0)
        return NULL;
    return list_bak;
}

list_t *list_del(list_t *list, int pos, bool free_data)
{
    list_t *list_bak = list;

    if (list == NULL)
        return NULL;
    list = list_get_elem(list, pos);
    if (list == NULL)
        return NULL;
    if (list == list_bak && list->next != NULL)
        list_bak = list->next;
    list = list_del_current(list, free_data);
    if (list == NULL)
        return NULL;
    return list_bak;
}
