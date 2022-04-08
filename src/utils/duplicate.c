/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget [WSL: Manjaro]
** File description:
** duplicate
*/

#include "local.h"

char *clean_line(char *line)
{
    for (int i = my_strlen(line); i >= 0; i--) {
        if (line[i] == '*')
            return line;
        line[i] = '\0';
    }
    free(line);
    return NULL;
}

char **clean_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        arr[i] = clean_line(arr[i]);
    }
    return arr;
}

char **duplicate_char_arr(char **arr)
{
    char **res = NULL;
    int i = 0;

    res = malloc(sizeof(char *) * my_char_tabl_len(arr));
    if (res == NULL)
        return NULL;
    for (; arr[i] != NULL; i++) {
        res[i] = my_strdup(arr[i]);
        if (res[i] == NULL)
            return NULL;
    }
    if (res[i - 1][0] == '\0' ||
        (res[i - 1][0] == '\n' && res[i - 1][1] == '\0')) {
        free(res[i - 1]);
        res[i - 1] = NULL;
    }
    res[i] = NULL;
    return res;
}
