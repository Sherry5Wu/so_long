/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:22:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/19 12:39:54 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

// window title
# define TITLE		"so long"

// characters used in the map
# define CHARACTERS	"10CPE"

// the output text colors
# define GREEN		"\033[0;32m"
# define RED		"\033[1;31m"
# define GREEN		"\033[0;32m"
# define RED		"\033[1;31m"
# define GREY		"\033[0;90m"
# define CYAN		"\033[1;96m"
# define RESET		"\033[0m"

// coordinate
typedef struct s_position
{
	uint32_t	x;
	uint32_t	y;
}	t_postion;

/*
** exit_op: exit door when it is open;
** exit_cl: exit door when it is close;
*/
typedef struct s_image
{
	uint32_t		width;
	uint32_t		heigh;
	mlx_image_t		*empty;
	mlx_image_t		*wall;
	mlx_image_t		*collectible;
	mlx_image_t		*exit_open;
	mlx_image_t		*exit_close;
	mlx_image_t		*player;
}	t_image;

/*
	all the params need for the game.
	grid: the copy of the map file.
	scale: the image size.
	move: the steps of player.
	cur_posn: the player current position.
	next: the next position where player will move to.
*/
typedef struct s_game
{
	mlx_t		*mlx;
	t_image		image;
	char		**grid;
	uint32_t	rows;
	uint32_t	cols;
	uint32_t	wd_width;
	uint32_t	wd_height;
	uint32_t	scale;
	uint32_t	move;
	uint32_t	collect_all;
	uint32_t	collect_get;
	uint32_t	player_n;
	uint32_t	exit_n;
	t_postion	exit;
	t_postion	start;
	t_postion	cur;
	t_postion	next;
}	t_game;

// errors_checking.c
void	param_check(int ac, char **av, t_game *game);

// map_init.c
void	map_init(t_game *game, char *map_file);

// utils.c
void	error_msg(char *message, t_game *game);
void	free_map(t_game *game);

#endif
