/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** init
*/

#include "local.h"

int init_colors(void)
{
    int count = 2;
    int nb_colors = 0;

    start_color();
    if (has_colors() == false || COLORS == 0)
        return 0;
    nb_colors = my_compute_square_root(COLORS);
    for (int i = 0; i < nb_colors; i++) {
        for (int j = 0; j < nb_colors; j++) {
            init_pair(count, j, i);
            count++;
        }
    }
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    return COLORS;
}

game_t *init_game_default(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return NULL;
    game->map = NULL;
    game->smap = NULL;
    game->tetriminos = NULL;
    game->cur_tetrimino = NULL;
    game->next_tetrimino = NULL;
    game->nb_tetriminos = 0;
    game->status = 1;
    game->width = 20;
    game->height = 15;
    game->biggest_height = 0;
    game->biggest_width = 0;
    game->nb_colors = 0;
    game->spawn_new = true;
    game->tick = 0;
    return game;
}

char **init_map(int size_x, int size_y)
{
    char **map = malloc(sizeof(char*) * (size_y + 1));

    if (map == NULL)
        return NULL;
    for (int y = 0; y < size_y; y++) {
        map[y] = malloc(sizeof(char) * (size_x + 1));
        if (map[y] == NULL)
            return NULL;
        for (int x = 0; x < size_x; x++) {
            map[y][x] = 1;
        }
        map[y][size_x] = '\0';
    }
    map[size_y] = NULL;
    return map;
}

void find_biggest_tetrimino(game_t *game)
{
    int tmp = 0;

    for (int i  = 0; i < game->nb_tetriminos; i++) {
        if ((tmp = game->tetriminos[i]->width) > game->biggest_width)
            game->biggest_width = tmp;
        if ((tmp = game->tetriminos[i]->height) > game->biggest_height)
            game->biggest_height = tmp;
    }
}

game_t *init_game(flags_t *flags)
{
    game_t *game = init_game_default();

    if (game == NULL)
        return NULL;
    game->flags = *flags;
    game->tetriminos = load_tetrimino(game);
    if (game->tetriminos[0] == NULL)
        return NULL;
    game->nb_tetriminos = my_tabl_len((void**)game->tetriminos);
    find_biggest_tetrimino(game);
    if (game->biggest_height > flags->map_size.y ||
        game->biggest_width > flags->map_size.x) {
        free_game(game);
        return NULL;
    }
    game->height = flags->map_size.y;
    game->width = flags->map_size.x;
    game->map = init_map(game->width, game->height);
    game->smap = init_map(game->width, game->height);
    return game;
}
