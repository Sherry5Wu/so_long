/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:22:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/19 12:39:54 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"

typedef struct s_position
{
	uint32_t	x;
	uint32_t	y;
}	t_postion;

/*
** exit_op: exit door when it is open;
** exit_cl: exit door when it is close;
*/
typedef struct s_image
{
	uint32_t		width;
	uint32_t		heigh;
	mlx_image_t		*empty;
	mlx_image_t		*wall;
	mlx_image_t		*collect;
	mlx_image_t		*exit_op;
	mlx_image_t		*exit2_cl;
	mlx_image_t		*plater;
}	t_image;

typedef struct s_map
{
	mlx_t		*mlx;
	t_image		image;
	char		**grid;
	uint32_t	rows;
	uint32_t	cols;
	uint32_t	wd_width;
	uint32_t	wd_height;
	uint32_t	scale;
	uint32_t	move;
	uint32_t	cpllect_all;
	uint32_t	collect_get;
	uint32_t	player_n;
	uint32_t	exit_n;
	t_postion	exit;
	t_postion	start;
	t_postion	cur;
	t_postion	next;
}	t_map;


#endif
