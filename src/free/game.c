/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** game
*/

#include "local.h"

void free_game(game_t* game)
{
    free_arr((void **)game->map);
    free_arr((void **)game->smap);
    for (int i = 0; game->tetriminos[i] != NULL; i++)
        free_arr((void **)game->tetriminos[i]->tetrimino);
    free_arr((void **)game->tetriminos);
    free(game);
    endwin();
}
