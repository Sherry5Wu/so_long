/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:02:31 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/22 10:34:32 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	param_check(ac, av, game); // if ac != 2, then print out error message.
	map_init(game, av[1]); // the function will verify the map first, then initialize the map.
	game_init(game);
	draw_map_to_game(game);

	game_vars_init(game);
	game_res_init(game);

	exit(0);
}
