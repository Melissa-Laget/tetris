/*
** EPITECH PROJECT, 2021
** header_libmy
** File description:
** header for libmy
*/

#ifndef PRINTERR_H
    #define PRINTERR_H

int my_getnbr(char const *str);
int my_isneg(int nb);
int my_put_nbr_err(int nb);
int my_put_n_nbr_err(int nb, int nbr);
int my_put_un_nbr_err(unsigned int nb);
int my_put_dig_err(int dig);
void my_putchar_err(char c);
int my_putstr_err(char const *str);
int my_put_nstr_err(char const *str, int nb);
int my_showstr_err(char const *str);
int is_in_str(char *str, char c);
int my_strlen(char const *str);
int my_nbrlen(int const nb);
void my_put_float_err(float nb);
void my_put_n_float_err(float nb, int deg);
void my_put_double_err(double nb);
void my_put_n_double_err(double nb, int deg);
void my_sort_int_array(int *tab, int size);
void my_putbase_err(int nbr, char const *base);
int my_printerr(const char *format, ...);
char *resize_str(char *str, int size);

#endif
