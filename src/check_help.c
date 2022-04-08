/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget [WSL: Manjaro]
** File description:
** check_help
*/

#include "local.h"

void check_help(char **argv)
{
    char *help = file_to_str("help.txt");

    if (help == NULL)
        return;
    if (argv != NULL && argv[0] != NULL)
        my_printf("Usage: %s [options]\n", argv[0]);
    else
        my_printf("Usage: ./tetris [options]\n");
    write(1, help, my_strlen(help));
    free(help);
    exit(0);
}
