/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** print an str
*/

#include <unistd.h>
#include <stddef.h>

void my_putchar_err(char c);

int my_strlen(char const *str);

int my_putstr_err(char const *str)
{
    int lenstr = my_strlen(str);

    if (str == NULL)
        return 84;
    write(2, str, lenstr);
    return 0;
}

int my_put_nstr_err(char const *str, int nb)
{
    int lenstr = my_strlen(str);

    if (lenstr > nb) {
        for (int i = 0; i < nb; i++)
            write(2, &str[i], 1);
    } else {
        for (int i = 0; i < nb - lenstr; i++) {
            my_putchar_err(' ');
        }
        my_putstr_err(str);
    }
    return 0;
}
