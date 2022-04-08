/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** event
*/

#include "local.h"

int drop_item(game_t *game)
{
    while (move_item(game, 0, 1) == 1);
    return 0;
}

int push_item(game_t *game)
{
    vect_t pos = get_tetrimino_pos(game->smap);
    tetrimino_t *tmp = game->cur_tetrimino;

    game->cur_tetrimino = game->next_tetrimino;
    game->next_tetrimino = tmp;
    game->smap = clear_map(game->smap);
    game->smap = put_char_arr_on_char_arr(game->smap,
    game->cur_tetrimino->tetrimino, pos.x, pos.y);
    return 0;
}

int gravity(game_t* game)
{
    if (game->tick < MIN_SPEED - (game->flags.level / MAX_LEVEL)) {
        game->tick = game->tick + 1;
        return 1;
    }
    game->tick = 0;
    game->flags.level++;
    return move_item(game, 0, 1);
}

int analyze_input(game_t *game)
{
    int key = getch();

    if (game->status == 1 && key == game->flags.key_left)
        return move_item(game, -1, 0);
    if (game->status == 1 && key == game->flags.key_right)
        return move_item(game, 1, 0);
    if (game->status == 1 && key == game->flags.key_drop)
        return drop_item(game);
    if (game->status == 1 && key == game->flags.key_next)
        return push_item(game);
    if (game->status == 1 && key == game->flags.key_turn)
        return rotate_tetrimino(game);
    if (key == game->flags.key_quit)
        game->status = 0;
    if (key == game->flags.key_pause)
        game->status = ((game->status == 2) ? 1 : 2);
    return 0;
}
