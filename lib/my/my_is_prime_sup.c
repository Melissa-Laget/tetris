/*
** EPITECH PROJECT, 2021
** my_is_prime_sup
** File description:
** get the greater prime number
*/

int my_is_prime(int nb);

int my_is_prime_sup(int nb)
{
    int cand_nb = nb;

    if (my_is_prime(nb)) {
        return nb;
    } else {
        while (!my_is_prime(cand_nb)) {
            cand_nb++;
        }
        return cand_nb;
    }
}
