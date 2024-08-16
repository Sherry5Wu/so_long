/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:45:58 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/23 08:46:57 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
	Description: 
	The function searches for the first occurrence of the character c 
	(an unsigned char) in the first n bytes of the string pointed to, 
	by the argument str.

	Return Value
	This function returns a pointer to the matching byte or NULL 
	if the character does not occur in the given memory area.
*/

void	*ft_memchr(const void *str, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)str == (unsigned char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
