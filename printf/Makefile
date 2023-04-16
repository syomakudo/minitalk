SRCS		=	src/ft_printf.c \
				src/ft_put_func1.c

MAKE	=	Make

OBJS		=	$(SRCS:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a
LIBFT_NAME	=	./libft/libft.a

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT_NAME)
			cp $(LIBFT_NAME) $(NAME)
			ar rcs $(NAME) $(OBJS)

$(LIBFT_NAME):
			$(MAKE) -C ./libft

clean:
			$(RM) $(OBJS)
			$(MAKE) clean -C ./libft

fclean:		clean
			rm -f $(NAME) $(LIBFT_NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
