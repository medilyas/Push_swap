
RSC = resources/

OP = operations/

S_FCT = sorting_fcts/

S_UTL = sorting_utils/

CH_B = checker_bonus/

SRCS = push_swap.c ${RSC}ft_atoi.c ${RSC}ft_calloc.c \
	 ${OP}push_swap_operations.c ${OP}rotation_operations.c \
	 ${S_FCT}sorting_hundred.c ${S_FCT}sorting_three_five.c \
	 ${S_UTL}five_PushMin.c ${S_UTL}get_lis.c ${S_UTL}hundred_PushBest.c \
	 ${S_UTL}moves.c ${S_UTL}push.c

BONUS_SRCS = ${CH_B}checker.c ${CH_B}check_errors.c ${CH_B}get_next_line.c \
	${CH_B}operations_execute.c ${CH_B}${RSC}ft_strcmp_bonus.c \
	${CH_B}${RSC}ft_atoi_bonus.c ${CH_B}${RSC}ft_calloc_bonus.c \
	${OP}push_swap_operations.c ${OP}rotation_operations.c

NAME = push_swap

CHECKER = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

.c.o :
	${CC} ${CFLAGS} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

checker : ${BONUS_OBJS}
	${CC} ${CFLAGS} ${BONUS_OBJS} -o ${CHECKER}

clean :
	rm -f ${OBJS} ${BONUS_OBJS}

fclean : clean
	rm -f ${NAME} ${CHECKER}

re : fclean all

.PHONY : re all clean fclean

