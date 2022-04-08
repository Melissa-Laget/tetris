/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget [WSL: Manjaro]
** File description:
** my_calloc
*/

#include <stdlib.h>
#include <stddef.h>

void *my_calloc(unsigned int size, void *data)
{
    void **res = malloc(sizeof(data) * (size + 1));

    for (unsigned int i = 0; i < size; i++)
        res[i] = data;
    res[size] = NULL;
    return res;
}
