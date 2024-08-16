/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:18:27 by jingwu            #+#    #+#             */
/*   Updated: 2024/05/14 12:59:08 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*free_mem(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	ft_strlen_2(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_2(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strjoin_2(char *dest, char *src)
{
	char	*nstr;
	size_t	i;
	size_t	j;

	if (!dest && !src)
		return (NULL);
	nstr = malloc(sizeof(char) * (ft_strlen_2(dest) + ft_strlen_2(src) + 1));
	if (!nstr)
		return (free_mem(&dest));
	i = 0;
	j = 0;
	if (dest)
	{
		while (dest[i])
		{
			nstr[i] = dest[i];
			i++;
		}
	}
	while (src[j])
		nstr[i++] = src[j++];
	nstr[i] = '\0';
	free(dest);
	return (nstr);
}

char	*ft_substr_2(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen_2(s))
	{
		substr = (char *)malloc(sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > ft_strlen_2(s) - start)
		len = ft_strlen_2(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
