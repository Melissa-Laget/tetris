/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** turn a str in a word array
*/

#include <stdlib.h>

int is_in_str(char *str, char c);

static int my_nb_word_in_str(char const *str, char *d)
{
    int i = 0;
    int nb_word = 0;
    int is_word = 0;

    while (str[i] != '\0') {
        while (is_in_str(d, str[i])) {
            i++;
            is_word = 1;
        }
        if (is_word) {
            nb_word++;
        }
        is_word = 0;
        i++;
    }
    return nb_word;
}

static void put_str_in_arr(char *arr, char const *str, int bufstart, int bufend)
{
    int i;
    for (i = 0; i < (bufend - bufstart); i++) {
        arr[i] = str[i + bufstart];
    }
    arr[i] = '\0';
}

static char **compute_to_arr(char *d, char **res, int *w_props, char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        while (is_in_str(d, str[i])) {
            i++;
            w_props[1]++;
            w_props[2] = 1;
        }
        if (w_props[2]) {
            res[w_props[0]] = malloc(sizeof(char) * (w_props[1] + 1));
            put_str_in_arr(res[w_props[0]], str, (i - w_props[1]), i);
            w_props[0]++;
        }
        w_props[2] = 0;
        w_props[1] = 0;
        i++;
    }
    res[w_props[0]] = 0;
    return res;
}

char **my_str_to_word_array(char const *str)
{
    int word_index = 0;
    char *d = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int word_length = 0;
    char **res;
    int is_word = 0;
    int w_props[3];

    w_props[0] = word_index;
    w_props[1] = word_length;
    w_props[2] = is_word;
    res = malloc(sizeof(char*) * (my_nb_word_in_str(str, d) + 1));
    res = compute_to_arr(d, res, w_props, str);
    return res;
}
