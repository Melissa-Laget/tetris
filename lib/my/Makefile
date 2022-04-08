##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra -L. -lmy -I. -g

TESTSRC = ../../tests/test_make.c\
		  ../../tests/test_basic.c\
		  ../../tests/test_complexe.c

TESTOBJ = $(TESTSRC:.c=.o)

SRC = my_compute_power_rec.c \
			my_compute_square_root.c\
			my_getnbr.c\
			my_isneg.c\
			my_is_prime.c\
			my_is_prime_sup.c\
			my_long_to_int.c\
			my_putchar.c\
			my_put_nbr.c\
			my_putstr.c\
			my_revstr.c\
			my_showstr.c\
			my_show_word_array.c\
			my_sort_int_array.c\
			my_strcapitalize.c\
			my_strcat.c\
			my_strcmp.c\
			my_strcpy.c\
			my_str_isalpha.c\
			my_str_islower.c\
			my_str_isnum.c\
			my_str_isprintable.c\
			my_str_isupper.c\
			my_strlen.c\
			my_strlowcase.c\
			my_strncat.c\
			my_strncmp.c\
			my_strncpy.c\
			my_strstr.c\
			my_str_to_word_array.c\
			my_strupcase.c\
			my_swap.c\
			my_put_float.c\
			my_putbase.c\
			str_start_with.c\
			for_str_in_str.c\
			resize_str.c\
			my_strdup.c\
			str_utils.c\
			str_to_array.c\
			char_arr_utils.c\
			is_in_str.c


OBJ = $(SRC:.c=.o)

HEADER = my.h

LIBNAME = libmy.a

all: $(LIBNAME)

$(LIBNAME): $(OBJ)
				ar rc $(LIBNAME) $(OBJ)
				cp $(LIBNAME) ../
				cp $(HEADER) ../../include/

clean:
				rm -f $(OBJ)

fclean: clean
				rm -f $(LIBNAME)
				rm -f ../$(LIBNAME)

re: fclean all

tests_run:	CFLAGS += -lcriterion --coverage -g
tests_run: re $(TESTOBJ)
				gcc -o unit_tests $(TESTOBJ) $(CFLAGS) $(CPPFLAGS)
				./unit_tests
