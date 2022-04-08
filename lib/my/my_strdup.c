/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *str)
{
    int length = my_strlen(str);
    char *res = NULL;

    if (length == 0) {
        res = malloc(sizeof(char) * 1);
        res[0] = '\0';
        return res;
    }
    res = malloc(sizeof(char) * length + 1);
    res = my_strcpy(res, str);
    return res;
}

char *my_strndup(char const *str, int length)
{
    int fulllength = my_strlen(str);
    char *res = NULL;

    if (fulllength == 0 || length > fulllength) {
        res = malloc(sizeof(char) * 1);
        res[0] = '\0';
        return res;
    }
    res = malloc(sizeof(char) * length + 1);
    res = my_strncpy(res, str, length);
    return res;
}
