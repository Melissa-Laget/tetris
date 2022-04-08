/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** main
*/

#include "local.h"

int main(int argc, char **argv)
{
    time_t date;
    if (check_errors(argc) != 0)
        return 84;
    srand((unsigned)time(&date));
    return tetris(argc, argv);
}
