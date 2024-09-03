/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:35:40 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/24 08:06:36 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
	The function ft_strdup() is used to duplicate a string. 
	It returns a pointer to null-terminated byte string.
*/

char	*ft_strdup(const char *str)
{
	char	*newstr;
	size_t	i;

	newstr = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
