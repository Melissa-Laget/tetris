/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** return 1 if str is printable
*/

int my_strlen(char const *str);

int my_str_isprintable(char const *str)
{
    int length = my_strlen(str);
    int printable_char = 1;

    for (int i = 0; i < length; i++) {
        if (!((str[i] > 31) && (str[i] < 126))) {
            printable_char = 0;
        }
    }
    return printable_char;
}
