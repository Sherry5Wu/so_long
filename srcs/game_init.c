
#include "../include/so_long.h"

void	game_vars_init(t_game *game)
{
	game ->map.collectible = 0;
	game ->map.columns = ft_strlen(game ->map.grid[0]) - 1;
	game ->map.exit = 0;
	game ->map.players = 0;
	game ->player_sprite = RIGHT;
}