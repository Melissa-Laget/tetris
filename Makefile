##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra -Llib
override CPPFLAGS += -Iinclude -llist -lmy -lprinterr -lprintf -lncurses

SRC	=	src/utils/put_char_arr_on_char_arr.c	\
		src/utils/del_map_line.c		\
		src/utils/file_to_str.c			\
		src/utils/void_utils.c			\
		src/utils/my_calloc.c			\
		src/utils/duplicate.c			\
		src/init/tetriminos.c			\
		src/init/debug_sort.c			\
		src/put_map_on_map.c			\
		src/check_errors.c			\
		src/check_flags.c			\
		src/check_help.c			\
		src/draw/debug.c			\
		src/init/flags.c			\
		src/init/spawn.c			\
		src/free/game.c				\
		src/draw/game.c				\
		src/init/load.c				\
		src/init/init.c				\
		src/draw/hud.c				\
		src/draw/map.c				\
		src/get_pos.c				\
		src/tetris.c				\
		src/rotate.c				\
		src/event.c				\
		src/move.c

OBJ = $(SRC:.c=.o)

TESTSRC = tests/test_make.c

MAINSRC = main.c

MAINOBJ = $(MAINSRC:.c=.o)

NAME = tetris

all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ)
				make  -C lib/list
				make  -C lib/my
				make  -C lib/printerr
				make  -C lib/printf
				gcc -o $(NAME) $(MAINOBJ) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
				rm -f $(OBJ) $(MAINOBJ)
				find . -type f -name '*.gcda' -delete
				find . -type f -name '*.gcno' -delete
				make clean -C lib/list
				make clean -C lib/my
				make clean -C lib/printerr
				make clean -C lib/printf


fclean: clean
				rm -f $(NAME)
				make fclean -C lib/list
				make fclean -C lib/my
				make fclean -C lib/printerr
				make fclean -C lib/printf

re: fclean all

tests_run:	CFLAGS += -lcriterion --coverage
tests_run: re $(TESTSRC)
				gcc -o unit_tests $(TESTSRC) $(SRC) $(CFLAGS) $(CPPFLAGS)
				./unit_tests

cover:
				gcovr --exclude tests
				gcovr --exclude tests --branches
				rm -f unit_tests*

debug: CFLAGS += -g
debug: re

.PHONY: all re clean fclean tests_run cover
