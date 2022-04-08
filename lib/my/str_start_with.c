/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-maxime.senard
** File description:
** str_start_with
*/

#include "my.h"

int str_start_with(char *base_str, char *str_to_find,
    int len_base_str, int len_str_to_find)
{
    int is_equal = 1;

    if (len_base_str < len_str_to_find)
        return 0;
    for (int i = 0; i < len_str_to_find; i++) {
        if (base_str[i] != str_to_find[i])
            is_equal = 0;
    }
    return is_equal;
}
