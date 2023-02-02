NAME			= so_long

SRCS			=	srcs/main.c \
					srcs/move.c \
					srcs/move2.c \
					srcs/mlx.c \
					srcs/display.c \
					srcs/trash.c \
					srcs/parsing.c \
					srcs/split.c \
					srcs/utils.c \
					srcs/utils2.c \
					srcs/validity.c \
					srcs/get_next_line.c \
					srcs/get_next_line_utils.c 

OBJS    		= $(SRCS:.c=.o)
CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MLX_FLAGS 		= -lX11 -lXext -lm
MLX_DIR			= mlx
MLX_LIB			= mlx/libmlx_Linux.a


all:			${NAME}

${MLX_LIB}:
				@make -C ${MLX_DIR}

${NAME}:		${OBJS} ${MLX_LIB} Makefile
				@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${MLX_LIB} ${MLX_FLAGS}


clean:
			@${RM} ${OBJS}
			@make -C ${MLX_DIR} clean

fclean:		clean
			@${RM} ${NAME}
			@${RM} ${MLX_LIB}

re:			fclean all

.PHONY: all clean fclean re
