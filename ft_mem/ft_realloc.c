/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:05:53 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/15 16:03:56 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t cur, size_t l)
{
	char	*tmp;

	if (ptr)
	{
		tmp = malloc(cur);
		if (!tmp)
			return (NULL);
		ft_memcpy(tmp, ptr, cur);
		free(ptr);
		ptr = malloc(l);
		if (!ptr)
		{
			free(tmp);
			return (NULL);
		}
		ft_memcpy(ptr, tmp, cur);
		free(tmp);
	}
	else
		ptr = malloc(l);
	return (ptr);
}
