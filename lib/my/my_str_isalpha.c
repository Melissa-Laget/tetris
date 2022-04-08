/*
** EPITECH PROJECT, 2021
** my_isalpha
** File description:
** check if char is only letters
*/

#include <stddef.h>

int my_strlen(char const *str);
int is_in_str(char *str, char c);

int my_str_isalpha(char *str)
{
    int length = my_strlen(str);
    int only_letter = 1;
    int is_letter = 0;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < length; i++) {
        is_letter = is_in_str(alphabet, str[i]);
        if (is_letter == 0)
            only_letter = 0;
    }
    return only_letter;
}
