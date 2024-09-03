/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:55:50 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/27 12:29:03 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			count += 1;
		s++;
	}
	return (count);
}

static void	*free_memory(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split_s;
	size_t	words;
	size_t	i;
	size_t	j;

	words = count_words(s, c);
	split_s = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split_s)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		j = 0;
		while (*s == c)
			s++;
		while (*(s + j) && *(s + j) != c)
			j++;
		split_s[i] = ft_substr(s, 0, j);
		if (!split_s[i])
			return (free_memory(split_s));
		i++;
		s = s + j;
	}
	split_s[words] = 0;
	return (split_s);
}
