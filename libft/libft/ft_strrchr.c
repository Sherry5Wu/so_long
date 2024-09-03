/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:46:07 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/30 10:46:24 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
	DESCRIPTION :
	The function ft_strrchr finds the last occurrence of character c in
	string str.

	RETURN VALUE :
	A pointer to the last occurrence of c in str.
	NULL if c is not found.
*/

static int	str_length(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = str_length(str) + 1;
	while (len-- > 0)
	{
		if (str[len] == (char)c)
			return ((char *)str + len);
	}
	return (NULL);
}
