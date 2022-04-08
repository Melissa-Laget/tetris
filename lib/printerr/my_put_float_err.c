/*
** EPITECH PROJECT, 2021
** my_put_float
** File description:
** print float nbr
*/

void my_putchar_err(char c);
int my_put_nbr_err(int nb);

void my_put_float_err(float nb)
{
    int int_nb = nb;

    nb -= int_nb;
    my_put_nbr_err(int_nb);
    my_putchar_err('.');
    while (nb > 0) {
        nb *= 10;
        int_nb = nb;
        nb -= int_nb;
        my_putchar_err(int_nb + 48);
    }
}

void my_put_n_float_err(float nb, int dig)
{
    int int_nb = nb;
    int i = 0;

    nb -= int_nb;
    my_put_nbr_err(int_nb);
    my_putchar_err('.');
    while (nb > 0 && i < dig) {
        nb *= 10;
        int_nb = nb;
        nb -= int_nb;
        my_putchar_err(int_nb + 48);
        i++;
    }
}

void my_put_double_err(double nb)
{
    int int_nb = nb;

    nb -= int_nb;
    my_put_nbr_err(int_nb);
    my_putchar_err('.');
    while (nb > 0) {
        nb *= 10;
        int_nb = nb;
        nb -= int_nb;
        my_putchar_err(int_nb + 48);
    }
}

void my_put_n_double_err(double nb, int dig)
{
    int int_nb = nb;
    int i = 0;

    nb -= int_nb;
    my_put_nbr_err(int_nb);
    my_putchar_err('.');
    while (nb > 0 && i < dig) {
        nb *= 10;
        int_nb = nb;
        nb -= int_nb;
        my_putchar_err(int_nb + 48);
        i++;
    }
}
