/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:21:33 by jingwu            #+#    #+#             */
/*   Updated: 2024/04/29 14:23:14 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
    Description:
    Takes as a parameter a node and frees the memory of the nod’s
    content using the function ’del’ given as a parameter and free
    the node. The memory of ’next’ must not be freed.

    Parameters:
    lst: The node to free.
    del: The address of the function used to delete the content.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst->content)
		del(lst->content);
	free(lst);
}
