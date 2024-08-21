
#include "../include/so_long.h"

static void	game_mlx_init(t_game *game)
{
	game ->mlx_ptr = mlx_init(WIN_WIDTH, WIN_HEIGHT, TITLE, true);
	if (!game ->mlx_ptr)
	{
		free(game ->mlx_ptr);
		error_msg("Failed to initialize the window.", game);
	}
}

void	game_vars_init(t_game *game)
{
	game ->map.collectible = 0;
	game ->map.columns = ft_strlen(game ->map.grid[0]) - 1;
	game ->map.exit = 0;
	game ->map.players = 0;
	game ->player_sprite = RIGHT;
}

void	game_res_init(t_game *game)
{
	game_mlx_init(game);
	game_sprite_init(game);
}