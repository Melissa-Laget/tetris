/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprinterr-maxime.senard
** File description:
** my_putbase
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_putbase_err(int nbr, char const *base)
{
    int base_len = my_strlen(base);

    if (nbr / my_strlen(base) > 0)
        my_putbase_err(nbr / base_len, base);
    write(2, &base[nbr % base_len], 1);
}
