/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-antman-killian1.lelong
** File description:
** doc_utils
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

int count_with_separators(char *document, char *separators)
{
    int count = 1;

    if (document == NULL || separators == NULL)
        return -84;
    for (int i = 0; document[i] != '\0'; i++)
        count += is_in_str(separators, document[i]);
    if (is_in_str(separators, '\0') == 1)
        count++;
    return count;
}

int count_char_before_separator(char *document, char *separators)
{
    int count = 0;

    if (document == NULL || separators == NULL)
        return -84;
    for (int i = 0; is_in_str(separators, document[i]) == 0; i++) {
        if (document[i] == '\0')
            return my_strlen(document);
        count++;
    }
    return count;
}

char **ducplicate_char_arr(char **arr)
{
    int len = 0;
    char **res = NULL;

    if (arr == NULL || arr[0] == NULL)
        return NULL;
    len = my_char_tabl_len(arr) - 1;
    if ((res = malloc(sizeof(char*) * (len + 1))) == NULL)
        return NULL;
    for (int  i = 0; i < len; i++) {
        if ((res[i] = my_strdup(arr[i])) == NULL)
            return NULL;
    }
    res[len] = NULL;
    return res;
}
