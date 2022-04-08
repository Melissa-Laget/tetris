/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** put_char_arr_on_char_arr
*/

#include "local.h"

int my_biggest_str(char **arr)
{
    int size = 0;
    int tmp = 0;

    if (arr == NULL)
        return 0;
    for (int i = 0; arr[i] != NULL; i++) {
        if ((tmp = my_strlen(arr[i])) > size)
            size = tmp;
    }
    return size;
}

char **put_char_arr_on_char_arr(char **dest, char **src, int x, int y)
{
    vect_t dest_size = {.x = my_biggest_str(dest),
    .y = my_char_tabl_len(dest) - 1};
    vect_t src_size = {.x = my_biggest_str(src),
    .y = my_char_tabl_len(src) - 1};

    if (dest == NULL || src == NULL)
        return dest;
    if (src_size.x + x > dest_size.x || src_size.y + y > dest_size.y)
        return dest;
    for (int pos_y = y; pos_y <= dest_size.y &&
        src[pos_y - y] != NULL; pos_y++) {
        for (int pos_x = x; pos_x <= dest_size.x &&
            src[pos_y - y][pos_x - x] != '\0'; pos_x++) {
            dest[pos_y][pos_x] = (
            src[pos_y - y][pos_x - x] == '\0' || src[pos_y - y][pos_x - x] == 1
            ) ? dest[pos_y][pos_x] : src[pos_y - y][pos_x - x];
        }
    }
    return dest;
}
