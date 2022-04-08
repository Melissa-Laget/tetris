/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** find first number of an array
*/

int my_long_to_int(long nb);
int my_strlen(char const *str);

static int my_find_nbr(char nbr)
{
    char intlist[10] = "1234567890";

    for (int i = 0; i <= 10; i++) {
        if (nbr == intlist[i]) {
            return 1;
        }
    }
    return 0;
}

static long my_char_to_num(char *reschar)
{
    long longres = 0;
    for (int l = 0; reschar[l] != '\0'; l++) {
        longres = (longres * 10) + (reschar[l] - 48);
    }
    return longres;
}

static int my_get_minus(const char *str, int i)
{
    int j = 0;
    int nb_minus = 0;

    while (j < i) {
        if (str[j] == '-') {
            nb_minus++;
        } else if (!my_find_nbr(str[j])) {
            nb_minus = 0;
        }
        j++;
    }
    if (nb_minus % 2) {
        return 1;
    } else {
        return 0;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 0;
    char reschar[10];
    long longres = 0;
    int lenstr = my_strlen(str);

    while (!my_find_nbr(str[i]) && i < lenstr)
        i++;
    j = i;
    while (my_find_nbr(str[j]) && j < lenstr) {
        reschar[j - i] = str[j];
        j++;
    }
    reschar[j - i] = '\0';
    longres = my_char_to_num(reschar);
    if (my_get_minus(str, i) && (longres != 0)) {
        longres = longres * -1;
    }
    return my_long_to_int(longres);
}
