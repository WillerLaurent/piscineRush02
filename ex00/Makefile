NAME			= ft_cat
SRCS			= ft_cat.c
OBJS			= ft_cat.o
HEADER			= includes
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

.c.o:
				${CC} ${CFLAGS} -c ${SRCS}

${NAME}:		${OBJS}
				${CC} -o ${NAME} ${OBJS}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all
