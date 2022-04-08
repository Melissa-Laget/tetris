/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** colision
*/

#include "local.h"

static int move_char_valid(game_t *game, vect_t pos, int x, int y)
{
    if (pos.x + x > game->width - 1 || pos.x + x < 0 ||
        pos.y + y > game->height - 1 || pos.y + y < 0 ||
        pos.x > game->width - 1 || pos.x < 0 ||
        pos.y > game->height - 1 || pos.y < 0)
        return -1;
    if (game->map[pos.y + y][pos.x + x] == 1)
        return 1;
    return 0;
}

static bool can_move_char(game_t *game, vect_t pos, int x, int y)
{
    if (game->smap[pos.y][pos.x] == 1 ||
        game->smap[pos.y][pos.x] == 0)
        return true;
    if (move_char_valid(game, pos, x, y) != 1)
        return false;
    return true;
}

static void move_char(game_t *game, vect_t pos, int x, int y)
{
    if (game->smap[pos.y][pos.x] == 1 ||
        game->smap[pos.y][pos.x] == '\0')
        return;
    game->smap[pos.y + y][pos.x + x] = game->smap[pos.y][pos.x];
    game->smap[pos.y][pos.x] = 1;
}

void move_all_char(game_t *game, int x, int y)
{
    vect_t pos = {0, 0};
    int start_x_pos = ((x >= 0) ? (game->width - 1) : 0);
    int start_y_pos = ((y >= 0) ? (game->height - 1) : 0);
    int end_x_pos = ((x >= 0) ? -1 : (game->width));
    int end_y_pos = ((y >= 0) ? -1 : (game->height));
    int add_x_pos = ((x >= 0) ? -1 : 1);
    int add_y_pos = ((y >= 0) ? -1 : 1);

    for (pos.y = start_y_pos; pos.y != end_y_pos; pos.y += add_y_pos) {
        for (pos.x = start_x_pos; pos.x != end_x_pos; pos.x += add_x_pos) {
            move_char(game, pos, x, y);
        }
    }
}

int move_item(game_t *game, int x, int y)
{
    bool can_move = true;

    for (vect_t pos = {0, game->height - 1}; pos.y >= 0 &&
        can_move == true; pos.y--) {
        for (pos.x = game->width - 1; pos.x >= 0 && can_move == true; pos.x--) {
            can_move = can_move_char(game, pos, x, y);
        }
    }
    if (can_move == false)
        return 0;
    move_all_char(game, x, y);
    draw_game(game);
    return 1;
}
