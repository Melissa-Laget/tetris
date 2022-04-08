/*
** EPITECH PROJECT, 2021
** my put char
** File description:
** function that can print a char
*/

#include <unistd.h>

void my_putchar_err(char c)
{
    write(2, &c, 1);
}
