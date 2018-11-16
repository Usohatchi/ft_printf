/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:33:01 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/27 18:55:53 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void		*ret;
	size_t		i;

	ret = malloc(size);
	if (!ret)
		return (ret);
	i = 0;
	while (i < size)
	{
		((char*)ret)[i] = 0;
		i++;
	}
	return (ret);
}
