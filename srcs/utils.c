/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:34:50 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/22 07:34:50 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_msg(char *message, t_game *game)
{
	if (game ->map_alloc == true)
		free_map(game);
	free(game);
	ft_printf(RED"Error\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game ->map.rows)
		free(game ->map.grid[i++]);
	free(game ->map.grid);
}
