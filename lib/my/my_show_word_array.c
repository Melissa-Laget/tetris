/*
** EPITECH PROJECT, 2021
** my_show_word_array
** File description:
** print all str in an array
*/

int my_putstr(char const *str);

void my_putchar(char c);;

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
