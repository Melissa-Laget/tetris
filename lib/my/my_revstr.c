/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverse a str with pointer
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int length = my_strlen(str) - 1;
    char result;
    int i = 0;

    while (i < length) {
        result = str[i];
        str[i] = str[length];
        str[length] = result;
        i++;
        length--;
    }
    return str;
}
