GREEN = \033[0;92m
DEFAULT = \033[0;39m

NAME = libft.a

AR     = ar -rc
RM     = rm -f
CC     = cc
CFLAGS = -Wall -Wextra -Werror

SRCS   = ft_isalpha.c ft_isdigit.c ft_isalnum.c  ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c\
         ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
		 ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
		 ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
		 ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS   = $(SRCS:.c=.o)

SRCS_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c 	ft_lstsize_bonus.c ft_lstlast_bonus.c\
		 ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
		 ft_lstmap_bonus.c
OBJS_B = $(SRCS_B:.c=.o)

GNL_DIR = ../get_next_line
GNL_SRCS = get_next_line.c get_next_line_utils.c
GNL_OJBS = $(addprefix $(GNL_DIR)/, $(GNL_SRCS:.c=.o))

PTF_DIR = ../ft_printf
PTF_SRCS = ft_output.c ft_printf.c
PTF_OBJS = $(addprefix $(PTF_DIR)/, $(PTF_SRCS:.c=.o))


all: $(NAME)
bonus: .bonus

$(NAME): $(OBJS) $(GNL_OJBS) $(PTF_OBJS)
	@$(AR) $@ $^
	@echo "libft.a compiled!"

%.o: %.c
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@
	@echo "Compiling: $<"

.bonus: $(NAME) $(OBJS_B)
	$(AR) $(NAME) $^
	@touch .bonus

clean:
	@$(RM) $(OBJS) $(OBJS_B) $(GNL_OJBS) $(PTF_OBJS)
	@echo "$(GREEN)Libft object files are cleaned!$(DEFAULT)"

fclean:	clean
	@$(RM) $(NAME) .bonus
	@echo "$(GREEN)Libft library file is cleaned!$(DEFAULT)"

re:	fclean all

.PHONY:		bonus all clean fclean re
