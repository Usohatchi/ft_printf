/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:29:38 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/17 21:12:29 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t l)
{
	size_t	i;

	if ((uintptr_t)dst == (uintptr_t)src)
		return (dst);
	if ((uintptr_t)dst > (uintptr_t)src)
	{
		i = l;
		while (i > 0)
		{
			((char*)dst)[i - 1] = ((char*)src)[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < l)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	return (dst);
}
