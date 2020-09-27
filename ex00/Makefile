NAME			= rush-02
SRCS			= main.c ft_readfile.c ft_split.c ft_aff.c ft_catnumber.c ft_atoi.c ft_splitnbr.c ft_strdup.c
OBJS			= main.o ft_readfile.o ft_split.o ft_aff.o ft_catnumber.o ft_atoi.o ft_splitnbr.o ft_strdup.o
CC				= cc
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
