/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:25:36 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/29 10:17:12 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	Description:
	Allocates (with malloc(3)) and returns a copy of ’s1’ with the
	characters specified in ’set’ removed from the beginning and
	the end of the string.

	Parameters:
	s1:  The string to be trimmed.
	set:  The reference set of characters to trim.

	Return value:
	The trimmed string.
	NULL if the allocation fails.
*/

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*trim_str;
// 	size_t	start;
// 	size_t	end;

// 	if (!s1 || !set)
// 		return (NULL);
// 	start = 0;
// 	end = ft_strlen(s1);
// 	while (s1[start] && ft_strchr(set, s1[start]))
// 		start++;
// 	while (end > start && ft_strchr(set, s1[end]))
// 		end--;
// 	trim_str = ft_substr(s1, start, (end - start + 1));
// 	if (!trim_str)
// 		return (NULL);
// 	return (trim_str);
// }
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*trim_s;

	if (!s1 || !set)
		return ((char *)s1);
	i = 0;
	while (s1[i] != 0 && ft_strchr(set, s1[i]) != NULL)
		i++;
	j = ft_strlen(s1) - 1;
	while (j > 0 && ft_strchr(set, s1[j]) != NULL)
		j--;
	trim_s = ft_substr(s1, i, (j - i + 1));
	return (trim_s);
}
