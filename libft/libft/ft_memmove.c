/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:03:47 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/30 09:27:09 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
	Description:
	The function copies n characters from str2 to str1, but for overlapping
    memory blocks, memmove() is a safer approach than memcpy().

	Parameters:
	str1 − This is a pointer to the destination array where the content is 
			to be copied, type-casted to a pointer of type void*.
    str2 − This is a pointer to the source of data to be copied, 
			type-casted to a pointer of type void*.
     n − This is the number of bytes to be copied.

	 Return Value:
	 This function returns a pointer to the destination, which is str1.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (dest > src)
	{
		while (n-- > 0)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	}
	else
	{
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dest);
}
