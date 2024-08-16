SCRS = ft_output.c ft_printf.c
OBJS = ${SCRS:.c=.o}

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f
NAME = libftprintf.a

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} $^

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re