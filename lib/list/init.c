/*
** EPITECH PROJECT, 2022
** structure
** File description:
** init list (only one elem)
*/

#include "list.h"

list_t *list_init(void *data)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return NULL;
    list->next = NULL;
    list->prev = NULL;
    list->data = data;
    return list;
}

list_t *list_init_circ(void *data)
{
    list_t *list = list_init(data);

    if (list == NULL)
        return NULL;
    list->next = list;
    list->prev = list;
    return list;
}
