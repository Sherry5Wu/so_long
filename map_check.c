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

/*
	The function is for checking if the map is only contain 1 player, 1 exit,
	and at least 1 collectible.
*/
void	map_chars_check(t_game *game)
{
	if (game ->exit_n != 1)
		error_msg("The map should contain 1 and only 1 exit.", game, NULL);
	else if (game ->player_n != 1)
		error_msg("The map should contain 1 and only 1 player.", game, NULL);
	else if (game ->collect_all == 0)
		error_msg("The map should contain at least 1 collectible.", game, NULL);
}

/*
	The function is for checking if the map is surrounding by wall.
*/
void	map_wall_check(t_game *game)
{
	uint32_t	i;

	i = 0;
	while (i < game ->cols)
	{
		if (game ->grid[0][i] != WALL
				|| game ->grid[game ->rows - 1][i] != WALL)
			error_msg("A wall missing in the first or last row!", game, NULL);
		i++;
	}
	i = 0;
	while (i < game ->rows)
	{
		if (game ->grid[i][0] != WALL
				|| game ->grid[i][game ->cols - 1] != WALL)
			error_msg("Wall missing in the first or last coloumn!", game, NULL);
		i++;
	}
}

/*
	The function is for checking if the map is rectange shape.
*/
void	map_shape_check(t_game *game)
{
	uint32_t	y;

	y = 0;
	while (y < game ->rows)
	{
		if (ft_strlen(game ->grid[y]) != game ->cols)
			error_msg("Invalid map. The map isn't rectange!", game, NULL);
		y++;
	}
}

/*
	1. The function starts from 'curt' postion, then using recursive method to go throught all the
	non-wall postions.
	2. In the recursive, it will count the encounter times of C and E.
	3.  After getting the count of C and E. It will check will origianl count.
		- if exit != 1 or collect != game ->collect_all, then there is NO valid path in the map.
		- otherwise, there is a valid path in the map(can collect all the collectibles
		and get out from exit).

	return value:
		true: there is a path;
		false: there is NOT a path;
*/
static bool	find_path(t_game *game, t_postion curt, char **matrix)
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
	find_path(game, (t_postion){curt.x + 1, curt.y}, matrix);
	find_path(game, (t_postion){curt.x - 1, curt.y}, matrix);
	find_path(game, (t_postion){curt.x, curt.y + 1}, matrix);
	find_path(game, (t_postion){curt.x, curt.y - 1}, matrix);
	if (collect == game ->collect_all && exit_c == 1)
		return (true);
	return (false);
}

/*
	Dupliate a new map saving into matx. Then call find_path() to see if there is path to
	collect all the collectibles and get out from exit.
*/
void	map_path_check(t_game *game)
{
	char		**matx;
	uint32_t	i;

	i = 0;
	matx = malloc(sizeof(char *) * (game ->rows + 1));
	if (!matx)
		error_msg("Malloc error.", game, NULL);
	while (i < game ->rows)
	{
		matx[i] = ft_strdup(game ->grid[i]);
		if (!matx[i])
		{
			free_matrix(matx, i);
			error_msg("Error generate when duplicating rows.", game, NULL);
		}
		i++;
	}
	if (!find_path(game, game ->start, matx))
		error_msg("There is no path in the map.", game, NULL);
	free_matrix(matx, i);
}
