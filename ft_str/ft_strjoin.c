/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:33:11 by eito-fis          #+#    #+#             */
/*   Updated: 2018/11/15 14:28:45 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*ret;
	int		i;

	if (!str1 || !str2)
		return (NULL);
	ret = ft_strnew(ft_strlen(str1) + ft_strlen(str2));
	if (!ret)
		return (NULL);
	i = 0;
	while (*str1)
	{
		ret[i] = *str1;
		i++;
		str1++;
	}
	while (*str2)
	{
		ret[i] = *str2;
		i++;
		str2++;
	}
	return (ret);
}
