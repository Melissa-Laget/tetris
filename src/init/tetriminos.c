/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget [WSL: Manjaro]
** File description:
** tetriminos
*/

#include "local.h"

tetrimino_t *parse_tetriminos(tetrimino_t *tetrimino)
{
    if (tetrimino == NULL)
        return NULL;
    for (int y = 0; tetrimino->tetrimino[y] != NULL; y++) {
        for (int x = 0; tetrimino->tetrimino[y][x] != '\0'; x++) {
            tetrimino->tetrimino[y][x] = (tetrimino->tetrimino[y][x] == ' ') ?
            1 : (tetrimino->color + 2);
        }
    }
    return tetrimino;
}

int check_numbers(char **tetrimino_info, tetrimino_t *tetrimino)
{
    if (my_char_tabl_len(tetrimino_info) - 1 != 3)
        return -1;
    tetrimino->width = my_getnbr(tetrimino_info[0]);
    tetrimino->height = my_getnbr(tetrimino_info[1]);
    tetrimino->color = my_getnbr(tetrimino_info[2]);
    return 0;
}

int check_size (tetrimino_t *tetrimino, char **tetrimino_line)
{
    int size = 0;
    int tmp = 0;

    if (my_char_tabl_len(tetrimino_line) - 1 != tetrimino->height) {
        free_arr((void **)tetrimino->tetrimino);
        free(tetrimino);
        return -1;
    }
    for (int i = 0; tetrimino_line[i] != NULL; i++) {
        if ((tmp = my_strlen(tetrimino_line[i])) > size)
            size = tmp;
    }
    if (size != tetrimino->width) {
        free_arr((void **)tetrimino->tetrimino);
        free(tetrimino);
        return -2;
    }
    return 0;
}

tetrimino_t *get_tetrimino(char *tetrimino_str)
{
    tetrimino_t *tetrimino = malloc(sizeof(tetrimino_t));
    char **tetrimino_line = NULL;
    char **tetrimino_info = NULL;

    if (tetrimino == NULL)
        return NULL;
    tetrimino_line = str_to_array(tetrimino_str, "\n");
    if (str_with_str(tetrimino_line[0], " 0123456789") == 0)
        return NULL;
    tetrimino_info = str_to_array(tetrimino_line[0], " ");
    if (check_numbers(tetrimino_info, tetrimino) != 0)
        return NULL;
    tetrimino->tetrimino = duplicate_char_arr(&tetrimino_line[1]);
    tetrimino->tetrimino = clean_array(tetrimino->tetrimino);
    tetrimino = (check_size(tetrimino, tetrimino->tetrimino) < 0) ?
    NULL : tetrimino;
    free_arr((void **)tetrimino_line);
    free_arr((void **)tetrimino_info);
    return parse_tetriminos(tetrimino);
}

tetrimino_t *init_tetrimino(char *file_path)
{
    char *tetrimino_str = file_to_str(file_path);
    tetrimino_t *tetrimino = NULL;

    if (tetrimino_str == NULL)
        return NULL;
    if (my_strlen(tetrimino_str) <= 6) {
        free(tetrimino_str);
        return NULL;
    }
    if (str_with_str(tetrimino_str, "0123456789 *\n") == 0) {
        free(tetrimino_str);
        return NULL;
    }
    tetrimino = get_tetrimino(tetrimino_str);
    free(tetrimino_str);
    return tetrimino;
}
