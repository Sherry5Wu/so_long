
#include "../include/so_long.h"

void	error_msg(char *message, t_game *game)
{
	if (game ->map_alloc == true)
		free_map(game);
	free(game);
	ft_printf(RED"Error\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game ->map.rows)
		free(game ->map.grid[i++]);
	free(game ->map.grid);
}