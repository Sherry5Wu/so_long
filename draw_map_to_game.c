/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_to_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:33:02 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/27 07:33:02 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_image(t_game *game, mlx_image_t *img, t_postion posn)
{
	if (mlx_image_to_window(game ->mlx, img, posn.x * game ->tile,
			posn.y * game ->tile) == -1)
		error_msg("Error generated when add image to the game.", game, NULL);
}

static void	draw_img(t_game *game, t_postion posn)
{
	char	c;

	c = game ->grid[posn.y][posn.x];
	if (c == WALL)
	{
		add_image(game, game ->image.empty, posn);
		add_image(game, game ->image.wall, posn);
	}
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
	else if (c == PLAYER)
		add_image(game, game ->image.empty, posn);
}
/*
	The funtion will loop the map, and call draw_img() to draw the correct image on the
	correct place.
	At the end, it will draw player image to the player place, to make sure player's layer
	is on top.
*/

void	draw_map_to_game(t_game *game)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < game ->rows)
	{
		x = 0;
		while (x < game ->cols)
		{
			draw_img(game, (t_postion){x, y});
			x++;
		}
		y++;
	}
	add_image(game, game ->image.player, game ->cur_posn);
}
