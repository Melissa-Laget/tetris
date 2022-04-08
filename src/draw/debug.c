/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget [WSL: Manjaro]
** File description:
** debug
*/

#include "local.h"

int display_debug_tetrimino(tetrimino_t *tetrimino)
{
    for (int i = 0; tetrimino->tetrimino[i] != NULL; i++) {
        for (int j = 0; tetrimino->tetrimino[i][j] != '\0'; j++)
            write(1, (tetrimino->tetrimino[i][j] == 1) ? " " : "*", 1);
        write(1, "\n", 1);
    }
    return 0;
}

int display_debug(char *file_path, tetrimino_t *tetrimino, game_t *game)
{
    int count = 0;

    if (game->flags.debug == false)
        return ((tetrimino == NULL) ? 0 : 1);
    file_path = &file_path[11];
    for (int i = 0; file_path[i] != '\0'; i++) {
        if (file_path[i] == '.')
            count = i;
    }
    my_printf("Tetriminos '");
    my_put_nstr(file_path, count);
    my_printf("': ");
    if (tetrimino == NULL) {
        my_printf("error\n");
        return 0;
    }
    my_printf("size %d*%d, color %d\n", tetrimino->width, tetrimino->height,
    tetrimino->color);
    display_debug_tetrimino(tetrimino);
    return 1;
}

static char *get_key_string(int key)
{
    char *key_string[] = {
        "KEY_DOWN",
        "KEY_UP",
        "KEY_LEFT",
        "KEY_RIGHT",
    };
    int key_code[] = {258, 259, 260, 261};
    int nb_code = 4;
    static char default_key[] = "\0";

    for (int i = 0; i < nb_code; i++) {
        if (key == key_code[i]) {
            return key_string[i];
        }
    }
    default_key[0] = key;
    return default_key;
}

void flag_debug(flags_t *flags)
{
    if (flags->debug == false)
        return;
    my_printf("Key left: %s (%d)\n", get_key_string(flags->key_left),
    flags->key_left);
    my_printf("Key right: %s (%d)\n", get_key_string(flags->key_right),
    flags->key_right);
    my_printf("Key turn: %s (%d)\n", get_key_string(flags->key_turn),
    flags->key_turn);
    my_printf("Key drop: %s (%d)\n", get_key_string(flags->key_drop),
    flags->key_drop);
    my_printf("Key quit: %s (%d)\n", get_key_string(flags->key_quit),
    flags->key_quit);
    my_printf("Key pause: %s (%d)\n", get_key_string(flags->key_pause),
    flags->key_pause);
    my_printf("Next: %s\n", flags->without_next ? "No" : "Yes");
    my_printf("Level: %d\n", flags->level);
    my_printf("Size: %d*%d\n", flags->map_size.y, flags->map_size.x);
    my_printf("\n");
    return;
}
