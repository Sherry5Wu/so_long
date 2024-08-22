/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:14:43 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/22 11:07:06 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	window_init(t_game *game)
{
	game ->wd_height = game ->rows * CELL_SIZE;
	game ->wd_width = game ->cols * CELL_SIZE;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game ->mlx = mlx_init(game ->wd_width, game ->wd_height, TITLE, true);
	if (!game ->mlx)
		error_msg("Error generated when trying to initialize the graph.", game);
}

static void	image_init(t_game *game)
{
	??????
}

void	game_init(t_game *game)
{
	window_init(game);
	image_init(game);
}
