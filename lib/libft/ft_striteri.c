/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:04:19 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/29 10:06:08 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Description:
    Applies the function ’f’ on each character of the string passed as argument, 
    passing its index as first argument.  Each character is passed by address 
    to ’f’ to be modified if necessary.

    Parameters:
    s:  The string on which to iterate.
    f:  The function to apply to each character.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
