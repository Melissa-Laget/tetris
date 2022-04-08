/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-antman-killian1.lelong
** File description:
** str_to_array
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char **str_to_array(char *str, char *separators)
{
    char **arr = NULL;
    char *tmpstr = str;
    int item_count = count_with_separators(str, separators);
    int count = 0;

    if (item_count == -84)
        return NULL;
    arr = malloc(sizeof(char*) * (item_count + 1));
    arr[item_count] = NULL;
    for (int i = 0; i < item_count; i++) {
        count = count_char_before_separator(tmpstr, separators);
        if (count == -84)
            return NULL;
        arr[i] = my_strndup(tmpstr, count);
        if (arr[i] == NULL)
            return NULL;
        (i != item_count) ? tmpstr = &tmpstr[count + 1] : NULL;
    }
    return arr;
}
