/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:52:11 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/29 13:56:23 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
// solution 1:
t_list  *ft_lstlast(t_list *lst);
{
    if (!lst)
        return (NULL);
    while (lst)
    {
        if (!lst->next)
            return (lst);
        lst = lst->next;
    }
}
*/
// solution 2

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
