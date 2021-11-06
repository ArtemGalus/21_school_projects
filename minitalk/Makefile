CC	= gcc

SRCS1	=	src/server.c

SRCS2	=	src/client.c

SOBJS	= ${SRCS1:.c=.o}

COBJS	= ${SRCS2:.c=.o}

SERVERNAME	= server

CLIENTNAME = client

LIBPATH = libft/

LIBNAME = ${LIBPATH}libft.a

HEADER	= includes/minitalk.h

LHEADER = /libft/include/libft.h

RM	= rm -f

CFLAGS	=  -Wall -Wextra -Werror -Imlx -I includes -I libft/include



%.o:		%.c ${HEADER}
			${CC} ${CFLAGS}  -c -o $@ $<

all:		${SERVERNAME} ${CLIENTNAME}

${SERVERNAME}:	${LIBNAME} ${SOBJS} 
			${CC} ${SOBJS} -lft -L libft/ -o ${SERVERNAME}

${CLIENTNAME}:	${LIBNAME} ${COBJS} 
			${CC} ${COBJS} -lft -L libft/ -o ${CLIENTNAME}

${LIBNAME}: 
			make -C ${LIBPATH}


			
clean:
			${RM} ${SOBJS} ${COBJS}
			make -C ${LIBPATH} clean

fclean:		clean
			${RM} ${SERVERNAME} ${CLIENTNAME}
			make -C ${LIBPATH} fclean

re:			fclean all

.PHONY:		all clean fclean re
