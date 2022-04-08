/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** local
*/

#include "tetris.h"

#ifndef LOCAL_H
    #define LOCAL_H

int my_tabl_len(void **tabl);
void draw_map(game_t *game, char **map, int x_offset, int y_offset);
void draw_hud(game_t *game, int x_offset, int y_offset);
void draw_game(game_t *game);
char **clear_map(char **map);
char **put_char_arr_on_char_arr(char **dest, char **src, int x, int y);
int spawn_new(game_t *game);
int move_item(game_t *game, int x, int y);
int gravity(game_t* game);
void free_arr(void **arr);
void free_game(game_t* game);
bool put_map_on_map(game_t* game);
int analyze_input(game_t *game);
int init_colors(void);
int my_biggest_str(char **arr);
char **del_map_line(char **map);
list_t *debug_sort(list_t *list, game_t *game);
void draw_hud_next(game_t *game, int x_offset, int y_offset);
vect_t get_tetrimino_pos(char **smap);
vect_t get_tetrimino_end_pos(char **smap);
int rotate_tetrimino(game_t *game);
char **clean_array(char **arr);
char **init_map(int size_x, int size_y);

#endif
