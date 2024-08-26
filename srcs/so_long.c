/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:02:31 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/26 10:11:31 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	param_check(int ac, char **av, t_game *game)
{
	int	len;

	if (ac < 2)
		error_msg("No map is added! please add one map(.ber)!", game);
	else if (ac > 2)
		error_msg("Too many maps! Only one map is accepted each time!", game);
	len = ft_strlen(av[1]);
	if (!f_strnstr(&av[1][len - 4], ".ber", 4))
		error_msg("Map file extention is wrong (It should be .ber).\n", game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	ft_bzero(game, sizeof(t_game));
	param_check(ac, av, game); // if ac != 2, then print out error message.
	map_init(game, av[1]); // the function will verify the map first, then initialize the map.
	game_init(game);
	draw_map_to_game(game);
	mlx_key_hook(game ->mlx, keyhook_wsad, game); // ??? why not "&keyhook", check Hooks.md in docs
	mlx_key_hook(game ->mlx, keyhook_arrowkeys, game);
	mlx_close_hook(game ->mlx, close_hook, game);
	mlx_loop(game ->mlx);
	exit(0);
}
