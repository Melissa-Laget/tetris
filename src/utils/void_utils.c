/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** my_tabl_len
*/

#include <unistd.h>
#include <stdlib.h>
#include "local.h"

int my_tabl_len(void **tabl)
{
    int i = 0;

    if (tabl == NULL)
        return -1;
    if (tabl[0] == NULL)
        return 0;
    for (i = 0; tabl[i] != NULL; i++);
    return i;
}

void free_arr(void **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
    return;
}
