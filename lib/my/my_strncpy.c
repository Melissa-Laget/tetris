/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copy a str into another
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int length = my_strlen(src);

    if (dest == NULL || src == NULL || length == 0 || n > length)
        return NULL;
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[n] = '\0';
    if (n < (my_strlen(src) - 1)) {
        dest[n] = '\0';
    }
    return dest;
}
