/*
** EPITECH PROJECT, 2021
** my_isupper
** File description:
** check if char is only upper letters
*/

int my_strlen(char const *str);

int is_in_str(char *str, char c);

int my_str_isupper(char *str)
{
    int length = my_strlen(str);
    int only_letter = 1;
    int is_letter = 0;
    char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < length; i++) {
        is_letter = is_in_str(ALPHABET, str[i]);
        if (is_letter == 0)
            only_letter = 0;
    }
    return only_letter;
}
