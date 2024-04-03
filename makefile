CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFILES = main.c\
		ft_utils.c\
		stack_fn.c\
		ft_push_m.c\
		stack_c_fn.c\
		counting_sort.c\
		ft_swap_m.c\
		ft_rotate_m.c
SRC_DIR = src/
SRC_FILES = $(addprefix $(SRC_DIR),$(CFILES))
HEADER = include/push_swap.h
NAME = a.out
PRINTF = printf/libftprintf.a

all : $(NAME)

$(NAME) : $(SRC_FILES) $(HEADER) makefile
	@make -C printf
	$(CC) $(SRC_FILES) $(HEADER) $(PRINTF)

debug : $(SRC_FILES) $(HEADER) makefile
	@make -C printf
	$(CC) -g $(SRC_FILES) $(HEADER) $(PRINTF)

clean :
	make clean -C printf

fclean :
	make fclean -C printf
	rm $(NAME)

re : fclean all
