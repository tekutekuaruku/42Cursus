NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCS := ft_print_num.c ft_printf_utils.c ft_printf.c ft_print_pointer.c ft_print_negative.c \
	ft_print_char.c ft_printf_utils2.c
OBJS := $(SRCS:%.c=%.o)
HEADER = printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
