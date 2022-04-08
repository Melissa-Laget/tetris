##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -I.

SRC =		my_getnbr.c\
			is_in_str.c\
			my_isneg.c\
			my_putchar_err.c\
			my_put_nbr_err.c\
			my_putstr_err.c\
			my_showstr_err.c\
			my_strlen.c\
			my_put_float_err.c\
			my_putbase_err.c\
			my_long_to_int.c\
			my_printerr.c\
			my_printerr_func_1.c\
			my_printerr_func_2.c

OBJ = $(SRC:.c=.o)

HEADER = printerr.h

LIBNAME = libprinterr.a

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
