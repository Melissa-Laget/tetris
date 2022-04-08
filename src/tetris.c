/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget [WSL: Manjaro]
** File description:
** tetris
*/

#include "local.h"

int game_loop(game_t *game)
{
    if (game->spawn_new == true) {
        spawn_new(game);
        game->spawn_new = false;
    }
    analyze_input(game);
    if (game->status > 1) {
        if (game->status == 3)
            draw_game(game);
        return 0;
    }
    if (gravity(game) != 1) {
        game->spawn_new = true;
        if (put_map_on_map(game) == false)
            return 1;
        game->map = del_map_line(game->map);
        if (game->map == NULL)
            return 2;
    }
    usleep(1000);
    return 0;
}

int init_window(game_t *game)
{
    if (initscr() == NULL)
        return 84;
    curs_set(0);
    timeout(0);
    noecho();
    game->nb_colors = init_colors();
    return 0;
}

int tetris(int argc, char **argv)
{
    game_t *game = NULL;
    flags_t flags;
    int status = 0;

    if (init_flags(argc, argv, &flags) == false)
        return 84;
    if ((game = init_game(&flags)) == NULL)
        return 84;
    if (flags.debug == true)
        game->status = 0;
    else {
        if (init_window(game) != 0)
            return 84;
    }
    while (game->status > 0)
        if ((status = (game_loop(game))) != 0)
            break;
    free_game(game);
    endwin();
    return status;
}
