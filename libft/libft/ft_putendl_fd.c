/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:43:51 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/29 11:44:57 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
    Description:
    Outputs the string ’s’ to the given file descriptor followed by a newline.
*/

/*
void ft_putendl_fd(char *s, int fd)
{
    if (!s)
        return;
    write(fd, s, ft_strlen(s));
    write(fd, '\n', 1);
}
*/

//solution 2
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
