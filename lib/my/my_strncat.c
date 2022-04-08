/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** put a str at the end of another str in n range
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_length = my_strlen(dest);
    int src_length = my_strlen(src);

    for (int i = 0; i < src_length && i < nb; i++) {
        dest[i + dest_length] = src[i];
    }
    return dest;
}
