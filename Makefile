# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 16:31:47 by alejaro2          #+#    #+#              #
#    Updated: 2025/02/28 18:25:35 by alejaro2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc 

CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR =libft 
LIBFT = $(LIBFT_DIR)/libft.a 

RM = rm -f

SRC = main.c \
parse_convert.c \
parse.c validate.c \
stack_utils.c \
utils.c sort_utils.c \
ops_1.c ops.c ksort.c \


OBJS = $(SRC:.c=.o)

all : $(LIBFT) $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)


$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re


