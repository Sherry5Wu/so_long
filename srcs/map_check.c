

#include "../include/so_long.h"

static void	map_rows_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game ->map.columns)
	{
		if (game ->map.grid[0][i] != WALL)
			error_msg("Invalide Map. There's a wall missing in the first row!
				The map must be surroued by walls!", game);
		else if (game ->map.grid[game ->map.rows - 1][i] != WALL)
			error_msg("Invalide Map. There's a wall missing in the last row!
				The map must be surroued by walls!", game);
		i++;
	}
}

static void	map_coloumns_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game ->map.rows)
	{
		if (game ->map.grid[i][0] != WALL)
			error_msg("Invalide Map. There's a wall missing in the first coloumn!
				The map must be surroued by walls!", game);
		else if (game ->map.grid[i][game ->map.columns - 1] != WALL)
			error_msg("Invalide Map. There's a wall missing in the last coloumn!
				The map must be surroued by walls!", game);
		i++;
	}
}

static void	count_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game ->map.rows)
	{
		j = 0;
		while (j < game ->map.columns)
		{
			if (!ft_strchr(CHARACTERS, game ->map.grid[i][j]))
				error_msg("Invalid map. There is an invalid character
					in the map", game);
			else if (game ->map.grid[i][j] == COLLECTIBLE)
				game ->map.collectible++;
			else if (game ->map.grid[i][j] == PLAYER)
			{
				game ->map.players++;
				game ->map.player_posn.x = j;
				game ->map.player_posn.y = i;
			}
			else if (game ->map.grid[i][j] == MAP_EXIT)
				game ->map.exit++;
		}
	}
}

static void	verify_map_chars(t_game *game)
{
	if (game ->map.exit != 1)
		error_msg("Invalid map. The map should contain 1 and only 1
			exit.", game);
	else if (game ->map.players != 1)
		error_msg("Invalid map. The map should contain 1 and only 1
			player.", game);
	else if (game ->map.collectible == 0)
		error_msg("Invalid map. The map should contain at least 1
			collectible.", game);
}

static void	map_wall_check(t_game *game)
{
	
}

static void	map_shape_check(t_game *game)
{
	int	i;
	int	len;

	len = ft_strlen(game ->grid[0]);
	i = 1;
	while (i < game ->rows)
	{
		if (ft_strlen(game ->grid[i]) != len)
			error_msg("Invalid map. The map isn't rectange!", game);
	}
}

void	map_check(t_game *game)
{
	game ->cols = ft_strlen(game ->grid[0]);
	if (game ->rows > 120 || game ->cols > 120)
		error_msg("The map is too big. The row or coloumn can't be more
			than 120.", game);
	map_shape_check(game);
	map_wall_check(game);
	map_characters_check(game);
	map_path_check(game);
}