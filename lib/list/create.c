/*
** EPITECH PROJECT, 2022
** structure
** File description:
** create list for a size
*/

#include "list.h"

static int get_arr_arr_size(void **arr)
{
    int count = 1;

    if (arr == NULL)
        return 0;
    if (arr[0] == NULL)
        return 1;
    if (sizeof(arr[0]) != sizeof(NULL))
        return -84;
    for (count = 1; arr[count] != NULL; count++);
    return count;
}

list_t *list_create(void *data, int size)
{
    list_t *list = list_init(data);
    list_t *list_bak = list;

    for (int i = 0; i < size; i++) {
        list->next = list_init(data);
        if (list->next == NULL)
            return NULL;
        list->next->prev = list;
        list = list->next;
    }
    return list_bak;
}

list_t *list_create_circ(void *data, int size)
{
    list_t *list = list_create(data, size);
    list_t *list_bak = list;

    if (list == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
        list = list->next;
    list->next = list_bak;
    list_bak->prev = list;
    return list_bak;
}

list_t *list_create_from_table(void **data)
{
    list_t *list = list_init(data[0]);
    list_t *list_bak = list;
    int size = get_arr_arr_size(data);

    if (list == NULL || size == -84)
        return NULL;
    for (int i = 0; i < size; i++) {
        list->next = list_init(data[i]);
        if (list->next == NULL)
            return NULL;
        list->next->prev = list;
        list = list->next;
    }
    return list_bak;
}
