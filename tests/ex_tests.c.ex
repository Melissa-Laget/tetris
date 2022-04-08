/*
** EPITECH PROJECT, 2021
** test_my_strstr
** File description:
** test criterion for my_strstr
*/

#include <stdlib.h>
#include <criterion/criterion.h>

Test(my_func, test_str)
{
    char source[] = "Hello";
    char *res = ma_func(source);

    cr_assert_str_eq(res, "Hello");
}

Test(ma_func, tested_str_null)
{
    char source[] = "Hello";
    char *res = ma_func(source);

    cr_assert_eq(res, NULL);
}

Test(ma_func, tested_int)
{
  int nb[] = 2;
  int res = ma_func(nb);

  cr_assert_eq(res, 4);
}
