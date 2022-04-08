/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** return lenth of an str
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_nbrlen(int const nb)
{
    int i = 0;
    int nbr = nb;

    while (nbr > 0) {
        nbr /= 10;
        i++;
    }
    return i;
}
