# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 20:45:49 by tom               #+#    #+#              #
#    Updated: 2022/01/02 16:02:00 by tzeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFILES =	src/main.c src/get_input.c src/get_input_help.c src/stack_utils.c \
			src/sorts/sort.c src/sorts/help_func.c src/sorts/sort_help.c \
			src/sorts/small/sort_three.c src/sorts/small/sort_four.c src/sorts/small/sort_five.c \
			src/sorts/medium_sort.c src/sorts/large_sort.c \
			src/stack_op/swap.c src/stack_op/rotate.c src/stack_op/r_rotate.c src/stack_op/push.c\

OBJECTS = $(CFILES:.c=.o)

LIBFT_PATH = libft/


CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: pre_makes $(NAME)

pre_makes:
	make -C $(LIBFT_PATH)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_PATH)libft.a -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re