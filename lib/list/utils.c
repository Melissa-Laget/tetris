/*
** EPITECH PROJECT, 2022
** structure
** File description:
** utils
*/

#include "list.h"

bool list_is_circ(list_t *list)
{
    bool is_circle = true;
    list_t *list_bak = list;

    if (list == NULL)
        return false;
    if (list->next != NULL && list->prev != NULL) {
        do {
            list = list->next;
            (list->next == NULL) ? is_circle = false : 1;
        } while (is_circle == true && list->next != list_bak);
    } else
        is_circle = false;
    return is_circle;
}

list_t *list_get_start(list_t *list)
{
    if (list == NULL)
        return NULL;
    if (list_is_circ(list) == true)
        return list;
    while (list->prev != NULL)
        list = list->prev;
    return list;
}

list_t *list_get_end(list_t *list)
{
    list_t *list_end = list;

    if (list == NULL)
        return NULL;
    if (list_is_circ(list) == true) {
        do {
            list_end = list_end->next;
        } while (list_end != list);
    } else {
        while (list_end->next != NULL)
            list_end = list_end->next;
    }
    return list_end;
}

int list_get_size(list_t *list)
{
    list_t *list_bak = list;
    int count = 0;

    if (list == NULL)
        return 0;
    do {
        list = list->next;
        count++;
    } while (list != NULL && list != list_bak);
    return count;
}

list_t *list_get_elem(list_t *list, int pos)
{
    int list_size = list_get_size(list);

    list = list_get_start(list);
    if (list == NULL || list_size == 0 ||
        list_size < pos || list_size < (pos * -1))
        return NULL;
    if (pos == 0)
        return list;
    if (pos > 0) {
        for (int i = 0; i < pos && list != NULL; i++)
            list = list->next;
    } else {
        list = list_get_end(list);
        for (int i = 1; i < pos && list != NULL; i++)
            list = list->prev;
    }
    return list;
}
