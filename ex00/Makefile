NAME			= rush-02
SRCS			= *.c
OBJS			= $(SRCS:.c=.o)
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

safe:			
				chmod 444 ref.dict

norme:			
				norminette -R CheckDefine
