CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFILES = ./src/main.c\
		./src/ft_utils.c\
		./src/push_swap.c\
		.src/stack_fn.c\
HEADER = push_swap.h
NAME = app
PRINTF = libftprintf.a

all : $(NAME)



$(NAME) : $(CFILES) $(HEADER) $(LIBRARY)
	@make -C printf
	
	$(CC) -o $@ $< $(LIBDIR)$(LIBRARY)