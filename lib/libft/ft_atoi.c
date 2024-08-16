/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:33:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/05/06 09:07:48 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Solution 1
int	ft_atoi(const char *str)
{
	int				sign;
	long long int	integer;

	sign = 1;
	integer = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		if (sign == -1 && (integer > 922337203685477580
				|| (integer == 922337203685477580 && *(str + 1) > 8)))
			return (0);
		else if (integer > 922337203685477580
			|| (integer == 922337203685477580 && *(str + 1) > 7))
			return (-1);
		integer = integer * 10 + (*str - '0');
		str++;
	}
	return (((int)integer) * sign);
}

//Solution 2
// int	ft_atoi(const char *str)
// {
// 	int		sign;
// 	long	integer;
// 	long	check;

// 	sign = 1;
// 	integer = 0;
// 	while ((*str >= 9 && *str <= 13) || *str == 32)
// 		str++;
// 	if (*str == '+' || *str == '-')
// 		if (*str++ == '-')
// 			sign = -1;
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		check = integer * 10 + (*str - '0');
// 		if (sign == -1 && check / 10 != integer)
// 			return (0);
// 		else if (sign == 1 && check / 10 != integer)
// 			return (-1);
// 		integer = check;
// 		str++;
// 	}
// 	return (((int)integer) * sign);
// }