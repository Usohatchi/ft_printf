/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:26:00 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/01 16:48:52 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t l)
{
	char	*ret;
	size_t	i;

	ret = ft_strnew(l);
	if (!str || !ret)
		return (NULL);
	i = 0;
	while (i < l)
	{
		ret[i] = str[start];
		start++;
		i++;
	}
	return (ret);
}
