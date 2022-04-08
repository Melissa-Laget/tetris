/*
** EPITECH PROJECT, 2021
** my_isnum
** File description:
** check if char is only number
*/

int my_strlen(char const *str);

int is_in_str(char *str, char c);

int my_str_isnum(char *str)
{
    int length = my_strlen(str);
    int only_num = 1;
    int is_num = 0;
    char all_num[] = "1234567890-+";

    for (int i = 0; i < length; i++) {
        is_num = is_in_str(all_num, str[i]);
        if (is_num == 0)
            only_num = 0;
    }
    return only_num;
}
