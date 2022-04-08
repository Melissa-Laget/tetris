/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget [WSL: Manjaro]
** File description:
** flags
*/

#include "local.h"

void init_flags_default(flags_t *flags)
{
    flags->level = 1;
    flags->key_left = 260;
    flags->key_right = 261;
    flags->key_turn = 259;
    flags->key_drop = 258;
    flags->key_quit = 113;
    flags->key_pause = 32;
    flags->key_next = 110;
    flags->without_next = false;
    flags->debug = false;
    flags->map_size = ((vect_t){.y = 20, .x = 10});
    flags->help = false;
}

bool init_flags(int argc, char **argv, flags_t *flags)
{
    init_flags_default(flags);
    if (check_flags(argc, argv, flags) == false)
        return false;
    flag_debug(flags);
    return true;
}
