
NAME	= push_swap

SRC		=	algos.c fonctions.c inutils.c main.c utils.c

OBJS    = ${SRC:.c=.o}

OPTION = -I ./

CC	= cc
RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror


.c.o:
			${CC} -c -g3 ${CFLAGS} ${OPTION} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BONUSOBJS} ${DEPS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re bonus
