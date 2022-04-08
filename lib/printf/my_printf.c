/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-maxime.senard
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "printf.h"

void my_printf_str(va_list arg, char *formater);
void my_printf_int(va_list arg, char *formater);
void my_printf_char(va_list arg, char *formater);
void my_printf_float(va_list args, char *formater);
void my_printf_bin(va_list args, char *formater);
void my_printf_show(va_list args, char *formater);
void my_printf_unint(va_list args, char *formater);
void my_printf_oct(va_list args, char *formater);
void my_printf_hex(va_list args, char *formater);
void my_printf_chex(va_list args, char *formater);

static const char *form_terminator = "sdicfeEgGbSuoxX";
static const int len_form_list = 15;
static const void (*printfunc[])(va_list, char *) = {
    &my_printf_str,
    &my_printf_int,
    &my_printf_int,
    &my_printf_char,
    &my_printf_float,
    &my_printf_float,
    &my_printf_float,
    &my_printf_float,
    &my_printf_float,
    &my_printf_bin,
    &my_printf_show,
    &my_printf_unint,
    &my_printf_oct,
    &my_printf_hex,
    &my_printf_chex
};

void put_formater(va_list args, char *formater)
{
    int flag_exist = 0;
    int len_formater = my_strlen(formater);
    char main_formater = formater[len_formater - 1];

    if (is_in_str(&formater[1], '%') || is_in_str(&formater[1], ' ')) {
        my_putstr(formater);
        return;
    }
    for (int i = 0; i < len_form_list; i++) {
        if (main_formater == form_terminator[i]) {
            printfunc[i](args, formater);
            flag_exist = 1;
            break;
        }
    }
    if (flag_exist == 0)
        my_putstr(formater);
}

int extract_formater(int i, int len_format, const char *format, va_list args)
{
    int j = 0;
    char *formater = malloc(sizeof(char) * 100);

    while (!is_in_str((char*)form_terminator, format[i + j]) &&
    i + j < len_format) {
        formater[j] = format[i + j];
        j++;
    }
    formater[j] = format[i + j];
    formater[j + 1] = '\0';
    i += j;
    put_formater(args, formater);
    free(formater);
    return i;
}

int my_printf(const char *format, ...)
{
    int len_format = my_strlen(format);
    va_list args;

    va_start(args, format);
    for (int i = 0; i < len_format; i++) {
        if (format[i] == '%' && format[i + 1] == '%') {
            i += 2;
            my_putchar('%');
        }
        if (format[i] == '%') {
            i = extract_formater(i, len_format, format, args);
        } else
            my_putchar(format[i]);
    }
    va_end(args);
    return 0;
}
