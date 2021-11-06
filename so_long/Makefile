CC	= gcc

SRCS	=	src/get_next_line.c			\
			src/get_next_line_utils.c	\
			src/so_long.c				\
			src/validate.c				\
			src/map_creation.c			\
			src/move_fns.c				\
			src/draw_fns.c				\
			src/game_start.c			\
			src/img_load.c				\
			src/validate2.c				

OBJS	= ${SRCS:.c=.o}

BUFFER = BUFFER_SIZE=100

NAME	= so_long

LIBPATH = libft/

LIBNAME = ${LIBPATH}libft.a

HEADER	= includes/so_long.h

LHEADER = /libft/include/libft.h

RM	= rm -f

CFLAGS	=  -Wall -Wextra -Werror -Imlx -I includes -I libft/include



%.o:		%.c ${HEADER}
			${CC} ${CFLAGS}  -D ${BUFFER} -c -o $@ $<

${NAME}:	${LIBNAME} ${OBJS} 
			${CC} ${OBJS}  -lmlx -framework OpenGL -framework AppKit -lft -L libft/ -o ${NAME}

all:		${NAME}

${LIBNAME}: 
			make -C ${LIBPATH}


			
clean:
			${RM} ${OBJS}
			make -C ${LIBPATH} clean

fclean:		clean
			${RM} ${NAME}
			make -C ${LIBPATH} fclean

re:			fclean all

.PHONY:		all clean fclean re
