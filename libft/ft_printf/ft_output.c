/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:11:15 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/29 13:11:40 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_c(int c)
{
	if ((write(1, &c, 1) != 1))
		return (-1);
	return (1);
}

int	print_str(char *str)
{
	int	i;

	if (!str)
	{
		if ((write(1, "(null)", 6) != 6))
			return (-1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		if (print_c(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	print_addrs(uintptr_t addr, int tag)
{
	char	*base_bank;
	int		char_pt;

	base_bank = "0123456789abcdef";
	char_pt = 0;
	if (tag == 0)
	{
		if (write(1, "0x", 2) != 2)
			return (-1);
		char_pt += 2;
		tag = 1;
	}
	if (addr >= 16)
	{
		char_pt += print_addrs(addr / 16, tag);
		if (char_pt == -1)
			return (-1);
	}
	if (print_c(base_bank[addr % 16]) == -1)
		return (-1);
	char_pt++;
	return (char_pt);
}

int	print_num(long nb, int base, int sign)
{
	char	*base_bank;
	int		char_pt;

	char_pt = 0;
	if (sign == 0)
		base_bank = "0123456789abcdef";
	else
		base_bank = "0123456789ABCDEF";
	if (nb < 0)
	{
		if (print_c('-') == -1)
			return (-1);
		char_pt++;
		nb *= -1;
	}
	if (nb >= base)
	{
		char_pt += print_num(nb / base, base, sign);
		if (char_pt == -1)
			return (-1);
	}
	if (print_c(base_bank[nb % base]) == -1)
		return (-1);
	char_pt++;
	return (char_pt);
}
