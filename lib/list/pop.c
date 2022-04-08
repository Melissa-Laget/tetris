/*
** EPITECH PROJECT, 2022
** structure
** File description:
** pop at end
*/

#include "list.h"

list_t *list_pop(list_t *list, bool free_data)
{
    list_t *list_bak = list;

    if (list == NULL)
        return NULL;
    list = list_get_end(list);
    if (list == NULL)
        return NULL;
    if (list_free_current(list, free_data) != 0)
        return NULL;
    return list_bak;
}
