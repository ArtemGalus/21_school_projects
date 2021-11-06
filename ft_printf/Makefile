CC	= cc

SRCS	=	ft_atoi.c	\
		ft_bzero.c	\
		ft_c.c		\
		ft_pars.c	\
		ft_printf.c	\
		ft_printwp.c	\
		ft_putnbr.c	\
		ft_strlen.c	\
		ft_x.c		\

OBJS	= ${SRCS:.c=.o}


NAME	= libftprintf.a

HEADER	= ft_printf.h

RM	= rm -f

AR	= ar rsc

CFLAGS	=  -Wall -Wextra -Werror

%.o:		%.c ${HEADER}
		$(CC) ${CFLAGS} -c -o $@ $<

all:		${NAME}

${NAME}:	${OBJS}
		${AR} ${NAME} $?
			
clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
