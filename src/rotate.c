/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** rotate
*/

#include "local.h"

bool my_array_cmp(char **arr1, char **arr2)
{
    vect_t size1 = {.x = my_biggest_str(arr1),
    .y = my_char_tabl_len(arr1) - 1};
    vect_t size2 = {.x = my_biggest_str(arr2),
    .y = my_char_tabl_len(arr2) - 1};
    bool equal = true;

    if (size1.x != size2.x || size1.y != size2.y)
        return false;
    for (int y = 0; y < size1.y && equal; y++) {
        for (int x = 0; x < size1.x && equal; x++)
            equal = (arr1[y][x] == arr2[y][x]) ? equal : false;
    }
    return equal;
}

char **rotate_tetrimino_arr(char **smap, vect_t start_pos, vect_t end_pos)
{
    vect_t size = {.x = (end_pos.x - start_pos.x),
    .y = (end_pos.y - start_pos.y)};
    char **res = malloc(sizeof(char *) * (size.x + 1));

    if (res == NULL)
        return NULL;
    for (int x = 0; x < size.x; x++) {
        res[x] = malloc(sizeof(char) * (size.y + 1));
        if (res[x] == NULL)
            return NULL;
        res[x][size.y] = '\0';
    }
    res[size.x] = NULL;
    for (int y = 0; y < size.y && smap[y + start_pos.y] != NULL; y++) {
        for (int x = 0; x < size.x &&
            smap[y + start_pos.y][x + start_pos.x] != '\0'; x++) {
            res[x][y] = smap[y + start_pos.y][x + start_pos.x];
        }
    }
    return res;
}

int check_map(game_t *game, char **empty, char **bak)
{
    if (my_array_cmp(game->smap, empty) == true) {
        free_arr((void **)game->smap);
        free_arr((void **)empty);
        game->smap = bak;
        return -1;
    }
    free_arr((void **)bak);
    free_arr((void **)empty);
    return 0;
}

int rotate_tetrimino(game_t *game)
{
    vect_t start_pos = get_tetrimino_pos(game->smap);
    vect_t end_pos = get_tetrimino_end_pos(game->smap);
    char **tetrimino = rotate_tetrimino_arr(game->smap, start_pos, end_pos);
    char **bak = duplicate_char_arr(game->smap);
    char **empty = init_map(game->width, game->height);

    if (tetrimino == NULL)
        return -1;
    game->smap = clear_map(game->smap);
    game->smap = put_char_arr_on_char_arr(game->smap, tetrimino,
    start_pos.x, start_pos.y);
    free_arr((void **)tetrimino);
    return check_map(game, empty, bak);
}
