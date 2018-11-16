/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:49:38 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/17 19:18:35 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char*)src;
	while (n > 0)
	{
		((char*)dst)[i] = *tmp;
		if (((unsigned char)*tmp) == ((unsigned char)c))
			return ((void*)(dst + i + 1));
		i++;
		tmp++;
		n--;
	}
	return (NULL);
}
