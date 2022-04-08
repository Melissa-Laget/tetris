/*
** EPITECH PROJECT, 2021
** my_strlowcase
** File description:
** put everything in lowcase
*/

int my_strlen(char const *str);

char replace_char(char *dic_src, char *dic_dest, char c)
{
    for (int i = 0; (dic_src[i] != '\0') || (dic_dest[i] != '\0'); i++) {
        if (c == dic_src[i]) {
            c = dic_dest[i];
        }
    }
    return c;
}

char *my_strlowcase(char *str)
{
    int length = my_strlen(str);
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < length; i++) {
        str[i] = replace_char(ALPHABET, alphabet, str[i]);
    }
    return str;
}
