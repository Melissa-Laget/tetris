/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** map
*/

#include "local.h"

char **clear_map(char **map)
{
    for (int y = 0; map[y] != NULL; y++)
        for (int x = 0; map[y][x] != '\0'; x++)
            map[y][x] = 1;
    return map;
}

void draw_char(int x, int y, char color, int nb_colors)
{
    if (color == 0 || color == 1)
        return;
    if (nb_colors != 0) {
        if (color <= nb_colors + 2)
            attron(COLOR_PAIR(color));
    }
    mvaddch(y, x, '*');
    if (nb_colors != 0) {
        if (color <= nb_colors + 2)
            attroff(COLOR_PAIR(color));
    }
}

void draw_map(game_t *game, char **map, int x_offset, int y_offset)
{
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            draw_char(x + x_offset, y + y_offset, map[y][x], game->nb_colors);
        }
    }
}
