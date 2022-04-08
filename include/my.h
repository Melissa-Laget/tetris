/*
** EPITECH PROJECT, 2021
** header_libmy
** File description:
** header for libmy
*/

#ifndef MY_H
    #define MY_H

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_is_prime(int nb);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_put_n_nbr(int nb, int nbr);
int my_put_un_nbr(unsigned int nb);
int my_put_dig(int dig);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nstr(char const *str, int nb);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
int is_in_str(char *str, char c);
int my_str_isalpha(char *str);
int my_str_islower(char *str);
int my_str_isnum(char *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_strlen(char const *str);
int my_nbrlen(int const nb);
char replace_char(char *dic_src, char *dic_dest, char c);
char *my_strlowcase(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
void my_swap (int *a, int *b);
int is_in_str(char *str, char c);
void my_put_float(float nb);
void my_put_n_float(float nb, int deg);
void my_put_double(double nb);
void my_put_n_double(double nb, int deg);
void my_sort_int_array(int *tab, int size);
int get_int_pos(int size, int nb, int *tabl);
void my_putbase(int nbr, char const *base);
int str_start_with(char *base_str, char *str_to_find,
int len_base_str, int len_str_to_find);
int for_str_in_str(char *base_str, char *str_to_find);
char *resize_str(char *str, int size);
char *my_strdup(char const *str);
char *my_strndup(char const *str, int length);
int for_char_in_str(char *str, char c);
char **str_to_array(char *str, char *separators);
int is_in_str(char *str, char c);
int count_with_separators(char *document, char *separators);
int count_char_before_separator(char *document, char *separators);
char **ducplicate_char_arr(char **arr);
char **create_char_tabl(int size);
int my_char_tabl_len(char **tabl);
char **add_str_to_tabl(char **tabl, char *str);
char *add_to_str(char *str, char c);
unsigned char *add_to_ustr(unsigned char *str, unsigned char c);
int str_with_str(char *str, char *dict);

#endif
