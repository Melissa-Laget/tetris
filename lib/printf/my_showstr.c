/*
** EPITECH PROJECT, 2021
** my put char
** File description:
** function that can print a printable char
*/

#include <unistd.h>

int my_put_nbr(int nb);

void my_showchar(char c)
{
    int nb = c;

    if ((c > 31) && (c < 126))
        write(1, &c, 1);
    else {
        if (c > 99)
            write(1, "\\", 1);
        else
            write(1, "\\0", 2);
        my_put_nbr(nb);
    }
}

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_showchar(str[i]);
        i++;
    }
    return 0;
}
