/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:14:43 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/26 09:26:10 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	window_init(t_game *game)
{
	game ->wd_height = game ->rows * CELL_SIZE;
	game ->wd_width = game ->cols * CELL_SIZE;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game ->mlx = mlx_init(game ->wd_width, game ->wd_height, TITLE, true);
	if (!game ->mlx)
		error_msg("Error generated when trying to initialize the graph.", game);
}
/*
	This function calculate the minimum width/length of the image according to the
	current window size(the window may have been resized).
*/
static void	set_image_tile(t_game *game)
{
	uint32_t	width;
	uint32_t	height;

	width = game ->wd_width / game ->cols;
	height = game ->wd_height / game -> rows;
	if (width < height)
		game ->tile = width;
	else
		game ->tile = height;
}

/*
	1.How to load a sprite from disk, then use it in the code:
		in order to display a sprite image onto our window we would first load
		the texture from disk into our memory and store the information in
		a `mlx_texture_t*`. After that we create a new `mlx_image_t*` based on the
		information given by the texture and then we can display our image onto the window.
*/
static mlx_image_t	*image_load(t_game *game, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		error_msg("Error generated when trying to load a image.", game);
	image = mlx_texture_to_image(game ->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		error_msg("Error generated when convert texture to image.", game);
	if(!mlx_resize_image(image, game ->tile, game ->tile))
		error_msg("Error geerated when resizing a image.", game);
	return (image);
}

static void	image_init(t_game *game)
{
	set_image_tile(game);
	game ->image.empty = image_load(game, "../texture/empty.png");
	game ->image.collectible = image_load(game, "../texture/collectible.png");
	game ->image.exit_close = image_load(game, "../texture/exit_close.png");
	game ->image.exit_open = image_load(game, "../texture/exit_open.png");
	game ->image.player = image_load(game, "../texture/player.png");
	game ->image.wall = image_load(game, "../texture/wall.png");
	game ->image.start = image_load(game, "../texture/start.png");

}

void	game_init(t_game *game)
{
	window_init(game);
	image_init(game);
}