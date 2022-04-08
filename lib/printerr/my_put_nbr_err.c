/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** print number
*/

void my_putchar_err(char c);
int my_nbrlen(int const nb);
int my_isneg(int nb);

int my_put_dig_err(int dig)
{
    dig = dig + 48;
    my_putchar_err(dig);
    return 0;
}

static void decomp_nbr_err(long nb)
{
    long tmp_nbr;

    if (nb >= 10) {
        tmp_nbr = nb / 10;
        decomp_nbr_err(tmp_nbr);
        my_put_dig_err(nb % 10);
    } else {
        my_put_dig_err(nb);
    }
}

int my_put_nbr_err(int nb)
{
    long longnb = nb;

    if (my_isneg(nb)) {
        my_putchar_err('-');
        longnb = longnb * -1;
    }
    decomp_nbr_err(longnb);
    return 0;
}

int my_put_un_nbr_err(unsigned int nb)
{
    long longnb = nb;

    decomp_nbr_err(longnb);
    return 0;
}

int my_put_n_nbr_err(int nb, int nbr)
{
    long longnb = nb;
    int lennbr = my_nbrlen(nb);

    if (my_isneg(nb)) {
        my_putchar_err('-');
        longnb = longnb * -1;
    }
    for (int i = 0; i < nbr - lennbr; i++)
        my_putchar_err('0');
    decomp_nbr_err(longnb);
    return 0;
}
