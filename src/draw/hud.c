/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** hud
*/

#include "local.h"

void draw_hud(game_t *game, int x_offset, int y_offset)
{
    attron(COLOR_PAIR(1));
    mvaddch(y_offset - 1, x_offset - 1, '/');
    for (int i = 0; i < game->width; i++)
        addch('-');
    addch('\\');
    for (int i = 0; i < game->height; i++) {
        mvaddch(y_offset + i, x_offset - 1, '|');
        mvaddch(y_offset + i, x_offset + game->width, '|');
    }
    mvaddch(y_offset + game->height, x_offset - 1, '\\');
    for (int i = 0; i < game->width; i++)
        addch('-');
    addch('/');
    attroff(COLOR_PAIR(1));
}

void draw_hud_next(game_t *game, int x_offset, int y_offset)
{
    attron(COLOR_PAIR(1));
    mvaddch(y_offset - 1, x_offset + game->width + 2, '/');
    for (int i = 0; i < game->biggest_width; i++)
        addch('-');
    addch('\\');
    for (int i = 0; i < game->biggest_height; i++) {
        mvaddch(y_offset + i, x_offset + game->width + 2, '|');
        mvaddch(y_offset + i, x_offset + game->width + 3 + game->biggest_width,
        '|');
    }
    mvaddch(y_offset + game->biggest_height, x_offset + game->width + 2, '\\');
    for (int i = 0; i < game->biggest_width; i++)
        addch('-');
    addch('/');
    attroff(COLOR_PAIR(1));
}
