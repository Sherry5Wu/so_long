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

#include "so_long.h"

void	error_msg(char *message, t_game *game)
{
	free_game(game);
	ft_printf(RED"Error\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_image(game);
	if (game ->grid)
		free_matrix(game ->grid, game ->rows);
	if (game ->mlx)
		mlx_terminate(game ->mlx);
}

void	free_image(t_game *game)
{
	if (game ->image.collectible)
		mlx_delete_image(game ->mlx, game ->image.collectible);
	if (game ->image.empty)
		mlx_delete_image(game ->mlx, game ->image.empty);
	if (game ->image.exit_close)
		mlx_delete_image(game ->mlx, game ->image.exit_close);
	if (game ->image.exit_open)
		mlx_delete_image(game ->mlx, game ->image.exit_open);
	if (game ->image.player)
		mlx_delete_image(game ->mlx, game ->image.player);
	if (game ->image.start)
		mlx_delete_image(game ->mlx, game ->image.start);
	if (game ->image.wall)
		mlx_delete_image(game ->mlx, game ->image.wall);
}

void	free_matrix(char **matrix, int row)
{
	if (!matrix || !*matrix)
		return ;
	while (--row >= 0)
		free (matrix[row]);
	free (matrix);
}

void	quit_game(t_game *game)
{
	if (game)
		free_game(game);
	exit(0);
}
