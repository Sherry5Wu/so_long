/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:24:26 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/23 09:59:21 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memcmp compares the first n bytes of the memory areas
	s1 and s2. The bytes are interpreted as unsigned char.

	RETURN VALUE :
	An integer less than, equal to, or greater than zero if the first
	n bytes of s1 is found to be less than, equal to, or greater than the 
	first n bytes of s2. Zero if n is equal to zero.
*/

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*c_str1;
	const unsigned char	*c_str2;

	i = 0;
	c_str1 = (unsigned char *)str1;
	c_str2 = (unsigned char *)str2;
	while (i < n)
	{
		if (c_str1[i] != c_str2[i])
			return ((int)(c_str1[i] - c_str2[i]));
		i++;
	}
	return (0);
}
