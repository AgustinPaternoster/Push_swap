CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFILES = main.c
HEADER = push_swap.h
NAME = app
LIBDIR = ./printf/
LIBRARY = libftprintf.a

all : $(NAME)



$(NAME) : $(CFILES) $(HEADER) $(LIBRARY)
	@make -C printf
	$(CC) -o $@ $< $(LIBDIR)$(LIBRARY)