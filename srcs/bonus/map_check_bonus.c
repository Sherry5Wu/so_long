/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:34:04 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/22 07:34:04 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	map_chars_check(t_game *game)
{
	if (game ->exit_n != 1)
		error_msg("Invalid map. The map should contain 1 and only 1 exit.", game);
	else if (game ->player_n != 1)
		error_msg("Invalid map. The map should contain 1 and only 1 player.", game);
	else if (game ->collect_all == 0)
		error_msg("Invalid map. The map should contain at least 1 collectible.", game);
}

static void	map_wall_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game ->cols)
	{
		if (game ->grid[0][i] != WALL || game ->grid[game ->rows - 1][i] != WALL)
			error_msg("Invalide Map. There's a wall missing in the first or last
				 row! The map must be surroued by walls!", game);
		i++;
	}
	i = 0;
	while (i < game ->rows)
	{
		if (game ->grid[i][0] != WALL || game ->grid[i][game ->cols - 1] != WALL)
			error_msg("Invalide Map. There's a wall missing in the first or last
				coloumn! The map must be surroued by walls!", game);
		i++;
	}
}

static void	map_shape_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game ->rows)
	{
		if (ft_strlen(game ->grid[i]) != game ->cols)
			error_msg("Invalid map. The map isn't rectange!", game);
	}
}
/*
	The function will:
		1. start from "start" coordinate, as player's start position, then it will
		   go through all the non-wall position, as the same time, it will count the
		   times of P, C and E.
		2. After getting the count of P, C and E. It will check will origianl count.
			- if exit != 1 || collect != game ->collect_all, then
			  there is NO valid path in the map;
			- otherwise, there is a valid path in the map(can collect all the collectibles
			  and get out from exit).
*/
static void	map_path_check(t_game *game, t_postion curt)
{
	static int	collect;
	static int	exit;

	if (game ->grid[curt.y][curt.x] == WALL)
		return ;
	else if (game ->grid[curt.y][curt.x] == COLLECTIBLE)
		collect++;
	else if (game ->grid[curt.y][curt.x] == MAP_EXIT)
		exit++;
	map_path_check(game, (t_postion){curt.x + 1, curt.y});
	map_path_check(game, (t_postion){curt.x - 1, curt.y});
	map_path_check(game, (t_postion){curt.x, curt.y + 1});
	map_path_check(game, (t_postion){curt.x, curt.y - 1});
	if (collect != game ->collect_all)
		error_msg("Couldn't find a path to collect all the collectibles.", game);
	else if (exit != 1)
		error_msg("Couldn't find a path to the exit.", game);
}

void	map_check(t_game *game)
{
	game ->cols = ft_strlen(game ->grid[0]);
	if (game ->rows > 120 || game ->cols > 120)
		error_msg("The map is too big. The row or coloumn can't be more
			than 120.", game);
	map_shape_check(game);
	map_wall_check(game);
	map_chars_check(game);
	map_path_check(game, game ->start);
}
