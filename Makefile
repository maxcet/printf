SRCS = 	ft_printf.c ft_printf_utils.c ft_printf_src.c ft_printf_lib.c

OBJS = $(patsubst %.c,%.o,$(SRCS))

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: 		$(NAME)

$(NAME):	$(OBJS)
					ar rcs $(NAME) $?

%.o : %.c
		gcc $(FLAGS) -c $< -o $@

clean:
					$(RM) $(OBJS) $(OBJS_B)

fclean: 	clean
					$(RM) $(NAME)

re:					fclean all

.PHONY: 	all clean fclean re bonus