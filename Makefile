NAME := so_long

GREEN = \033[1;92m
DEFAULT = \033[1;39m

CC = gcc
CFLAGS := -Wall -Wextra -Werror
#-Wunreachable-code -Ofast
RM := rm -rf

# MLX library
LIBMLX_URL := https://github.com/codam-coding-college/MLX42.git
LIBMLX_DIR := ./lib/MLX42
LIBMLX := $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Libft library
LIB_DIR:= lib/libft
LIBFT_A := $(LIB_DIR)/libft.a

HEADERS := -I. -I $(LIBMLX_DIR)/include -I$(LIB_DIR)

# mandatory srcs
#SRCS_DIR = ./srcs
SRCS = draw_map_to_game.c game_init.c hook.c map_check.c map_init.c \
	move_player.c so_long.c utils.c
#SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_O))
OBJS = $(SRCS:.c=.o)


all: clone $(NAME)

# .clone_done will be generated as a hidden file, and it will contain the timestamp
# to tell if the target is latest or not. So the execute 'make' command at the second
# time, it will show "make: nothing to be done for 'all'"
clone: .clone_done

# "! -d" means if the directory doesn't exist.
.clone_done:
	@if [ ! -d "$(LIBMLX_DIR)" ]; then \
		git clone $(LIBMLX_URL) $(LIBMLX_DIR); \
		touch .clone_done; \
	fi

$(NAME): $(OBJS)
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4
	@make -C $(LIB_DIR)
	@$(CC) $^ $(LIBMLX) $(LIBFT_A) -o $@
	@echo "$(GREEN)so_long has been generated successfully!$(DEFAULT)"

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) $< -c -o $@ && printf "Compiling: $(notdir $<)"

clean:
	@make clean -C $(LIB_DIR)
	@$(RM) $(OBJS)
	@$(RM) $(LIBMLX_DIR)/build
	@$(RM) .clone_done
	@echo "$(GREEN)so_long objects have been cleaned.$(DEFAULT)"

fclean: clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME)
	@echo "$(GREEN)so_long executable file has been cleaned.$(DEFAULT)"

re:	fclean all

.PHONY: all clean fclean re clone
