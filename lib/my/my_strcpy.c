/*
** EPITECH PROJECT, 2021
** my_stnrcpy
** File description:
** copy n char of a str into another
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int length = my_strlen(src);

    if (dest == NULL || src == NULL || length == 0)
        return NULL;
    for (int i = 0; i <= length - 1; i++) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
    return dest;
}
