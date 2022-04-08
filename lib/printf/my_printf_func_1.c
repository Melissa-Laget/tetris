/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-maxime.senard
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "printf.h"

void my_printf_str(va_list args, char *formater)
{

    char *str = va_arg(args, char*);
    int nbr = my_getnbr(formater);

    if (nbr != 0) {
        my_put_nstr(str, nbr);
    } else
        my_putstr(str);
}

void my_printf_int(va_list args, char *formater)
{
    int nb = va_arg(args, int);
    int nbr = my_getnbr(formater);

    if (nbr != 0) {
        my_put_n_nbr(nb, nbr);
    } else
        my_put_nbr(nb);
}

void my_printf_char(va_list args, char *)
{
    my_putchar(va_arg(args, int));
}

void my_printf_float(va_list args, char *formater)
{
    int nb_dig = 0;

    if (is_in_str(formater, '.')) {
        nb_dig = my_getnbr(formater);
        if (nb_dig != 0) {
            my_put_n_double(va_arg(args, double), nb_dig);
            return;
        }
    }
    my_put_double(va_arg(args, double));
}

void my_printf_bin(va_list args, char *)
{
    int nbr = va_arg(args, int);
    my_putbase(nbr, "01");
}
