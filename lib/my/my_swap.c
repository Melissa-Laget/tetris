/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** function to swap 2 int from pointer
*/

void my_swap (int *a, int *b)
{
    int nb1 = *a;
    int nb2 = *b;

    *a = nb2;
    *b = nb1;
}
