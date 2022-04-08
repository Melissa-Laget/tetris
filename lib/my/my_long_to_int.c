/*
** EPITECH PROJECT, 2021
** my_long_to_int
** File description:
** turn long into int
*/

int my_long_to_int(long nb)
{
    if ((nb >= -2147483648) && (nb <= 2147483647)) {
        return nb;
    } else {
        return 0;
    }
}
