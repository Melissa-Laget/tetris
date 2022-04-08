/*
** EPITECH PROJECT, 2021
** libmy.a
** File description:
** resize_str
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *resize_str(char *str, int size)
{
    char *res = malloc(sizeof(char) * (size + 1));
    int lenstr = my_strlen(str);
    int i;

    for (i = 0; i < size && i < lenstr; i++)
        res[i] = str[i];
    res[i] = '\0';
    free(str);
    return res;
}
