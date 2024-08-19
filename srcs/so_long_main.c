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

static void	param_check(int ac, char **av)
{
	int		len_of_param;
	if (ac < 2)
	{
		ft_printf("No map is added! please add one map(.ber)!");
		exit (1);
	}
	else if (ac > 2)
	{
		ft_printf("Too many maps! Only one map is accepted each time!\n");
		exit (1);
	}
	len_of_param = ft_strlen(av[1]);
	if (!f_strnstr(&av[1][len_of_param - 4], ".ber", 4))
	{
		ft_printf("Map file extention is wrong (It should be .ber).\n");
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_map	*map;

	ft_bzero(map, sizeof(t_map));
	param_check(ac, av);
	map_init(map, av[1]);


}
