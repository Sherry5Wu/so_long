/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 08:44:00 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/29 08:50:20 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
	Description:
	Applies the function ’f’ to each character of the string ’s’, and passing its
	index as first argument to create a new string (with malloc(3)) resulting
	from successive applications of ’f’.

	Parameters:
	s:  The string on which to iterate.
	f:  The function to apply to each character.

	Return value:
	The string created from the successive applications of ’f’.
	Returns NULL if the allocation fails.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	i;
	size_t			len;

	if (!s)
		return (ft_strdup(""));
	if (!f)
		return (ft_strdup(s));
	len = ft_strlen(s);
	new_s = ft_strdup(s);
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_s[i] = (*f)(i, s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
