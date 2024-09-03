/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:39:49 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/29 13:40:41 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *fmt, ...);
int	print_c(int c);
int	print_str(char *str);
int	print_addrs(uintptr_t addr, int tag);
int	print_num(long nb, int base, int sign);

#endif
