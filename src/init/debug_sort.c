/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** debug_sort
*/

#include "local.h"

int find_elem_pos(list_t *list)
{
    list_t *tmplist = list->next;
    int position = 0;

    do {
        if (my_strcmp((char *)list->data, (char *)tmplist->data) < 0)
            position += 1;
        tmplist = tmplist->next;
    } while (tmplist != list);
    return position;
}

int *insertion_sorting(list_t *list, int size)
{
    list_t *tmplist = list_transform_circ(list);
    int *position = malloc(sizeof(int) * (size + 1));
    int i = 0;

    do {
        position[i] = find_elem_pos(tmplist);
        tmplist = tmplist->next;
        i++;
    } while (tmplist != list);
    position[size] = -1;
    list = list_transform_stdr(list);
    return position;
}

list_t *debug_sort(list_t *list, game_t *game)
{
    int size = list_get_size(list);
    int *position = insertion_sorting(list, size);
    list_t *newlist = NULL;
    int j = 0;

    for (int i = 0; i < size; i++) {
        for (j = 0; position[j] != i && j < size; j++);
        newlist = list_append(newlist, (list_get_elem(list, j))->data);
    }
    game->nb_tetriminos = size;
    if (game->flags.debug == true)
        my_printf("Number of tetriminos: %d\n", game->nb_tetriminos);
    list_free(list, false);
    free(position);
    return newlist;
}
