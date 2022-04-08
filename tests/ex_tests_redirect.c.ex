#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

void redirect_all_stdout(void)
{
  cr_redirect_stdout();
  cr_redirect_stderr();
}

Test(cat, test_file_as_parameters, .init=redirect_all_stdout)
{
  int ac = 2;
  char *av[] = {"a.out", "test"};

  my_cat(ac, av);
  cr_assert_stdout_eq_str("123456789", "");
}
