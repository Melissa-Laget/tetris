/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** put everything in upercase
*/

int my_strlen(char const *str);

static void my_compute_cap(char *str, int *pos, int *first_let, int *is_letter)
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz1234567890";
    char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int i = pos[0];
    int j = pos[1];

    if ((str[i] == alphabet[j]) || (str[i] == ALPHABET[j])) {
        if (*first_let) {
            str[i] = ALPHABET[j];
        } else {
            str[i] = alphabet[j];
        }
        *is_letter = 1;
        *first_let = 0;
    }
}

char *my_strcapitalize(char *str)
{
    int length = my_strlen(str);
    int pos[2];
    int is_letter = 0;
    int first_let = 1;

    for (int i = 0; i < length; i++) {
        is_letter = 0;
        for (int j = 0; j < 26; j++) {
            pos[0] = i;
            pos[1] = j;
            my_compute_cap(str, pos, &first_let, &is_letter);
        }
        if (is_letter == 0)
            first_let = 1;
    }
    return str;
}
