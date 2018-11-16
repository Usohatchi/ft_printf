/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:42:15 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/31 19:48:29 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	ret = (char*)malloc(size + 1);
	if (!ret)
		return (ret);
	i = 0;
	while (i <= size + 1)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
