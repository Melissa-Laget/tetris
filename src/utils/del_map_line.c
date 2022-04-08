/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** del_map_line
*/

#include "local.h"

static char **drop_lines(char **map, int size_x, int y)
{
    for (int i = y; i > 0; i--) {
        map[i] = map[i - 1];
    }
    map[0] = malloc(sizeof(char) * (size_x + 1));
    if (map[0] == NULL)
        return NULL;
    for (int i = 0; i < size_x; i++)
        map[0][i] = 1;
    map[0][size_x] = '\0';
    return map;
}

char **del_map_line(char **map)
{
    int size_x = my_biggest_str(map);
    int size_y = my_tabl_len((void **)map);

    for (int y = 0; y < size_y; y++) {
        if (is_in_str(map[y], 1) == 1)
            continue;
        free(map[y]);
        map[y] = NULL;
        if ((map = drop_lines(map, size_x, y)) == NULL)
            return NULL;
    }
    return map;
}
