NAME			= rush-02
SRCS			= main.c ft_readfile.c
OBJS			= main.o ft_readfile.o
HEADER			= .
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
