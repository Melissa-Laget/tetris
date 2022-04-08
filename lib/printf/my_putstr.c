/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** print an str
*/

#include <unistd.h>
#include <stddef.h>

void my_putchar(char c);

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int lenstr = my_strlen(str);

    if (str == NULL)
        return 84;
    write(1, str, lenstr);
    return 0;
}

int my_put_nstr(char const *str, int nb)
{
    int lenstr = my_strlen(str);

    if (lenstr > nb) {
        for (int i = 0; i < nb; i++)
            write(1, &str[i], 1);
    } else {
        for (int i = 0; i < nb - lenstr; i++) {
            my_putchar(' ');
        }
        my_putstr(str);
    }
    return 0;
}
