##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -I.

SRC =		my_getnbr.c\
			my_long_to_int.c\
			is_in_str.c\
			my_isneg.c\
			my_putchar.c\
			my_put_nbr.c\
			my_putstr.c\
			my_showstr.c\
			my_strlen.c\
			my_put_float.c\
			my_putbase.c\
			my_printf.c\
			my_printf_func_1.c\
			my_printf_func_2.c

OBJ = $(SRC:.c=.o)

HEADER = printf.h

LIBNAME = libprintf.a

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
