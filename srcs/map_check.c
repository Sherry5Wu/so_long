

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

void	map_check(t_game *game)
{
	map_rows_check(game);
	map_coloumns_check(game);
	count_map_params(game);
	verify_map_params(game);
}