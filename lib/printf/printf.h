/*
** EPITECH PROJECT, 2021
** header_libmy
** File description:
** header for libmy
*/

#ifndef PRINTF_H
    #define PRINTF_H

int my_getnbr(char const *str);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_put_n_nbr(int nb, int nbr);
int my_put_un_nbr(unsigned int nb);
int my_put_dig(int dig);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nstr(char const *str, int nb);
int my_showstr(char const *str);
int is_in_str(char *str, char c);
int my_strlen(char const *str);
int my_nbrlen(int const nb);
void my_put_float(float nb);
void my_put_n_float(float nb, int deg);
void my_put_double(double nb);
void my_put_n_double(double nb, int deg);
void my_sort_int_array(int *tab, int size);
void my_putbase(int nbr, char const *base);
int my_printf(const char *format, ...);
char *resize_str(char *str, int size);

#endif
