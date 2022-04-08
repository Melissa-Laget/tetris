/*
** EPITECH PROJECT, 2022
** structure
** File description:
** free
*/

#include "list.h"

int list_free_current(list_t *elem_to_free, bool free_data)
{
    if (elem_to_free == NULL)
        return 1;
    if (free_data == true)
        free(elem_to_free->data);
    free(elem_to_free);
    return 0;
}

int list_free_elem(list_t *list, int pos, bool free_data)
{
    if (list == NULL)
        return 1;
    list = list_get_elem(list, pos);
    if (list == NULL)
        return 2;
    list->next = NULL;
    list->prev = NULL;
    if (free_data == true)
        free(list->data);
    free(list);
    return 0;
}

int list_free(list_t *list, bool free_data)
{
    list_t *next;

    if (list == NULL)
        return 1;
    while (list != NULL) {
        next = list->next;
        if (list_free_current(list, free_data) != 0)
            return 2;
        list = next;
    }
    return 0;
}
