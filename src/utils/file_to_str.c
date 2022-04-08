/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget [WSL: Manjaro]
** File description:
** file_to_str
*/

#include "local.h"

char *file_to_str(char *filepath)
{
    struct stat st;
    char *buff = NULL;
    int filedesc = open(filepath, O_RDONLY);

    if (filedesc < 0)
        return NULL;
    if (fstat(filedesc, &st) < 0)
        return NULL;
    buff = malloc(sizeof(char) * st.st_size + 1);
    if (read(filedesc, buff, st.st_size) < 1)
        return NULL;
    buff[st.st_size] = '\0';
    return buff;
}
