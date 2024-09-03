/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:11:59 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/29 13:11:59 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	specifier(const char fmt, va_list arg)
{
	int	char_pt;

	char_pt = 0;
	if (fmt == 'c')
		char_pt = print_c(va_arg(arg, int));
	else if (fmt == 's')
		char_pt = print_str(va_arg(arg, char *));
	else if (fmt == 'p')
		char_pt = print_addrs(va_arg(arg, uintptr_t), 0);
	else if (fmt == 'd' || fmt == 'i')
		char_pt = print_num((long)va_arg(arg, int), 10, 0);
	else if (fmt == 'u')
		char_pt = print_num((long)va_arg(arg, unsigned int), 10, 0);
	else if (fmt == 'x')
		char_pt = print_num((long)va_arg(arg, unsigned int), 16, 0);
	else if (fmt == 'X')
		char_pt = print_num((long)va_arg(arg, unsigned int), 16, 1);
	else
		char_pt = print_c(fmt);
	return (char_pt);
}

static int	format(const char *fmt, va_list arg)
{
	int	char_pt;
	int	i;
	int	re_value;

	i = 0;
	char_pt = 0;
	while (fmt[i])
	{
		while (fmt[i] != '%' && fmt[i])
		{
			if (print_c(fmt[i]) == -1)
				return (-1);
			char_pt++;
			i++;
		}
		if (fmt[i] == '%')
		{
			re_value = specifier(fmt[++i], arg);
			if (re_value == -1)
				return (-1);
			char_pt += re_value ;
			i++;
		}
	}
	return (char_pt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arg;
	int		char_pt;

	va_start(arg, fmt);
	if (!fmt || !*fmt)
		return (0);
	char_pt = 0;
	char_pt = format(fmt, arg);
	va_end(arg);
	return (char_pt);
}
