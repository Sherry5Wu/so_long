/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:22:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/22 13:07:51 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

// game title
# define TITLE		"so long"
# define CELL_SIZE	(16)

// characters used in the map
# define CHARACTERS	"10CPE"
# define WALL			'1'
# define COLLECTIBLE	'C'
# define F_SPACE		'0'
# define PLAYER			'P'
# define MAP_EXIT		'E'

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
	uint32_t		width; //init in image_scale_check()
	uint32_t		height; //init in image_scale_check()
	mlx_image_t		*empty;
	mlx_image_t		*wall;
	mlx_image_t		*collectible;
	mlx_image_t		*exit_open;
	mlx_image_t		*exit_close;
	mlx_image_t		*player;
	mlx_image_t		*start;
}	t_image;

/*
	all the params need for the game.
	grid: the copy of the map file.
	scale: the image size.
	move: the steps of player.
	cur_posn: the player current position.
	next_posn: the next position where player will move to.
*/
typedef struct s_game
{
	mlx_t		*mlx; // init in window_init()
	t_image		image;
	char		**grid;	// init in read_map
	uint32_t	rows;	// init in read_map
	uint32_t	cols;	// init in map_check
	uint32_t	wd_width; // init in window_init()
	uint32_t	wd_height; // init in window_init()
	uint32_t	scale; //init in image_scale_check()
	uint32_t	move;
	uint32_t	collect_all;	// init in map_chars_init
	uint32_t	collect_get;	// init in map_chars_init
	uint32_t	player_n;	// init in map_chars_init
	uint32_t	exit_n;	// init in map_chars_init
	t_postion	exit_posn;	// init in map_chars_init
	t_postion	start;	// init in map_chars_init
	t_postion	cur_posn;	// init in map_init
	t_postion	next_posn;
}	t_game;

// param_check.c
void	param_check(int ac, char **av, t_game *game);

// map_init.c
void	map_init(t_game *game, char *map_file);

// map_check.c
void	map_check(t_game *game);

// game_init.c
void	game_init(t_game *game);

// draw_map_to_game.c
void	draw_map_to_game(t_game *game);

// utils.c
void	error_msg(char *message, t_game *game);
void	free_map(t_game *game);

#endif
