/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:07:41 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/25 15:01:33 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (!dest && !src)
		return (NULL);
	p_dest = dest;
	p_src = src;
	while (n > 0)
	{
		p_dest[n - 1] = p_src[n - 1];
		n--;
	}
	return (dest);
}
