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

#include "../include/so_long_bonus.h"

/*
	The function is checking if there is any empty lines in the map：
	Beginnning, end and in the middle.
*/
static void	check_for_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		error_msg("Invalid map. There is an empty line right at the beginning.", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		error_msg("Invalid map. There is an empty line at the end.", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error_msg("Invalid map. There is an empty line in the middle.", game);
		}
		i++;
	}
}

/*
	Based on ft_strjoin in libft, code for releasing the memory has been added.

	Description:
	Allocates (with malloc(3)) and returns a new string, which is the
	result of the concatenation of ’s1’ and ’s2’.

	Parameters:
	s1:  The prefix string.
	s2:  The suffix string.

	Return value:
	The new string.NULL if the allocation fails.
*/
static char	*ft_strjoin_2(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, (s1_len + 1));
	ft_strlcat(newstr, s2, (s1_len + s2_len + 1));
	free(s1);
	return (newstr);
}

/*
	The fucntion is reading the content from map_file, then fill it into game ->grid.

	Solution:
		1. open the map_file;
		2. read the content line by line, then using ft_strjoin_2 put them into map_str;
		3. using ft_split put the content in map_str to game ->grid;
	Note:
		if after execute this function, the project doesn't failed exit, then it means
		the game ->grid is not empty.
*/
static void	read_map(char *map_file, t_game *game)
{
	int		fd;
	char	*map_str;
	char	*line;

	if (!map_file)
		error_msg("File pointer is NULL", game);
	fd = open(map_file);
	if (fd == -1)
		error_msg("Couldn't open the map. Please check the map file!", game);
	map_str = ft_strdup("");
	game ->rows = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			error_msg("Failed to get content from the map.", game);
		if (!(map_str = ft_strjoin_2(map_str, line)))
			error_msg("Failed to join two strings together.", game);
		free(line);
		game ->rows++;
	}
	clsoe(fd);
	check_for_empty_line(map_str, game);
	game ->grid = ft_split(map_str, '\n');
	free(map_str);
}
/*
	Initialize for game ->collect_all, game ->player_n, game ->exit_n,
	game ->start, game ->exit.
*/
static void	map_chars_init(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game ->rows)
	{
		x = -1;
		while (++x < game ->cols)
		{
			if (!ft_strchr(CHARACTERS, game ->grid[y][x]))
				error_msg("Invalid map. There is an invalid character.", game);
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
	The function will do these things:
	1. use read_map function to read the map_file, then fill the content
	   into game ->grind.
	2. check the map.

*/
void	map_init(t_game *game, char *map_file)
{
	read_map(map_file, game);
	map_chars_init(game);
	map_check(game);
	game ->cur_posn = (t_postion){game ->start.x, game ->start.y};
}
