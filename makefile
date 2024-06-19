# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaterno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 11:14:53 by apaterno          #+#    #+#              #
#    Updated: 2024/06/19 11:14:59 by apaterno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFILES = check_err.c\
		ft_push_m.c\
		ft_rotate_m.c\
		ft_rrotate_m.c\
		ft_swap_m.c\
		ft_utils.c\
		main.c\
		node_mov_fn.c\
		quick_sort.c\
		sort_fn.c\
		sort_stack.c\
		stack_c_fn.c\
		stack_fn.c\
		stack_utils.c\
		stack_utils_2.c\
		ft_split.c
SRC_DIR = src/
SRC_FILES = $(addprefix $(SRC_DIR),$(CFILES))

HEADER = include/push_swap.h
NAME = push_swap
PRINTF = printf/libftprintf.a

all : $(NAME)

$(NAME) : $(SRC_FILES) $(HEADER) makefile
	@make -C printf
	$(CC) $(SRC_FILES) $(HEADER) $(PRINTF) $(CFLAGS) -o $(NAME)

clean :
	make clean -C printf

fclean :
	make fclean -C printf
	rm $(NAME)

re : fclean all



test10:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-10 -n 10))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-1000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-1000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l
