/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** put a str at the end of another str
*/

#include <stdlib.h>
#include <stddef.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strcat(char *dest, char *src)
{
    int dest_length = my_strlen(dest);
    int src_length = my_strlen(src);
    char *res = malloc(sizeof(char) * (dest_length + src_length + 1));

    if (res == NULL || dest == NULL || src == NULL)
        return NULL;
    res = my_strcpy(res, dest);
    for (int i = 0; i < src_length; i++) {
        res[i + dest_length] = src[i];
    }
    res[dest_length + src_length] = '\0';
    return res;
}
