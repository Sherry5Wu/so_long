/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:02:31 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/28 10:41:21 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	param_check(int ac, char **av, t_game *game)
{
	int	len;

	if (ac < 2)
		error_msg("No map is added! please add one map(.ber)!", game);
	else if (ac > 2)
		error_msg("Too many maps! Only one map is accepted each time!", game);
	len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][len - 4], ".ber", 4))
		error_msg("Map file extention is wrong (It should be .ber).", game);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	param_check(ac, av, &game);
	map_init(&game, av[1]);
	game_init(&game);
	draw_map_to_game(&game);
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_close_hook(game.mlx, close_hook, &game);
	mlx_loop(game.mlx);
	exit(0);
}
