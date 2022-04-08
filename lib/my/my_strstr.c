/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** find first occurence of a patern in a str
*/

#include <stdlib.h>

int my_strlen(char const *str);

static int find_rec(char *str, char const *to_find)
{
    if ((str[0] != to_find[0]) || (str[0] == '\0')) {
        return 0;
    } else if (to_find[0] == '\0') {
        return 1;
    } else {
        find_rec(&str[1], &to_find[1]);
        return 1;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int length = my_strlen(str);

    for (int i = 0; i <= length; i++) {
        if ((find_rec(&str[i], &to_find[0]))) {
            return &str[i];
        }
    }
    return NULL;
}
