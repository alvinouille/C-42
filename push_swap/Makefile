
NAME	= push_swap

SRC		=	parsing.c algo_1.c algo_2.c pre_sort.c fonctions_s_p.c fonctions_r.c fonctions_rr.c main.c utils.c small_a.c utils_a.c utils2.c moves.c utils2_a.c

OBJS    = ${SRC:.c=.o}

OPTION = -I ./

CC	= cc
RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror


.c.o:
			${CC} -c ${CFLAGS} ${OPTION} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BONUSOBJS} ${DEPS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
