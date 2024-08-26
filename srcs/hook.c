/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 07:48:03 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/26 15:00:31 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	keyhook_wsad(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit_game(game);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		game ->next_posn = (t_postion){game ->cur_posn.x, game ->cur_posn.y - 1};
		move_player(game);
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		game ->next_posn = (t_postion){game ->cur_posn.x, game ->cur_posn.y + 1};
		move_player(game);
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		game ->next_posn = (t_postion){game ->cur_posn.x - 1, game ->cur_posn.y};
		move_player(game);
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		game ->next_posn = (t_postion){game ->cur_posn.x + 1, game ->cur_posn.y};
		move_player(game);
	}
}

void	keyhook_arrowkeys(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		game ->next_posn = (t_postion){game ->cur_posn.x, game ->cur_posn.y - 1};
		move_player(game);
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		game ->next_posn = (t_postion){game ->cur_posn.x, game ->cur_posn.y + 1};
		move_player(game);
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		game ->next_posn = (t_postion){game ->cur_posn.x - 1, game ->cur_posn.y};
		move_player(game);
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		game ->next_posn = (t_postion){game ->cur_posn.x + 1, game ->cur_posn.y};
		move_player(game);
	}
}

void	close_hook(void *param)
{
	t_game *game;

	game = (t_game *)param;
	??????
}
