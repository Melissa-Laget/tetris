/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprinterr-maxime.senard
** File description:
** my_printerr
*/

#include <stdarg.h>
#include <stdlib.h>
#include "printerr.h"

void my_printerr_str(va_list arg, char *formater);
void my_printerr_int(va_list arg, char *formater);
void my_printerr_char(va_list arg, char *formater);
void my_printerr_float(va_list args, char *formater);
void my_printerr_bin(va_list args, char *formater);
void my_printerr_show(va_list args, char *formater);
void my_printerr_unint(va_list args, char *formater);
void my_printerr_oct(va_list args, char *formater);
void my_printerr_hex(va_list args, char *formater);
void my_printerr_chex(va_list args, char *formater);

static const char *form_terminator = "sdicfeEgGbSuoxX";
static const int len_form_list = 15;
static const void (*printerrunc[])(va_list, char *) = {
    &my_printerr_str,
    &my_printerr_int,
    &my_printerr_int,
    &my_printerr_char,
    &my_printerr_float,
    &my_printerr_float,
    &my_printerr_float,
    &my_printerr_float,
    &my_printerr_float,
    &my_printerr_bin,
    &my_printerr_show,
    &my_printerr_unint,
    &my_printerr_oct,
    &my_printerr_hex,
    &my_printerr_chex
};

void put_formater_err(va_list args, char *formater)
{
    int flag_exist = 0;
    int len_formater = my_strlen(formater);
    char main_formater = formater[len_formater - 1];

    if (is_in_str(&formater[1], '%') || is_in_str(&formater[1], ' ')) {
        my_putstr_err(formater);
        return;
    }
    for (int i = 0; i < len_form_list; i++) {
        if (main_formater == form_terminator[i]) {
            printerrunc[i](args, formater);
            flag_exist = 1;
            break;
        }
    }
    if (flag_exist == 0)
        my_putstr_err(formater);
}

int extract_formater_err(int i, int len_format,
const char *format, va_list args)
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
    put_formater_err(args, formater);
    free(formater);
    return i;
}

int my_printerr(const char *format, ...)
{
    int len_format = my_strlen(format);
    va_list args;

    va_start(args, format);
    for (int i = 0; i < len_format; i++) {
        if (format[i] == '%' && format[i + 1] == '%') {
            i += 2;
            my_putchar_err('%');
        }
        if (format[i] == '%') {
            i = extract_formater_err(i, len_format, format, args);
        } else
            my_putchar_err(format[i]);
    }
    va_end(args);
    return 0;
}
