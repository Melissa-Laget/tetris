/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-maxime.senard
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "printf.h"

void my_printf_show(va_list args, char *)
{
    my_showstr(va_arg(args, char*));
}

void my_printf_unint(va_list args, char *)
{
    my_put_un_nbr(va_arg(args, unsigned int));
}

void my_printf_oct(va_list args, char *)
{
    int nbr = va_arg(args, int);
    my_putbase(nbr, "01234567");
}

void my_printf_hex(va_list args, char *)
{
    int nbr = va_arg(args, int);
    my_putbase(nbr, "0123456789abcdef");
}

void my_printf_chex(va_list args, char *)
{
    int nbr = va_arg(args, int);
    my_putbase(nbr, "0123456789ABCDEF");
}
