/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:02:31 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/19 13:22:46 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	param_check(ac, av, game); // if ac != 2, then print out error message.
	map_init(game, av[1]); // the function will verify the map first, then initialize the map.
	game_vars_init(game);
	map_check(game);
	game_res_init(game);



}
