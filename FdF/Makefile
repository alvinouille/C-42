NAME			= fdf

SRCS			=	srcs/algo.c \
					srcs/brasenham.c \
					srcs/split_tab.c \
					srcs/utils.c

OBJS    		= ${SRCS:.c=.o}
CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MLX_FLAGS 		= -lX11 -lXext -lm
MLX_DIR			= mlx
MLX_LIB			= mlx/libmlx_Linux.a

all:			${NAME}

${MLX_LIB}:
				make -C ${MLX_DIR}

${NAME}:		${OBJS} ${MLX_LIB} Makefile
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${MLX_LIB} ${MLX_FLAGS}


clean:
			${RM} ${OBJS}
			make -C ${MLX_DIR} clean

fclean:		clean
			${RM} ${NAME}
			make -C ${MLX_DIR} fclean

re:			fclean ${NAME}
			make -C ${MLX_DIR} re

.PHONY: all clean fclean re
