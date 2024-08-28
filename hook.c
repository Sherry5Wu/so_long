/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 07:48:03 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/28 10:02:38 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	execute_keyhook_action(t_game *game, char key)
{
	if (key == 'U')
	{
		game ->next_posn = (t_postion){game ->cur_posn.x,
			game ->cur_posn.y - 1};
		move_player(game);
	}
	else if (key == 'D')
	{
		game ->next_posn = (t_postion){game ->cur_posn.x,
			game ->cur_posn.y + 1};
		move_player(game);
	}
	else if (key == 'L')
	{
		game ->next_posn = (t_postion){game ->cur_posn.x - 1,
			game ->cur_posn.y};
		move_player(game);
	}
	else if (key == 'R')
	{
		game ->next_posn = (t_postion){game ->cur_posn.x + 1,
			game ->cur_posn.y};
		move_player(game);
	}
}

/*
	Because I want support both "WSAD" and the arrow up,  arrow down, arrow left, arrow
	right keys. I can't mange all the codes in one function and that function is less
	than 25 lines. So I seprate them into two functions: keyhook() and execute_keyhook_action().
*/
void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit_game(game);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		execute_keyhook_action(game, 'U');
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		execute_keyhook_action(game, 'D');
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		execute_keyhook_action(game, 'L');
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		execute_keyhook_action(game, 'R');
}

void	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_game(game);
	exit(0);
}
