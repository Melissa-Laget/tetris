/*
** EPITECH PROJECT, 2021
** my put char
** File description:
** function that can print a printable char
*/

#include <unistd.h>

int my_put_nbr_err(int nb);

void my_showchar_err(char c)
{
    int nb = c;

    if ((c > 31) && (c < 126))
        write(2, &c, 1);
    else {
        if (c > 99)
            write(2, "\\", 1);
        else
            write(2, "\\0", 2);
        my_put_nbr_err(nb);
    }
}

int my_showstr_err(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_showchar_err(str[i]);
        i++;
    }
    return 0;
}
