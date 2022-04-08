/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** get_pos
*/

#include "local.h"

static void find_big_pos(char **smap, vect_t *pos, int x, int y)
{
    if (smap[y][x] == '\0' || smap[y][x] == 1)
        return;
    if (x > pos->x)
        pos->x = x;
    if (y > pos->y)
        pos->y = y;
}

static void find_small_pos(char **smap, vect_t *pos, int x, int y)
{
    if (smap[y][x] == '\0' || smap[y][x] == 1)
        return;
    if (x < pos->x)
        pos->x = x;
    if (y < pos->y)
        pos->y = y;
}

vect_t get_tetrimino_end_pos(char **smap)
{
    vect_t pos = {0};

    for (int y = 0; smap[y] != NULL; y++) {
        for (int x = 0; smap[y][x] != '\0'; x++) {
            find_big_pos(smap, &pos, x, y);
        }
    }
    pos.x++;
    pos.y++;
    return pos;
}

vect_t get_tetrimino_pos(char **smap)
{
    vect_t pos = {0};

    for (pos.y = 0; smap[pos.y] != NULL; pos.y++)
        for (pos.x = 0; smap[pos.y][pos.x] != '\0'; pos.x++);
    for (int y = 0; smap[y] != NULL; y++) {
        for (int x = 0; smap[y][x] != '\0'; x++) {
            find_small_pos(smap, &pos, x, y);
        }
    }
    return pos;
}
