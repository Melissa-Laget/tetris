/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-antman-killian1.lelong
** File description:
** duplicate
*/

#include "list.h"

list_t *list_duplicate(list_t *list)
{
    list_t *newlist = NULL;
    list_t *tmplist = list;

    if (list == NULL)
        return NULL;
    do {
        newlist = list_append(newlist, tmplist->data);
        tmplist = tmplist->next;
    } while (tmplist != NULL && tmplist != list);
    return newlist;
}

list_t *list_nduplicate(list_t *list, int size)
{
    list_t *newlist = NULL;
    list_t *tmplist = list;
    int list_size = 0;
    int i = 0;

    if (list == NULL)
        return NULL;
    list_size = list_get_size(list);
    if (list_size < size)
        return NULL;
    do {
        newlist = list_append(newlist, tmplist->data);
        tmplist = tmplist->next;
        i++;
    } while (tmplist != NULL && tmplist != list && i < size);
    return newlist;
}
