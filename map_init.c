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
		error_msg("There is an empty line right at the beginning.", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error_msg("There is an empty line in the middle.", game);
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
static char	*ft_strjoin_sl(char *s1, char *s2)
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
		3. return map_str;
	Note:
		why I didn't using ft_split() to split map_str into game->grid, , it's because
		I can't manage it within 25 lines due to the norminette rules. So I move the split
		part into map_init().
*/
static char	*read_map(char *map_file, t_game *game)
{
	int		fd;
	char	*map_str;
	char	*line;

	if (!map_file)
		error_msg("File pointer is NULL", game);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_msg("Couldn't open the map. Please check the map file!", game);
	map_str = ft_strdup("");
	game ->rows = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_str = ft_strjoin_sl(map_str, line);
		if (!map_str)
			error_msg("Failed to join two strings together.", game);
		free(line);
		game ->rows++;
	}
	close(fd);
	return (map_str);
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
	while ((uint32_t)(++y) < game ->rows)
	{
		x = -1;
		while ((uint32_t)(++x) < ft_strlen(game ->grid[y]))
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
	The function verify the map first, then initialize the map.
	1. use read_map function to read the map_file, then fill the content
	   into game ->grind.
	2. check the map.

*/
void	map_init(t_game *game, char *map_file)
{
	char	*strs;

	strs = read_map(map_file, game);
	if (game ->rows == 0)
		error_msg("The map is empty!", game);
	check_for_empty_line(strs, game);
	game ->grid = ft_split(strs, '\n');
	game ->cols = ft_strlen(game ->grid[0]);
	map_chars_init(game);
	map_check(game, strs);
	game ->cur_posn = (t_postion){game ->start.x, game ->start.y};
}
