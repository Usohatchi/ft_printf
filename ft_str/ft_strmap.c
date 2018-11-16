/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:59:53 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/15 15:06:42 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	char	*ret;
	int		i;

	if (!str || !f)
		return (NULL);
	ret = ft_strnew(ft_strlen(str));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = (*f)(str[i]);
		i++;
	}
	return (ret);
}
