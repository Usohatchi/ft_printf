/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:07:56 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/15 15:11:01 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (!str || !f)
		return (NULL);
	ret = ft_strnew(ft_strlen(str));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = (*f)(i, str[i]);
		i++;
	}
	return (ret);
}
