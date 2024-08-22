/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 08:48:03 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/22 08:48:03 by jingwu           ###   ########.fr       */
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
