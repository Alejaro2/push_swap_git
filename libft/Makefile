NAME= libft.a
AR= ar -rcs
CC= cc
CFLAGS= -Wall -Werror -Wextra
SRC=   ft_bzero.c \
ft_strchr.c \
ft_memcmp.c \
ft_memmove.c \
ft_isdigit.c \
ft_isalpha.c \
ft_putnbr_fd.c \
ft_itoa.c \
ft_atoi.c \
ft_isascii.c \
ft_isalnum.c \
ft_striteri.c \
ft_strncmp.c \
ft_memchr.c \
ft_strlen.c \
ft_strlcpy.c \
ft_isprint.c \
ft_strrchr.c \
ft_strnstr.c \
ft_substr.c \
ft_strjoin.c \
ft_strdup.c \
ft_calloc.c \
ft_strmapi.c \
ft_putchar_fd.c \
ft_putstr.c \
ft_memcpy.c \
ft_strtrim.c \
ft_putendl_fd.c \
ft_strlcat.c \
ft_memset.c \
ft_toupper.c \
ft_tolower.c \
ft_split.c \

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft.h
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $< -c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
