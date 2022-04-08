/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** sort in array
*/

#include <stdlib.h>

int get_int_pos(int size, int nb, int *tabl)
{
    int pos = 0;

    for (int i = 0; i <= size; i++) {
        if (nb > tabl[i])
            pos++;
    }
    return pos;
}

void my_sort_int_array(int *tab, int size)
{
    int sorted = 0;
    int **res;
    int j = 0;

    res = malloc(sizeof(int*) * size + 1);
    for (int i = 0; i <= size; i++) {
        res[i] = malloc(sizeof(int) * 2 + 1);
        res[i][0] = tab[i];
        res[i][1] = get_int_pos(size, tab[i], tab);
    }
    while (sorted <= size) {
        if (res[j][1] == sorted) {
            tab[sorted] = res[j][0];
            j = 0;
            sorted++;
        } else
            j++;
    }
}
