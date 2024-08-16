NAME := so_long

CC = gcc
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast
RM := rm -rf

LIBMLX_URL := https://github.com/codam-coding-college/MLX42.git
LIBMLX_DIR := ./lib/MLX42
LIBMLX := $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

HEADERS := -I include -I $(LIBMLX_DIR)/include

SRCS_DIR = ./srcs
SRCS_O = colors.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_O))
OBJS = $(SRCS:.c=.o)



all: clone libmlx $(NAME)

# "! -d" means if the directory doesn't exist.
clone:
	@if [ ! -d "$(LIBMLX_DIR)" ]; then \
		git clone $(LIBMLX_URL) $(LIBMLX_DIR); \
	fi

libmlx:
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4


$(NAME): $(OBJS)
	@$(CC) $^ $(LIBMLX) $(HEADERS) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) $< -c -o $@ && printf "Compiling: $(notdir $<)"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(LIBMLX_DIR)/build

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all libmlx clean fclean re clone
