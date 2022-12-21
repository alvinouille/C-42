NAME	= libftprintf.a

CC	= cc
RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

SRC	= ft_putnbr_un.c ft_hex.c ft_d_i_c.c ft_p.c ft_percent.c ft_s.c ft_printf.c ft_core.c

OBJS    = ${SRC:.c=.o}

.c.o:
	${CC} -c ${CFLAGS} -I ./libft/ -I ./ $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ./libft/
			cp ./libft/libft.a ./
			mv libft.a ${NAME}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
		make clean -C ./libft/
		${RM} ${OBJS}

fclean:		clean
			make fclean -C ./libft/
			${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
