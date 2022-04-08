/*
** EPITECH PROJECT, 2021
** my put char
** File description:
** function that can print a char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
