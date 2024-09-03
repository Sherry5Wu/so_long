/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:17:54 by jingwu            #+#    #+#             */
/*   Updated: 2024/05/13 14:46:39 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

char	*get_next_line(int fd);
char	*ft_strchr_2(const char *str, int c);
char	*ft_strjoin_2(char *dest, char *src);
size_t	ft_strlen_2(const char *str);
char	*ft_substr_2(char const *s, unsigned int start, size_t len);
void	*free_mem(char **str);

#endif
