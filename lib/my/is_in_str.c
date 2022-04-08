/*
** EPITECH PROJECT, 2022
** complib
** File description:
** is_in_str
*/

#include <stddef.h>

int my_strlen(char const * str);

int is_in_str(char *str, char c)
{
    if (str == NULL)
        return 84;
    for (int i = 0; i < my_strlen(str); i++) {
        if (c == str[i]) {
            return 1;
        }
    }
    return 0;
}

int str_with_str(char *str, char *dict)
{
    if (str == NULL || dict == NULL)
        return 84;
    for (int i = 0; i < my_strlen(str); i++) {
        if (is_in_str(dict, str[i]) == 0)
            return 0;
    }
    return 1;
}
