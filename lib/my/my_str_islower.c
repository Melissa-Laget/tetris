/*
** EPITECH PROJECT, 2021
** my_islower
** File description:
** check if char is only lower letters
*/

int my_strlen(char const *str);

int is_in_str(char *str, char c);

int my_str_islower(char *str)
{
    int length = my_strlen(str);
    int only_letter = 1;
    int is_letter = 0;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < length; i++) {
        is_letter = is_in_str(alphabet, str[i]);
        if (is_letter == 0)
            only_letter = 0;
    }
    return only_letter;
}
