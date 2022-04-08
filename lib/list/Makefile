##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra -I.

SRC = add.c \
	  append.c \
	  create.c \
	  del.c \
	  duplicate.c \
	  free.c \
	  init.c \
	  pop.c \
	  transform.c \
	  utils.c

OBJ = $(SRC:.c=.o)

HEADER = list.h

LIBNAME = liblist.a

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
