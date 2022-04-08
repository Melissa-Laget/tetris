/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget [WSL: Manjaro]
** File description:
** check_errors
*/

#include "local.h"

int check_errors(int argc)
{
    if (!argc)
        return -1;
    if (argc > 20)
        return -2;
    return 0;
}

bool check_nb(flags_t *flags)
{
    bool valid = true;
    int arr[6] = {0};

    arr[0] = flags->key_left;
    arr[1] = flags->key_right;
    arr[2] = flags->key_turn;
    arr[3] = flags->key_drop;
    arr[4] = flags->key_quit;
    arr[5] = flags->key_pause;
    for (int i = 0; i < 6 && valid; i++) {
        if (arr[i] < 0 || arr[i] > 402)
            return false;
        for (int j = 0; j < 6 && valid; j++)
            valid = (arr[i] == arr[j] && i != j) ? false : valid;
    }
    return valid;
}
