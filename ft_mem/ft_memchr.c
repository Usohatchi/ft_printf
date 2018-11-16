/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:46:29 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/17 16:18:14 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*tmp;

	tmp = (char*)str;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)*tmp == (unsigned char)c)
			return ((void*)tmp);
		tmp++;
		i++;
	}
	return (NULL);
}
