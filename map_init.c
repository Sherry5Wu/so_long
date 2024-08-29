/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:02:31 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/19 13:22:46 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_rows(char *map_file, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_msg("Couldn't open the map file!", game, NULL);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		game ->rows++;
		free(line);
	}
	close(fd);
}
/*
	The fucntion is reading the content from map_file, then fill it into game ->grid.

	Solution:
		1. open the map_file;
		2. read the content line by line, then using ft_strjoin_2 put them into map_str;
		3. return map_str;
	Note:
		why I didn't using ft_split() to split map_str into game->grid, , it's because
		I can't manage it within 25 lines due to the norminette rules. So I move the split
		part into map_init().
*/
static void	read_map(char *map_file, t_game *game)
{
	int			fd;
	uint32_t	y;
	char		*line;

	init_game_rows(map_file, game);
	game ->grid = malloc(sizeof(char *) * (game ->rows + 1));
	if (!game ->grid)
		error_msg("Failed to create map grid!", game , NULL);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_msg("Couldn't open the map file!", game, NULL);
	y = 0;
	while (y < game ->rows)
	{
		line = get_next_line(fd);
		if (!line)
			error_msg("Failed to read the row.", game, NULL);
		game ->grid[y] = ft_strtrim(line, "\n");
		if (!game ->grid[y])
			error_msg("Failed to creat new row.", game, line);
		free(line);
		y++;
	}
	close(fd);
}

static void	map_chars_init(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while ((uint32_t)(++y) < game ->rows)
	{
		x = -1;
		while ((uint32_t)(++x) < ft_strlen(game ->grid[y]))
		{
			if (!ft_strchr(CHARACTERS, game ->grid[y][x]))
				error_msg("Invalid map. There is an invalid character.", game, NULL);
			else if (game ->grid[y][x] == COLLECTIBLE)
				game ->collect_all++;
			else if (game ->grid[y][x] == PLAYER)
			{
				game ->player_n++;
				game ->start = (t_postion){x, y};
			}
			else if (game ->grid[y][x] == MAP_EXIT)
			{
				game ->exit_n++;
				game ->exit_posn = (t_postion){x, y};
			}
		}
	}
}

/*
	The function verify the map first, then initialize the map.
	1. use read_map function to read the map_file, then fill the content
	   into game ->grind.
	2. check the map.

*/
void	map_init(t_game *game, char *map_file)
{

	read_map(map_file, game);
	if (game ->rows == 0)
		error_msg("The map is empty!", game, NULL);
	game ->cols = ft_strlen(game ->grid[0]);
	map_chars_init(game);
	map_shape_check(game);
	map_wall_check(game);
	map_chars_check(game);
	map_path_check(game);
	game ->cur_posn = (t_postion){game ->start.x, game ->start.y};
}
