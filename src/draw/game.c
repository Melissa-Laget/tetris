/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** game
*/

#include "local.h"

int draw_too_small(int col, int row)
{
    char msg[] = "window too small\0";

    clear();
    if (row < 1 || col < my_strlen(msg))
        return 0;
    if (mvprintw((row / 2), ((col / 2) - (my_strlen(msg) / 2)),
        msg) != 0)
        return -3;
    refresh();
    return 0;
}

vect_t get_size(void)
{
    static vect_t size = {0};

    getmaxyx(stdscr, size.y, size.x);
    return size;
}

vect_t get_offset(game_t *game, vect_t *size)
{
    static vect_t offset = {0};

    offset.x = (size->x / 2) - ((game->width + game->biggest_width + 3) / 2);
    offset.y = (size->y / 2) - (game->height / 2);
    return offset;
}

void draw_game(game_t *game)
{
    vect_t size = get_size();
    vect_t offset = get_offset(game, &size);

    if (size.x < game->width + game->biggest_width + 5 ||
        size.y < game->height + 2) {
        draw_too_small(size.x, size.y);
        game->status = 3;
        return;
    }
    game->status = 1;
    clear();
    draw_map(game, game->map, offset.x, offset.y);
    draw_map(game, game->smap, offset.x, offset.y);
    draw_hud(game, offset.x, offset.y);
    if (game->flags.without_next == false) {
        draw_map(game, game->next_tetrimino->tetrimino,
        offset.x + game->width + 3, offset.y);
        draw_hud_next(game, offset.x, offset.y);
    }
    refresh();
}
