CC	= gcc

SRCS	=	src/operations.c	\
			src/operations2.c	\
			src/push_swap.c		\
			src/sort.c			\
			src/sortsupfunc1.c	\
			src/sortsupfunc2.c	\
			src/delete.c		\
			src/check.c			\

OBJS	= ${SRCS:.c=.o}


NAME	= push_swap

LIBPATH = libft/

LIBNAME = ${LIBPATH}libft.a

HEADER	= includes/push_swap.h

LHEADER = /libft/include/libft.h

RM	= rm -f

CFLAGS	=  -Wall -Wextra -Werror -I includes -I libft/include



%.o:		%.c ${HEADER}
			${CC} ${CFLAGS} -c -o $@ $<

${NAME}:	${LIBNAME} ${OBJS} 
			${CC} ${OBJS} -lft -L libft/ -o ${NAME}

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
