
#include "../include/so_long.h"

static void	add_image(t_game *game, mlx_image_t *img, t_postion posn)
{
	if (mlx_image_to_window(game ->mlx, img, posn.x * game ->scale,
			posn.y * game ->scale) == -1)
		error_msg("Error generated when add image to the game.", game);
}

static void	draw_img(t_game *game, t_postion posn)
{
	char	c;

	c = game ->grid[posn.y][posn.x];
	if (c == WALL)
		add_image(game, game ->image.wall, posn);
	else if (c == F_SPACE)
		add_image(game, game ->image.empty, posn);
	else if (c == COLLECTIBLE)
	{
		add_image(game, game ->image.empty, posn);
		add_image(game, game ->image.collectible, posn);
	}
	else if (c == MAP_EXIT)
	{
		add_image(game, game ->image.exit_open, posn);
		add_image(game, game ->image.exit_close, posn);
	}

}

void	draw_map_to_game(t_game *game)
{
	int32_t	x;
	int32_t	y;

	y = -1;
	while (++y < game ->rows)
	{
		x = -1;
		while (++x < game ->cols)
			draw_img(game, (t_postion){x, y});
	}
	add_image(game, game ->image.player, game ->cur_posn);
}