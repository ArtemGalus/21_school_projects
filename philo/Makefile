CC	= gcc

SRCS	=	main.c	\
			init.c	\
			life.c	\
			eat.c	

OBJS	= ${SRCS:.c=.o}

NAME	= philo

HEADER	= philo.h

RM	= rm -f

CFLAGS	=  -Wall -Wextra -Werror



%.o:		%.c ${HEADER}
			${CC} ${CFLAGS} -c -o $@ $<

${NAME}:	${OBJS} 
			${CC} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
