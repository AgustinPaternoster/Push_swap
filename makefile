CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFILES = main.c\
		ft_utils.c\
		stack_fn.c
SRC_DIR = src/
SRC_FILES = $(addprefix $(SRC_DIR),$(CFILES))
HEADER = include/push_swap.h
NAME = app
PRINTF = printf/libftprintf.a

all : $(NAME)

$(NAME) : $(SRC_FILES) $(HEADER) makefile
	@make -C printf
	$(CC) -o $@ $(SRC_FILES) $(HEADER) $(PRINTF)

clean :
	make clean -C printf

fclean :
	make fclean -C printf
	rm $(NAME)

re : fclean all