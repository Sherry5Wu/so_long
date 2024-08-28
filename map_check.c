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

#include "so_long.h"

static void	map_chars_check(t_game *game)
{
	if (game ->exit_n != 1)
		error_msg("The map should contain 1 and only 1 exit.", game);
	else if (game ->player_n != 1)
		error_msg("The map should contain 1 and only 1 player.", game);
	else if (game ->collect_all == 0)
		error_msg("The map should contain at least 1 collectible.", game);
}

static void	map_wall_check(t_game *game)
{
	uint32_t	i;

	i = 0;
	while (i < game ->cols)
	{
		if (game ->grid[0][i] != WALL
				|| game ->grid[game ->rows - 1][i] != WALL)
			error_msg("A wall missing in the first or last row!", game);
		i++;
	}
	i = 0;
	while (i < game ->rows)
	{
		if (game ->grid[i][0] != WALL
				|| game ->grid[i][game ->cols - 1] != WALL)
			error_msg("A wall missing in the first or last coloumn!", game);
		i++;
	}
}

static void	map_shape_check(t_game *game)
{
	uint32_t	y;

	y = 0;
	while (y < game ->rows)
	{
		if (ft_strlen(game ->grid[y]) != game ->cols)
			error_msg("Invalid map. The map isn't rectange!", game);
		y++;
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
static int	map_path_check(t_game *game, t_postion curt, char **matrix)
{
	static uint32_t	collect = 0;
	static uint32_t	exit_c = 0;

	if (matrix[curt.y][curt.x] == WALL)
		return (0);
	else if (matrix[curt.y][curt.x] == 'C')
		collect++;
	else if (matrix[curt.y][curt.x] == MAP_EXIT)
		exit_c++;
	matrix[curt.y][curt.x] = WALL;
	map_path_check(game, (t_postion){curt.x + 1, curt.y}, matrix);
	map_path_check(game, (t_postion){curt.x - 1, curt.y}, matrix);
	map_path_check(game, (t_postion){curt.x, curt.y + 1}, matrix);
	map_path_check(game, (t_postion){curt.x, curt.y - 1}, matrix);
	if (collect == game ->collect_all && exit_c == 1)
		return (1);
	return (0);
}

void	map_check(t_game *game, char *strs)
{
	char	**matrix;

	matrix = ft_split(strs, '\n');
	free(strs);
	map_shape_check(game);
	map_wall_check(game);
	map_chars_check(game);
	if (map_path_check(game, game ->start, matrix) == 0)
		error_msg("Invalid map! There is no path.", game);
	free_matrix(matrix, game ->rows);
}
