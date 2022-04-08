/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprinterr-maxime.senard
** File description:
** my_printerr
*/

#include <stdarg.h>
#include <stdlib.h>
#include "printerr.h"

void my_printerr_show(va_list args, char *)
{
    my_showstr_err(va_arg(args, char*));
}

void my_printerr_unint(va_list args, char *)
{
    my_put_un_nbr_err(va_arg(args, unsigned int));
}

void my_printerr_oct(va_list args, char *)
{
    int nbr = va_arg(args, int);
    my_putbase_err(nbr, "01234567");
}

void my_printerr_hex(va_list args, char *)
{
    int nbr = va_arg(args, int);
    my_putbase_err(nbr, "0123456789abcdef");
}

void my_printerr_chex(va_list args, char *)
{
    int nbr = va_arg(args, int);
    my_putbase_err(nbr, "0123456789ABCDEF");
}
