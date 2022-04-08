/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** tetris
*/

#include <stdbool.h>
#include <stddef.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <getopt.h>
#include <ncurses.h>
#include "my.h"
#include "list.h"
#include "printf.h"
#include "printerr.h"

#ifndef TETRIS_H
    #define TETRIS_H

    #define MIN_SPEED 200
    #define MAX_LEVEL 10

typedef struct vect_s {
    int x;
    int y;
} vect_t;

typedef struct tetrimino_s {
    int height;
    int width;
    int color;
    char *name;
    char **tetrimino;
    vect_t pos;
} tetrimino_t;

typedef struct flags_s {
    int level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    int key_next;
    bool without_next;
    bool debug;
    vect_t map_size;
    bool help;
} flags_t;

typedef struct game_s {
    tetrimino_t **tetriminos;
    tetrimino_t *cur_tetrimino;
    tetrimino_t *next_tetrimino;
    int nb_tetriminos;
    char status;
    char **map;
    char **smap;
    int height;
    int width;
    int biggest_width;
    int biggest_height;
    int tick;
    bool spawn_new;
    flags_t flags;
    int nb_colors;
} game_t;

tetrimino_t **load_tetrimino(game_t *game);
int tetris(int argc, char **argv);
game_t *init_game(flags_t *flags);
char *file_to_str(char *filepath);
tetrimino_t *get_tetrimino(char *tetrimino_str);
tetrimino_t *init_tetrimino(char *file_path);
char **duplicate_char_arr(char **arr);
void *my_calloc(unsigned int size, void *data);
bool check_flags(int argc, char **argv, flags_t *flags);
bool init_flags(int argc, char **argv, flags_t *flags);
void check_help(char **argv);
int check_errors(int argc);
void flag_debug(flags_t *flags);
int display_debug(char *file_path, tetrimino_t *tetrimino, game_t *game);
bool check_nb(flags_t *flags);

#endif
