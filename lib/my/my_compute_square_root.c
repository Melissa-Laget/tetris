/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** get sqare root of an int
*/

int my_long_to_int(long nb);

int my_compute_square_root(int nb)
{
    int result;
    long longres;

    if (nb < 0) {
        return 0;
    }
    for (int i = 1; i < nb; i++) {
        longres = i * i;
        result = my_long_to_int(longres);
        if (result == 0) {
            return 0;
        } else if (result == nb) {
            return i;
        }
    }
    return 0;
}
