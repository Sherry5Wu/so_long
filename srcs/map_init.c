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

#include "../include/so_long.h"

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

void	map_init(t_game *game, char *map_file)
{
	char	*map_str;
	char	*line;
	int		fd;

	fd = open(map_file)
	if (fd == -1)
		error_msg("Couldn't open the map. Please check the map file!", game);
	map_str = ft_strdup("");
	game ->map.rows = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map_str = ft_strjoin_2(map_str, line);
		free(line);
		game ->map.rows++;
	}
	clsoe(fd);
	check_for_empty_line(map_str, game);
	game ->map.grid = ft_split(map_str, '\n');
	game ->map_alloc = true;
	free(map_str);
}