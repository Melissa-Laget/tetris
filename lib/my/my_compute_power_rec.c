/*
** EPITECH PROJECT, 2021
** my_compute_power_it
** File description:
** power a number
*/

int my_long_to_int(long nb);

int my_compute_power_rec(int nb, int p)
{
    int result = nb;
    int longres = result;

    if (p < 0) {
        return 0;
    }
    while (p > 1) {
        longres = result * nb;
        result = my_long_to_int(longres);
        if (result == 0) {
            return 0;
        }
        p--;
    }
    return result;
}
