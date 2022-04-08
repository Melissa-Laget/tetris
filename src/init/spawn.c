/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** spawn
*/

#include "local.h"

tetrimino_t *get_rand_tetromino(game_t *game)
{
    int rand_int = (rand() % game->nb_tetriminos);

    return game->tetriminos[rand_int];
}

void renew_tetrimino(game_t *game)
{
    if (game->next_tetrimino == NULL)
        game->next_tetrimino = get_rand_tetromino(game);
    game->cur_tetrimino = game->next_tetrimino;
    game->next_tetrimino = get_rand_tetromino(game);
}

int spawn_new(game_t *game)
{
    game->smap = clear_map(game->smap);
    renew_tetrimino(game);
    put_char_arr_on_char_arr(game->smap, game->cur_tetrimino->tetrimino, 0, 0);
    return 0;
}
