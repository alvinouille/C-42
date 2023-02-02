NAME			= fdf

SRCS			=	srcs/main.c \
					srcs/brasenham.c \
					srcs/brasenham2.c \
					srcs/brasenham3.c \
					srcs/split_tab.c \
					srcs/mlx.c \
					srcs/projection.c \
					srcs/tracing.c \
					srcs/trash.c \
					srcs/utils.c \
					srcs/utils2.c \
					srcs/get_next_line.c \
					srcs/get_next_line_utils.c

OBJS    		= $(SRCS:.c=.o)
CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MLX_FLAGS 		= -lX11 -lXext -lm
MLX_DIR			= mlx
MLX_LIB			= mlx/libmlx_Linux.a

BBlue=\033[1;34m

BAN				=	███████╗██████╗ ███████╗ \n\
					██╔════╝██╔══██╗██╔════╝ \n\
					█████╗  ██║  ██║█████╗  		Ready ???\n\
					██╔══╝  ██║  ██║██╔══╝  \n\
					██║     ██████╔╝██║      \n\
					╚═╝     ╚═════╝ ╚═╝      \n

all:			${NAME}

${MLX_LIB}:
				@make -C ${MLX_DIR}

${NAME}:		${OBJS} ${MLX_LIB} Makefile
				@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${MLX_LIB} ${MLX_FLAGS}
				@echo ""
				@echo " ${BAN}"


clean:
			@${RM} ${OBJS}
			@make -C ${MLX_DIR} clean

fclean:		clean
			@${RM} ${NAME}
			@${RM} ${MLX_LIB}

re:			fclean all

.PHONY: all clean fclean re
