/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:09:55 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/28 10:30:56 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Invalid moves:
		- move to wall;
		- move to the same postion(current position and next position are same);
*/
static bool	is_valid_move(t_game *game)
{
	if (game ->cur_posn.x == game ->next_posn.x
		&& game ->cur_posn.y == game ->next_posn.y)
	{
		ft_printf(RED"Invalid move. It is the same postion.\n"RESET);
		return (false);
	}
	else if (game ->grid[game ->next_posn.y][game ->next_posn.x] == WALL)
	{
		ft_printf(RED"You can't move to the WALL.\n"RESET);
		return (false);
	}
	return (true);
}

/*
	The function will:
		- collect the colletible(game ->collect_get++);
		- disable the collectible image;
		- set the current postion to Free Space in the map(because the collectible is
		  collected)
		- if collect all the collectibles, then disable the 'exit_close' iamge (then it
		  will render the 'exit_open' image).
*/
static void	collect(t_game *game)
{
	uint32_t	i;

	i = 0;
	game ->collect_get++;
	game ->grid[game ->cur_posn.y][game ->cur_posn.x] = F_SPACE;
	ft_printf(CYAN"Found one! Carrots: %u/%u\n"RESET,
		game ->collect_get, game ->collect_all);
	while (i < game ->image.collectible ->count)
	{
		if ((uint32_t)game ->image.collectible ->instances[i].x
			== game ->cur_posn.x * game ->tile
			&& (uint32_t)game ->image.collectible
			->instances[i].y == game ->cur_posn.y * game ->tile)
			game ->image.collectible ->instances[i].enabled = false;
		i++;
	}
	if (game ->collect_get == game ->collect_all)
	{
		game ->image.exit_close->instances[0].enabled = false;
		game ->grid[game ->exit_posn.y][game ->exit_posn.x] = EXIT_OPEN;
		ft_printf(GREEN_B"YEAH! ALL carrots are collected!\n"RESET);
	}
}

/*
	The function will do:
	1. check if the move is valid (not to the wall, not the same postion);
	2. move the player image to the next postion, set current postion in map to '0',
	   and print the moves;
	3. After move the player, then check the current postion:
		== COLLECTIBLE    --> go to collect the collectible
		== MAP_EXIT       --> print messge;
		== EXIT_OPEN      --> the game player win.Print message and quit the game.
*/
void	move_player(t_game *game)
{
	char	c;

	if (!is_valid_move(game))
		return ;
	game ->image.player ->instances[0].x = game ->next_posn.x * game ->tile;
	game ->image.player ->instances[0].y = game ->next_posn.y * game ->tile;
	game ->move++;
	ft_printf("moves: %u\n", game ->move);
	game ->cur_posn = game ->next_posn;
	c = game ->grid[game ->cur_posn.y][game ->cur_posn.x];
	if (c == COLLECTIBLE)
		collect(game);
	else if (c == MAP_EXIT)
	{
		ft_printf(RED"Need collect all the carrots before leave!\n"RESET);
		ft_printf(CYAN"Carrots: %u/%u\n"RESET,
			game ->collect_get, game ->collect_all);
	}
	else if (c == EXIT_OPEN)
	{
		ft_printf(GREEN_B"Hooray, YOU WIN!\n"RESET);
		quit_game(game);
	}
}
