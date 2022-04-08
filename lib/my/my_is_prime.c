/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** test if a number is prime
*/

int my_is_prime(int nb)
{
    int pos_div = 0;

    if (nb <= 1) {
        return 0;
    }
    for (int i = 1; i <= nb; i++) {
        if ((nb % i) == 0) {
            pos_div++;
        }
    }
    if (pos_div == 2) {
        return 1;
    } else {
        return 0;
    }
}
