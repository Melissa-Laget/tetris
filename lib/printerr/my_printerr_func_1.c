/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprinterr-maxime.senard
** File description:
** my_printerr
*/

#include <stdarg.h>
#include <stdlib.h>
#include "printerr.h"

void my_printerr_str(va_list args, char *formater)
{

    char *str = va_arg(args, char*);
    int nbr = my_getnbr(formater);

    if (nbr != 0) {
        my_put_nstr_err(str, nbr);
    } else
        my_putstr_err(str);
}

void my_printerr_int(va_list args, char *formater)
{
    int nb = va_arg(args, int);
    int nbr = my_getnbr(formater);

    if (nbr != 0) {
        my_put_n_nbr_err(nb, nbr);
    } else
        my_put_nbr_err(nb);
}

void my_printerr_char(va_list args, char *)
{
    my_putchar_err(va_arg(args, int));
}

void my_printerr_float(va_list args, char *formater)
{
    int nb_dig = 0;

    if (is_in_str(formater, '.')) {
        nb_dig = my_getnbr(formater);
        if (nb_dig != 0) {
            my_put_n_double_err(va_arg(args, double), nb_dig);
            return;
        }
    }
    my_put_double_err(va_arg(args, double));
}

void my_printerr_bin(va_list args, char *)
{
    int nbr = va_arg(args, int);
    my_putbase_err(nbr, "01");
}
