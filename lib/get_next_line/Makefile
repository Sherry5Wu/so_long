NAME = gnl
AR     = ar rc
RM     = rm -f
CC     = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line_utils.c get_next_line.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $^
	@echo "get_next_line compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -fPIC -I. -c $< -o $@
	@echo "Compiling: $<"

clean:
	@${RM} ${OBJS}
	@echo "Gnl object files are cleaned"

fclean: clean
	@${RM} ${NAME}
	@echo "Gnl library file is cleaned"

re:	fclean all

.PHONY:		all fclean re
