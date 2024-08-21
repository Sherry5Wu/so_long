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

// window paramters
# define WIN_WIDTH	(512)
# define WIN_HEIGHT	(512)
# define TITLE		"so long"

// the output text colors
# define GREEN		"\033[0;32m"
# define RED		"\033[1;31m"
# define GREEN		"\033[0;32m"
# define RED		"\033[1;31m"
# define GREY		"\033[0;90m"
# define CYAN		"\033[1;96m"
# define RESET		"\033[0m"

// player_sprite
# define FRONT		1
# define LEFT		2
# define RIGHT		3
# define BACK		4

// map characters
# define WALL			'1'
# define COLLECTIBLE	'C'
# define F_SPACE		'0'
# define PLAYER			'P'
# define MAP_EXIT		'E'
# define CHARACTERS		"10CPE"

typedef enum s_bool
{
	true,
	false
}	e_bool;

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
	void		*xpm_ptr;
	uint32_t	width;
	uint32_t	heigh;

}	t_image;

typedef struct s_map
{
	char		**grid;
	uint32_t	rows;
	uint32_t	columns;
	uint32_t	collectible;
	uint32_t	exit;
	uint32_t	players;
	t_postion	player_posn;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	uint32_t	movements;
	uint32_t	player_sprite;
	t_map		map;
	e_bool		map_alloc;
	t_image		wall;
	t_image		f_space;
	t_image		collectible;
	t_image		exit_open;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

// param_check.c
void	param_check(int ac, char **av, t_game *game);

// map_init.c
void	map_init(t_game *game, char *map_file);

// game_init.c
void	game_vars_init(t_game *game);

// map_check.c
void	map_check(t_game *game);

// utils.c
void	error_msg(char *message, t_game *game);
void	free_map(t_game *game);

#endif
