/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:58:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/25 13:11:31 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
	Description:
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of	maximum size ’len’.

	Parameters:
	s:  The string from which to create the substring.
	start:  The start index of the substring in the	string ’s’.
	len:  The maximum length of the substring.

	Return value:
	The substring. NULL if the allocation fail.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	end;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) > start + len)
		end = start + len;
	else
		end = ft_strlen(s);
	substr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
