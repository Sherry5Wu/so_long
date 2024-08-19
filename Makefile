NAME := so_long

CC = gcc
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast
RM := rm -rf

# MLX library
LIBMLX_URL := https://github.com/codam-coding-college/MLX42.git
LIBMLX_DIR := ./lib/MLX42
LIBMLX := $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Libft library
LIBFT_DIR := lib/libft
LIBFT := $(LIBFT_DIR)/libft.a

# gnl library
GNL_DIR := lib/get_next_line
GNL := $(GNL_DIR)/gnl.a

# ft_printf library
PRINTF_DIR := lib/ft_printf
PRINTF := $(PRINTF_DIR)/lft_printf.a

HEADERS := -I include -I $(LIBMLX_DIR)/include

SRCS_DIR = ./srcs
SRCS_O = colors.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_O))
OBJS = $(SRCS:.c=.o)



all: clone $(NAME)

# "! -d" means if the directory doesn't exist.
clone:
	@if [ ! -d "$(LIBMLX_DIR)" ]; then \
		git clone $(LIBMLX_URL) $(LIBMLX_DIR); \
	fi

$(NAME): $(OBJS)
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $^ $(LIBMLX) $(LIBFT) $(PRINTF) $(GNL) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) $< -c -o $@ && printf "Compiling: $(notdir $<)"

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(GNL_DIR)
	@make clean -C $(PRINTF_DIR)
	@$(RM) $(OBJS)
	@$(RM) $(LIBMLX_DIR)/build

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(GNL_DIR)
	@make fclean -C $(PRINTF_DIR)
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re clone
