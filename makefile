CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFILES = check_err.c\
	ft_push_m.c\
	ft_rotate_m.c\
	ft_rrotate_m.c\
	ft_swap_m.c\
	ft_utils.c\
	large_sort_stack.c\
	main.c\
	quick_sort.c\
	stack_c_fn.c\
	stack_fn.c\
	stack_utils.c\
	stack_utils_2.c\
	tiny_sort_stack.c
SRC_DIR = src/
SRC_FILES = $(addprefix $(SRC_DIR),$(CFILES))
HEADER = include/push_swap.h
NAME = app
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
