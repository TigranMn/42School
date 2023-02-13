LIBFT = libft/libft.a

LIBFT_PATH = ./libft

NAME = libftprintf.a

SRCS =  ft_print_hex.c ft_print_nbrs.c ft_printf.c ft_printf_utils.c
		
OBJS =  ${SRCS:.c=.o}

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror -I

INCLUDES = ./ft_printf.h

$(NAME): $(OBJS)
	$(MAKE) bonus -C ${LIBFT_PATH}
	cp ${LIBFT} $(NAME)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ${LIBFT_PATH}
	${RM} $(OBJS)

fclean : clean
	$(MAKE) fclean -C ${LIBFT_PATH}
	${RM} $(NAME)

re : fclean all

.PHONY all clean fclean re