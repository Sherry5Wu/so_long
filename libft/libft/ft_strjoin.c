/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:28:41 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/24 11:24:59 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
	Description:
	Allocates (with malloc(3)) and returns a new string, which is the 
	result of the concatenation of ’s1’ and ’s2’.

	Parameters:
	s1:  The prefix string.
	s2:  The suffix string.

	Return value:
	The new string.NULL if the allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, (s1_len + 1));
	ft_strlcat(newstr, s2, (s1_len + s2_len + 1));
	return (newstr);
}
