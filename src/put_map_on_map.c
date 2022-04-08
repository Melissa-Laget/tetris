/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** put_map_to_map
*/

#include "local.h"

bool put_char_on_map(char **map, char c, int x, int y)
{
    if (c == 1)
        return true;
    if (map[y][x] == 1) {
        map[y][x] = c;
        return true;
    }
    return false;
}

bool put_map_on_map(game_t* game)
{
    bool success = true;

    for (int y = 0; y < game->height && success; y++) {
        for (int x = 0; x < game->width && success; x++) {
            success = put_char_on_map(game->map, game->smap[y][x], x, y);
        }
    }
    if (success)
        clear_map(game->smap);
    return success;
}
